/* strmanip.c --- string handling function library
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

#include "strmanip.h"

#define MAX_OUTPUT_SIZE 100

const char *strip_delims(char *input_string)
{
  // TODO: Impliment this.
  const char *stripped_string;
  stripped_string = "2552552550";
  return stripped_string;
}

const char *add_delims(char *input_string)
{
  // TODO: Impliment this.
  const char *delimited_string;
  delimited_string = "255.255.255.0";
  return delimited_string;
}

const char *compile_netstat_output()
{
  // TODO: Implimemt this.
  char *placeholder_str = (char *) malloc(MAX_OUTPUT_SIZE);
  placeholder_str = "just a placeholder string\n";
  return placeholder_str;
}
