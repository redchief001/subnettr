/* netstructs.h --- The header file for netstructs.c
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

#ifndef _NETSTRUCTS_H_
#define _NETSTRUCTS_H_

#include <stdbool.h>
#include <stdlib.h>

/***************************
 * Functions for flag data *
 ***************************/

/* Return the version flag
 */
bool get_v_flag();

/* Return the CIDR flag
 */
bool get_cidr_flag();

/* Set the version flag
 */
void set_v_flag(bool);

/* Set the CIDR flag
 */
void set_cidr_flag(bool);

/*************************************
 * Functions for struct manipulation *
 *************************************/

/* Insert an entry into the string struct
 */
void str_insert_octet(int, char *);

/* Return one of the stored string values
 */
char *str_get_octet(int);

/* Insert an entry into the ul struct
 */
void int_insert_octet(int, int);

/* Return one of the stored ul values
 */
int int_get_octet(int);


/************************************
 * Functions for stack manipulation *
 ************************************/

/* Check the stack to see if it's empty. Return 1 if empty
 */
int nstack_isempty();

/* Check the stack to see if it it's full. Return 1 if full
 */
int nstack_isfull();

/* Check the value of the top element in the stack
 */
int nstack_peek();

/* Return the element at the top of the stack or -1 if empty
 */
int nstack_pop();

/* Push an element on to the top of the stack or return -1 on error
 */
int nstack_push(int);

#endif
