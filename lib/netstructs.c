/* netstructs.c --- A simple stack for network calculations
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

#include <stdbool.h>
#include <stdio.h>

#include "netstructs.h"

#define NSTACK_MAXSIZE 8

int nstack[8];
int nstack_top = -1;
int IP_RAW_MAXSIZE = 4;


/****************
 * Private data *
 ****************/

/* Structure to hold the flags for the program */
struct inst_cond_data{
  bool v6;
  bool cidr;
};
struct inst_cond_data inst_cond_data;

/* Linked list that can hold strings */
struct str_list
{
  char *key;
  char *list_item;
  struct str_list *next;
};
struct str_list *str_head = NULL;
struct str_list *str_current = NULL;

/* Linked list that can hold unsigned long integers */
struct ul_list
{
  char *key;
  unsigned long list_item;
  struct ul_list *next;
};
struct ul_list *ul_head = NULL;
struct uL_list *ul_current = NULL;

/****************************************
 * Public functions for data structures *
 ****************************************/

void insert_link()
{
  /* TODO: impliment this function */
}

void str_list_add()
{
  /* TODO: impliment this function */
}

bool get_v_flag(void)
{
  /* TODO: impliment this function */
  return true;
}

bool get_cidr_flag(void)
{
  /* TODO: impliment this function */
  return true;
}

void set_v_flag(bool v_flag_value)
{
  /* TODO: impliment this function */
}

void set_cidr_flag(bool cidr_flag)
{
  /* TODO: impliment this function */
}


/******************************
 * Public functions for stack *
 ******************************/
int nstack_isempty() {

  if(nstack_top == -1)
      return 1;
   else
      return 0;
}

int nstack_isfull() {

   if(nstack_top == NSTACK_MAXSIZE)
      return 1;
   else
      return 0;
}

int nstack_peek() {
   return nstack[nstack_top];
}

int nstack_pop() {
   int data;

   if(!nstack_isempty()) {
      data = nstack[nstack_top];
      nstack_top = nstack_top - 1;
      return data;
   } else {
      return -1;
   }
}

int nstack_push(int data) {

   if(!nstack_isfull()) {
      nstack_top = nstack_top + 1;
      nstack[nstack_top] = data;
      return 1;
   } else {
      return -1;
   }
}
