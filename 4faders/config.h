// Copyright 2024 Vermoot (@Vermoot)
// SPDX-License-Identifier: GPL-2.0-or-later

#pragma once

/*
 * Feature disable options
 *  These options are also useful to firmware size reduction.
 */

/* disable debug print */
//#define NO_DEBUG

/* disable print */
//#define NO_PRINT

/* disable action features */
//#define NO_ACTION_LAYER
//#define NO_ACTION_TAPPING
//#define NO_ACTION_ONESHOT

#define ENCODERS_PAD_A { GP20, GP16, GP17, GP18, GP23, GP22, GP21, GP19 }
#define ENCODERS_PAD_B { GP16, GP17, GP18, GP19, GP20, GP23, GP22, GP21 }
#define ENCODER_DEFAULT_POS 0x3

#define MIDI_ADVANCED
