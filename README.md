# RollJam Research – Flipper Zero App (Educational)

## ⚠️ Legal, Ethical & Liability Disclaimer

This project is provided **for educational and research purposes only**.

The author(s) of this project:
- Do **NOT** encourage illegal activity
- Do **NOT** provide any functional attack implementation
- Do **NOT** endorse misuse of radio-frequency equipment or security research

🚫 **The author(s) assume NO responsibility or liability for any misuse, damage, legal consequences, or unlawful activity resulting from the use, modification, or interpretation of this code or its concepts.**

Any use of the information, ideas, or software contained in this repository is done **entirely at the user's own risk**.

By using, modifying, or distributing this project, you agree that:
- You are solely responsible for ensuring compliance with all applicable local, national, and international laws
- You will not use this project to attack, interfere with, or bypass real-world systems without explicit authorization

If you do not agree with these terms, **do not use this project**.

❗ **Using radio equipment to interfere with or bypass security systems without authorization is illegal in many jurisdictions.**  
The authors and contributors of this project take **no responsibility for misuse** of the concepts described herein.

---

## 🎯 Purpose of This Project

The goal of this application is to:

- Provide a **research skeleton** that models the *logical flow* of a RollJam / resynchronization attack
- Enable **defensive research** into:
  - Detection of RF-based attacks
  - Receiver-side hardening strategies
  - Timing-based anomaly analysis
- Serve as a **safe framework** for:
  - Simulations
  - Threat modeling
  - Countermeasure development

This project is intended for:
- Security researchers
- Embedded systems engineers
- Automotive / access-control designers
- Academic study and lab environments

---

## 🧠 What Is RollJam (High-Level)

A RollJam (resynchronization) attack is a **class of RF attacks** that exploits weaknesses in rolling-code based remote control systems by:

1. Preventing a receiver from accepting a valid code (e.g., via interference)
2. Capturing valid transmissions
3. Replaying previously captured codes at a later time

⚠️ This repository **DOES NOT perform this attack**.  
It only models the **state transitions and timing logic** for research purposes.

---

## 🐬 Application Overview

**Platform:** Flipper Zero  
**Build System:** uFBT  
**Language:** C  
**Firmware:** Official / Unleashed / RogueMaster (no firmware modification required)

### App Flow (State Machine)

```
 └─▶ PHASE 1 Jamming
       └─▶ Signal A "Captured"
             └─▶ PHASE 2 Jamming
                   └─▶ PHASE 3 Replay
                         └─▶ DONE
```
Each phase is represented visually on the Flipper Zero display, matching real-world attack research flows without executing RF actions.

## 📺 User Interface
**The UI displays:**

Frequency

Modulation

**Attack phases:**

Phase 1: Jamming

Phase 2: Jamming

Phase 3: Replay

**Status messages such as:**

“Signal A Captured!”

“Waiting for keyfob…”

## 🔒 RF Safety Design
All RF-related functionality is isolated in a dedicated stub layer:

```
rolljam_rf_stub.h
```

## 🛡️ Defensive Research Applications
This framework can be safely extended to build:

RollJam detection systems

Timing anomaly analyzers

RSSI / CRC pattern detectors (RX-only)

Receiver-side mitigation strategies

Rolling-code simulators

Academic demonstrations and lectures

## 📚 Recommended Research Topics
If you are studying this topic defensively, consider:

Non-deterministic acceptance windows

Challenge–response protocols

RF fingerprinting

Replay detection heuristics

Rolling code desynchronization limits

## 🧪 Intended Environment
Laboratory settings

Simulated receivers

Dummy transmitters

Shielded / non-radiating environments

Academic or professional research contexts

## 📜 License
This project is provided for educational and research purposes only.

You are responsible for complying with all local laws and regulations regarding radio equipment and security research.

## 🤝 Final Note
Understanding attacks is essential to building secure systems.
This project exists to help engineers and researchers defend, not to exploit.

Stay ethical. Stay legal. 🔐
