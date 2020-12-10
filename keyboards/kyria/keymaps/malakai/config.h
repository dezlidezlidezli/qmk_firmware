/* Copyright 2019 Thomas Baart <thomas@splitkb.com>
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 2 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */

#pragma once
// This enables use of the OLED, sets the resolution to 128x64 and then sets the timeout to 180000 milliseconds, or three minutes.
#ifdef OLED_DRIVER_ENABLE
  #define OLED_DISPLAY_128X64
  #define OLED_TIMEOUT 30000
#endif

#define TAPPING_TOGGLE 3
#define ENCODER_RESOLUTION 2
#define ENCODER_DIRECTION_FLIP

// If you are using an Elite C rev3 on the slave side, uncomment the lines below:
// #define SPLIT_USB_DETECT
// #define NO_USB_STARTUP_CHECK
