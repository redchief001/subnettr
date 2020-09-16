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

#include <stdio.h>
#include "netstructs.h"

int NSTACK_MAXSIZE = 8;
int nstack[8];
int nstack_top = -1;
int IP_RAW_MAXSIZE = 4;

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
