/*
  Plastic Logic EPD project on MSP430

  Copyright (C) 2013, 2014 Plastic Logic Limited

  This program is free software: you can redistribute it and/or modify
  it under the terms of the GNU General Public License as published by
  the Free Software Foundation, either version 3 of the License, or
  (at your option) any later version.

  This program is distributed in the hope that it will be useful,
  but WITHOUT ANY WARRANTY; without even the implied warranty of
  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
  GNU General Public License for more details.

  You should have received a copy of the GNU General Public License
  along with this program.  If not, see <http://www.gnu.org/licenses/>.
*/
/*
 * pl/platform.h
 *
 * Authors:
 *   Nick Terry <nick.terry@plasticlogic.com>
 *   Guillaume Tucker <guillaume.tucker@plasticlogic.com>
 *
 */

#ifndef PL_PLATFORM_H
#define PL_PLATFORM_H 1

#include <pl/gpio.h>
#include <pl/i2c.h>
#include <pl/epdpsu.h>
#include "i2c-eeprom.h"
#include "config.h"

/* Common platform data */

struct pl_system_gpio {
	unsigned sel[4];
	unsigned sw[5];
	unsigned led[4];
	unsigned assert_led;
};

struct platform {
	struct pl_gpio gpio;
	struct pl_i2c host_i2c;
	const struct pl_system_gpio *sys_gpio;
	struct pl_epdpsu psu;
};

#endif /* PL_PLATFORM_H */
