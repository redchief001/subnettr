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

#include "netstructs.h"

#define NSTACK_MAXSIZE 8

int nstack[8];
int nstack_top = -1;
int IP_RAW_MAXSIZE = 4;


/******************************
 * Public functions for flags *
 ******************************/

/* Structure to hold the flags for the program */
struct inst_cond_data{
  bool v6;
  bool cidr;
};
struct inst_cond_data inst_cond_data;

bool get_v_flag()
{
  bool v_flag = inst_cond_data.v6;
  return v_flag;
}

bool get_cidr_flag()
{
  bool cidr_flag = inst_cond_data.cidr;
  return cidr_flag;
}

void set_v_flag(bool v_flag_value)
{
  inst_cond_data.v6 = v_flag_value;
}

void set_cidr_flag(bool cidr_flag_value)
{
  inst_cond_data.cidr = cidr_flag_value;
}


/**************************************
 * Public functions for other structs *
 **************************************/

/* Strings to store */
struct str_octets
{
  char *first_octet;
  char *second_octet;
  char *third_octet;
  char *fourth_octet;
};
struct str_octets str_octets;

/* Linked list that can hold unsigned long integers */
struct int_octets
{
  int first_octet;
  int second_octet;
  int third_octet;
  int fourth_octet;
};
struct int_octets int_octets;

void str_insert_octet(int order, char *octet)
{
  if(order == 1){
    str_octets.first_octet = octet;
  } else if(order == 2){
    str_octets.second_octet = octet;
  } else if(order == 3){
    str_octets.third_octet = octet;
  } else{
    str_octets.fourth_octet = octet;
  }
}

char *str_get_octet(int order)
{
  char *ret_val;
  if(order == 1){
    ret_val = str_octets.first_octet;
  } else if(order == 2){
    ret_val = str_octets.second_octet;
  } else if(order == 3){
    ret_val = str_octets.third_octet;
  } else {
    ret_val = str_octets.fourth_octet;
  }

  return ret_val;
}

void int_insert_octet(int order, int octet)
{
  if(order == 1){
    int_octets.first_octet = octet;
  } else if(order == 2){
    int_octets.second_octet = octet;
  } else if(order == 3){
    int_octets.third_octet = octet;
  } else{
    int_octets.fourth_octet = octet;
  }
}

int int_get_octet(int order)
{
  long ret_val;
  if(order == 1){
    ret_val = int_octets.first_octet;
  } else if(order == 2){
    ret_val = int_octets.second_octet;
  } else if(order == 3){
    ret_val = int_octets.third_octet;
  } else {
    ret_val = int_octets.fourth_octet;
  }

  return ret_val;
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
