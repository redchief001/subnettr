/* condtest.h - headers for program wide conditionals in subnettr
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <https://www.gnu.org/licenses.
 *
 * Copyright (c) 2020 James Nicholson
 */

#ifndef _CONDTEST_H_
#define _CONDTEST_H_

#include <stdbool.h>
#include "netstructs.h"


/* Change the value of the IP version flag in the instance struct
 */
void set_v_flag(bool);


/*
 * Change the value of the CIDR flag in the instance structure
 */
void set_cidr_flag(bool);


#endif
