## Subnettr - a simple command line network calculator


Subnettr calculates the useful values for a network given the IP address and CIDR subnet mask input on the command line.


### Usage


Subnettr is a command line utility that can be called with the subnettr command followed by the IP address of a node combined with the subnet mask in CIDR notation as in the following example:

```bash
$ ./subnettr 192.168.178.12/26
```


The above command line will produce the following output:

```bash
Entry: 192.168.178.12/26

Network address:192.168.178.0
Netmask:			255.255.255.192		(26 bits)
Broadcast addr:		192.168.178.63
Min Host value:		192.168.178.1
Max Host value:		192.168.178.62

The number of availible hosts on this network is 62.
```


### Requirements


Subnettr requires GCC or some other POSIX complient C compiler along with GNU Make.
