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

#include <stdlib.h>
#include "convlib.h"

unsigned long conv_str_to_ulong(char *char_input)
{
  // TODO: Stub. Impliment this function
  return 101;
}

unsigned long octets_to_bin(unsigned long n)
/* This function converts the octet passed in to binary format and
 * returns the result to the caller.
 */
{
  int bin_octet[8];
  int rev_bin_octet[8];
  int i = 0;
  int k =0;
  while(n > 0){
    bin_octet[i] = n%2;
    n = n/2;
    i++;
  }
  for(int j = i -1; j >= 0; j--){
    rev_bin_octet[k] = bin_octet[j];
  }
  return *rev_bin_octet;
}
