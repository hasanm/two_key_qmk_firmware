/* Copyright 2019
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

#include "config_common.h"

#define MATRIX_COL_PINS { D1}
#define MATRIX_ROW_PINS { D6}
#define UNUSED_PINS

#undef DIODE_DIRECTION
#define DIODE_DIRECTION ROW2COL

/* #define BACKLIGHT_PIN B6
   #define BACKLIGHT_BREATHING */

#undef DEBOUNCE
#define DEBOUNCE 10


/* 


#define RGB_DI_PIN F6
#define RGB_CI_PIN B1

#define ADC_PIN F6

*/
