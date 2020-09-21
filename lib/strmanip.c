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

#include "netstructs.h"
#include "strmanip.h"

#define MAX_OUTPUT_SIZE 100

char *strip_delims(char *input_string)
{
  if(! get_v_flag()){ /* for IPv4 */
    size_t tok_size = 4;
    char *tok1 = (char *) malloc(tok_size);
    char *tok2 = (char *) malloc(tok_size);
    char *tok3 = (char *) malloc(tok_size);
    char *tok4 = (char *) malloc(tok_size);
    const char *delim_char = ".";
    tok1 = strtok(input_string, delim_char);
    str_insert_octet(1, tok1);
    tok2 = strtok(NULL, delim_char);
    str_insert_octet(2, tok2);
    tok3 = strtok(NULL, delim_char);
    str_insert_octet(3, tok3);
    tok4 = strtok(NULL, delim_char);
    str_insert_octet(4, tok4);
  } else {
    char *ret_val;
    ret_val = "No IPv6 yet!";
    return ret_val;
  }
  size_t ret_size = 13;
  char *ret_val = (char *) malloc(ret_size);
  strncpy(ret_val, str_get_octet(1), 13);
  strncat(ret_val, str_get_octet(2), 13);
  strncat(ret_val, str_get_octet(3), 13);
  strncat(ret_val, str_get_octet(4), 13);
  return ret_val;
}


char * add_delims(char *input_string)
{
  // TODO: Impliment this.
  char *delimited_string = "255.255.255.0";

  return delimited_string;
}


char *compile_netstat_output()
{
  // TODO: Implimemt this.
  char *placeholder_str = (char *) malloc(MAX_OUTPUT_SIZE);
  placeholder_str = "just a placeholder string";
  return placeholder_str;
}
