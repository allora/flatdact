/*
Copyright 2012 Jun Wako <wakojun@gmail.com>
Copyright 2015 Jack Humbert

This program is free software: you can redistribute it and/or modify
it under the terms of the GNU General Public License as published by
the Free Software Foundation, either version 2 of the License, or
(at your option) any later version.

This program is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU General Public License for more details.

You should have received a copy of the GNU General Public License
along with this program.  If not, see <http://www.gnu.org/licenses/>.
*/

#pragma once

#include "config_common.h"

/* Set 0 if debouncing isn't needed */
#define DEBOUNCE 5

/* Serial configuration for split keyboard */
//#define SERIAL_PIO_USE_PIO0
#define SERIAL_USART_FULL_DUPLEX    // Enable full duplex operation mode.
#define SERIAL_USART_TX_PIN GP0     // USART TX pin
#define SERIAL_USART_RX_PIN GP1     // USART RX pin

#define SPLIT_POINTING_ENABLE
#define POINTING_DEVICE_RIGHT

/* Double tap the side button to enter bootloader */
#define RP2040_BOOTLOADER_DOUBLE_TAP_RESET
#define RP2040_BOOTLOADER_DOUBLE_TAP_RESET_TIMEOUT 500U

/* Encoders */
#define ENCODERS_PAD_A { GP12 }
#define ENCODERS_PAD_B { GP16 }

#define ENCODERS_PAD_A_RIGHT { GP12 }
#define ENCODERS_PAD_B_RIGHT { GP16 }

#define ENCODER_RESOLUTIONS { 2 }

/* SPI */
#define SPI_DRIVER SPID0
#define SPI_SCK_PIN GP6
#define SPI_MISO_PIN GP20
#define SPI_MOSI_PIN GP7

#define PMW33XX_CS_PIN GP21

/* key matrix size */
// Rows are doubled-up
#define MATRIX_ROWS 8
#define MATRIX_COLS 5

// wiring of each half
#define MATRIX_ROW_PINS { GP2, GP3, GP4, GP9 }
#define MATRIX_COL_PINS { GP29, GP28, GP27, GP26, GP22 }

#define DIODE_DIRECTION COL2ROW

/* define if matrix has ghost */
//#define MATRIX_HAS_GHOST

// WS2812 RGB LED strip input and number of LEDs
//#define RGB_DI_PIN D3
//#define RGBLED_NUM 12

/* number of backlight levels */
// #define BACKLIGHT_LEVELS 3
