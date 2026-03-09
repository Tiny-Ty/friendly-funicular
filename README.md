# RP2040 Zero Numpad — QMK + VIAL Firmware

QMK firmware for a Waveshare RP2040 Zero connected to an 18-key numpad membrane matrix (6×6), with [VIAL](https://get.vial.today/) support for real-time key remapping.

## Hardware

| Signal   | GPIO Pin |
|----------|----------|
| Row 0    | GP0      |
| Row 1    | GP1      |
| Row 2    | GP2      |
| Row 3    | GP3      |
| Row 4    | GP4      |
| Row 5    | GP5      |
| Col 0    | GP6      |
| Col 1    | GP7      |
| Col 2    | GP8      |
| Col 3    | GP9      |
| Col 4    | GP10     |
| Col 5    | GP11     |

Matrix scanning direction: **COL2ROW**

## Default Keymap

The default keymap is a standard numpad layout:

```
┌────┬────┬────┬────┐
│NMLK│ /  │ *  │ -  │
├────┼────┼────┼────┤
│ 7  │ 8  │ 9  │ +  │
├────┼────┼────┼────┤
│ 4  │ 5  │ 6  │BCK │
├────┼────┼────┼────┤
│ 1  │ 2  │ 3  │ENT │
├────┴────┼────┤    │
│    0    │ .  │    │
└─────────┴────┴────┘
```

With VIAL, all keys can be remapped live without reflashing.

## Building the Firmware

### Prerequisites

- [QMK CLI](https://docs.qmk.fm/#/newbs_getting_started) installed
- For VIAL support, use the [vial-qmk](https://github.com/vial-kb/vial-qmk) fork

### Build Steps (VIAL)

```bash
# 1. Clone vial-qmk (includes VIAL support on top of QMK)
git clone https://github.com/vial-kb/vial-qmk.git
cd vial-qmk
git submodule update --init --recursive

# 2. Copy the keyboard definition into the vial-qmk tree
cp -r /path/to/this-repo/keyboards/rp2040_zero_keypad keyboards/rp2040_zero_keypad

# 3. Build the VIAL firmware
make rp2040_zero_keypad:vial

# The output UF2 file will be at:
#   .build/rp2040_zero_keypad_vial.uf2
```

### Build Steps (VIA)

```bash
# Using standard QMK (mainline)
qmk compile -kb rp2040_zero_keypad -km via
```

### Build Steps (Default — no VIAL)

```bash
# Using standard QMK
qmk compile -kb rp2040_zero_keypad -km default
```

## Flashing

1. Hold the **BOOT** button on the RP2040 Zero and plug in USB (or double-tap reset).
2. The board will appear as a USB mass-storage drive named **RPI-RP2**.
3. Copy the `.uf2` file onto the drive. The board will reboot automatically.

```bash
# Or flash with QMK CLI (picotool):
qmk flash -kb rp2040_zero_keypad -km vial
```

## Using VIA

1. Flash the VIA firmware (see Build Steps (VIA) above).
2. Open the [VIA app](https://usevia.app/) in your browser.
3. Go to the **Design** tab and enable "Show Design tab" in Settings if needed.
4. Click **Load** and select `keyboards/rp2040_zero_keypad/keymaps/via/via_layout.json` from this repository.
5. Go to the **Configure** tab, connect the keypad, and remap keys across all 4 layers.

## Using VIAL

1. Flash the VIAL firmware (see above).
2. Open [VIAL](https://get.vial.today/) (web or desktop app).
3. Connect the keypad — VIAL will detect it automatically.
4. Remap keys, create macros, and configure layers in real time.

**VIAL Unlock:** Hold the Num Lock (top-left) and . (bottom row) keys simultaneously to unlock VIAL security.

## File Structure

```
keyboards/rp2040_zero_keypad/
├── config.h                    # Debounce configuration
├── keyboard.json               # QMK keyboard metadata & layout
├── rules.mk                   # MCU and bootloader settings
└── keymaps/
    ├── default/
    │   └── keymap.c            # Default numpad keymap (1 layer)
    ├── via/
    │   ├── keymap.c            # VIA keymap (4 layers)
    │   ├── rules.mk            # Enables VIA
    │   └── via_layout.json     # VIA draft definition (load in Design tab)
    └── vial/
        ├── config.h            # VIAL UID and unlock combo
        ├── keymap.c            # VIAL keymap (4 layers)
        ├── rules.mk            # Enables VIA + VIAL
        └── vial.json           # VIAL layout definition
```
