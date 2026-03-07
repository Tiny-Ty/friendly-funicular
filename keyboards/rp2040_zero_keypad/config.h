// Copyright 2024 QMK
// SPDX-License-Identifier: GPL-2.0-or-later

#pragma once

/* Matrix configuration */
#define MATRIX_ROWS 4
#define MATRIX_COLS 4

#define MATRIX_ROW_PINS { GP4, GP5, GP6, GP7 }
#define MATRIX_COL_PINS { GP3, GP2, GP1, GP0 }

#define DIODE_DIRECTION COL2ROW

/* Debounce configuration */
#define DEBOUNCE 5
