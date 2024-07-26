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

#define ENCODERS_PAD_A { GP11, GP10, GP9, GP8, GP13, GP14, GP15, GP12 }
#define ENCODERS_PAD_B { GP10, GP9, GP8, GP12, GP11, GP13, GP14, GP15 }
#define ENCODER_DEFAULT_POS 0x3

#define ADC_RESOLUTION ADC_CFGR1_RES_12BIT

#define MIDI_ADVANCED
