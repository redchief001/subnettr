/* convlib.c --- Type conversion function library
 *
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
 *
 */

#include <stdio.h>
#include <stdlib.h>
#include <inttypes.h>
#include <string.h>

#include "convlib.h"
#include "netstructs.h"

void conv_str_to_int(int order)
{
  int int_output = strtoumax(str_get_octet(order), NULL, 10);
  int_insert_octet(order, int_output);
}

void conv_int_to_str(int order)
{
  int input_int = int_get_octet(order);
  size_t str_size = sizeof(char)*4;
  char output_str[str_size];
  sprintf(output_str, "%d", input_int);
  str_insert_octet(order, output_str);
}
