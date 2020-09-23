/* subnettr - a simple network calculator tool.
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

#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

#include "../lib/convlib.h"
#include "../lib/netstructs.h"
#include "../lib/strmanip.h"

int main(int argc, char *argv[])
{
  // Set up the flag for IPv6 (default is false)
  bool vflag = false;
  bool cidr = false;

  // Parse the command line
  int opt;
  while ((opt = getopt(argc, argv, "V")) != -1) {
    switch (opt) {
    case 'V': vflag = true; break;
    case 'c': cidr = true; break;
    default:
      fprintf(stderr,
	      "Usage: %s [-V, -c] [IP addr] [Netmask]\n", argv[0]);
      exit(EXIT_FAILURE);
    }
  }


  return 0;
}
