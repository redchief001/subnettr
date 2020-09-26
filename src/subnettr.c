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

#include <arpa/inet.h>
#include <math.h>
#include <stdio.h>
#include <stdlib.h>

/***********************
 * Global declarations *
 ***********************/
#define MAX_BUFFER_SIZE 100

void use_messg(char *, char *);
int is_ip_valid(char *);
int is_mask_valid(char *);
int get_input_size(char *);
int get_number_of_slashes(char *);
int get_slash_position(char *);
void get_ip_string(char *, char *, int);
void get_netmask_string(char *, char *, int);
void print_ip_address(int *);
void binary_print(unsigned int);
void handle_input(char *);

unsigned int ip_number = 0;
unsigned int netmask_number = 0;
unsigned int netmask_bits;


/******************
 * Main function  *
 ******************/
int main(int argc, char *argv[])
{
  /* Variable declarations */
  unsigned int network_address = 0;
  unsigned int broadcast = 0;
  unsigned int host_min = 0;
  unsigned int host_max = 0;
  double number_of_hosts_bits = 0;
  char ip_string[15];
  char netmask_string[4];

  if(argc < 2)
    {
      use_messg(argv[0], "You must provide a valid ip/mask");
    }

  int inputSize = get_input_size(argv[1]);

  if (inputSize > 18)
    {
      use_messg(argv[0], "You must provide a valid IP/subnet mask");
    }

  int numberOfSlashes = get_number_of_slashes(argv[1]);

  if (numberOfSlashes != 1)
    {
      use_messg(argv[0], "You must provide a valid IP/subnet mask");
    }

  int slashPosition = get_slash_position(argv[1]);

  if (slashPosition == 0 || slashPosition == inputSize - 1)
    {
      use_messg(argv[0], "You must provde a valid IP/subnet mask");
    }

  get_ip_string(argv[1], ip_string, slashPosition);

  if (!is_ip_valid(ip_string))
    {
      use_messg(argv[0], "You must provde a valid IP/subnet mask");
    }

  get_netmask_string(argv[1], netmask_string, slashPosition);

  if (!is_mask_valid(netmask_string))
    {
      use_messg(argv[0], "You must provide a valid ip/mask");
    }

  printf("\n");
  printf("Entry: %s\n", argv[1]);
  printf("\n");

  /* transform the given input in numbers */
  handle_input(argv[1]);

  /*calculating values through the global variables */
  network_address = ip_number & netmask_number;
  broadcast = ~(netmask_number);
  broadcast = broadcast + network_address;
  host_min = network_address + 1;
  host_max = broadcast - 1;

  /* printing the results */
  printf("Network address: ");
  printf("\t");
  binary_print(network_address);
  printf("\t");
  print_ip_address(&network_address);
  printf("\n");

  printf("Netmask:          ");
  printf("\t");
  binary_print(netmask_number);
  printf("\t");
  print_ip_address(&netmask_number);
  printf("(%d bits)", netmask_bits);
  printf("\n");

  printf("Broadcast addr:   ");
  printf("\t");
  binary_print(broadcast);
  printf("\t");
  print_ip_address(&broadcast);
  printf("\n");

  printf("Min Host value:   ");
  printf("\t");
  binary_print(host_min);
  printf("\t");
  print_ip_address(&host_min);
  printf("\n");

  printf("Max Host value:   ");
  printf("\t");
  binary_print(host_max);
  printf("\t");
  print_ip_address(&host_max);
  printf("\n");
  printf("\n");

  number_of_hosts_bits = 32 - netmask_bits;

  printf
    ("The possible number of hosts on this network is %d.\n",
     (int)pow(2, number_of_hosts_bits) - 2);
  printf("\n");

  return 0;
}


/********************
 * Helper functions *
 ********************/
void use_messg(char *progname, char *error_messg)
{
  printf("\n%s\nUsage: %s [IP addr]/[CIDR netmask]\n\n",
	 error_messg, progname);
  exit(EXIT_FAILURE);
}

/* Validate the IP address passed in */
int is_ip_valid(char *ip_addr)
{
  struct sockaddr_in sockaddr;
  int result = inet_pton(AF_INET, ip_addr, &(sockaddr.sin_addr));
  return result != 0;
}

/* Validate the subnet mask passed in */
int is_mask_valid(char *netmask)
{
  char *end;
  int i = strtol(netmask, &end, 10);
  return i < 31;
}

int get_input_size(char *input)
{
  int size = 0;
  for(int i = 0; input[i] != 0; i++)
    {
      size++;
    }

  return size;
}

int get_number_of_slashes(char *input)
{
  int numberOfSlashes = 0;
  for(int i = 0; input[i] != 0; i++)
    {
      if (input[i] == '/') {
	numberOfSlashes++;
      }
    }

  return numberOfSlashes;
}

int get_slash_position(char *input)
{
  int slashPosition = 0;
  for(int i = 0; input[i] != 0; i++)
    {
      if (input[i] == '/') {
	return i;
      }
    }

  return 0;
}

void get_ip_string(char * input, char * destination, int slashPosition)
{
  for (int i = 0; i < slashPosition; i++) {
    destination[i] = input[i];
    destination[i + 1] = 0;
  }
}

void get_netmask_string(char * input, char * destination, int slashPosition)
{
  for (int i = slashPosition + 1, j = 0; input[i] != 0; i++, j++) {
    destination[j] = input[i];
    destination[j + 1] = 0;
  }
}

void print_ip_address(int * number_addr)
{
  unsigned char * raw_ptr; // pointer to get single bytes
  int i, aux_int;
  raw_ptr = (unsigned char *) number_addr;

  for (i = 3; i > -1; i--) // run through the four integer bytes
    {
      aux_int = raw_ptr[i];
      printf("%d", aux_int);
      if(i != 0)
	printf(".");
    }

  printf(" ");
}

void binary_print(unsigned int number)
{
  unsigned int mask = 0xff000000; // last byte mask
  unsigned int shift = 24; // separate bytes
  unsigned int byte, byte_iterator, bit_iterator; // auxiliary variables

  for(byte_iterator = 0; byte_iterator < 4; byte_iterator++) // byte iterator
    {
      byte = (number & mask) >> shift;
      printf(" ");

      for(bit_iterator = 0; bit_iterator < 8; bit_iterator++) // bit iterator
	{
	  if(byte & 128) // print bit values
	    printf("1");
	  else
	    printf("0");
	  byte <<= 1;
	}
      mask >>= 8; // adjust mask for next byte
      shift -= 8; // adjust shift for next byte

    }
}

/* Store the results */
void handle_input(char * string)
{
  unsigned int i, shift, temp = 0;

  /* Cast the input string to an integer */
  shift = 24;
  ip_number = (atoi(&string[0]) << shift);
  shift -= 8;

  for(i = 0; string[i] != 0; i++)
    {
      if(string[i] == 46) /* If it's a dot get the value after it */

	{
	  ip_number += (atoi(&string[i + 1]) << shift);
	  shift -= 8;
	}
    }

  /* Get the number of bits of the mask */
  for(i = 0; string[i] != 0; i++)
    {
      if(string[i] == 47) /* If it's a slash get the value after it */
	{
	  netmask_bits += atoi(&string[i + 1]);
	}
    }

  /* Cast the mask into an integer */
  for(i = 31; i > (31 - netmask_bits); i--)
    {
      temp = (1 << i);
      netmask_number += temp;
    }
}
