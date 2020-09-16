/* strmanip.h --- headers for strmanip.c
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

#ifndef _STRMANIP_H_
#define _STRMANIP_H_

#include <string.h>
#include <stdlib.h>

/*
 * Define a constant that will hold the delimitors
 */
#define IPV6_DELIM ":"
#define IPV$_DELIM "."


/*
 * Strip the delimiters from the input and return the string without them
 */
const char *strip_delims(char*);


/*
 * Add the delimiters to the output and return the resulting string
 */
const char *add_delims(char*);


/*
 * Compile string output for STDOUT
 */
const char *compile_netstat_output();


#endif
