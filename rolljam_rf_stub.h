#pragma once
#include <stdbool.h>

static inline bool rf_external_cc1101_present(void) {
    // TODO (REAL): SPI handshake / chip ID read
    return true; // stub
}

static inline void rf_phase1_jamming_start(void) {
    /*
     * REAL ATTACK WOULD:
     * - Configure CC1101 TX
     * - Transmit noise or malformed frames
     * - Time TX/RX windows
     *
     * THIS STUB DOES NOTHING.
     */
}

static inline void rf_phase1_jamming_stop(void) {
    // Stub
}

static inline bool rf_capture_signal_A(void) {
    /*
     * REAL ATTACK WOULD:
     * - Switch to RX
     * - Capture valid rolling code
     *
     * STUB: always "captures"
     */
    return true;
}

static inline bool rf_capture_signal_B(void) {
    return true;
}

static inline void rf_replay_signal_A(void) {
    /*
     * REAL ATTACK WOULD:
     * - Replay captured signal with precise timing
     *
     * STUB: no RF output
     */
}
