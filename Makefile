SHELL = /bin/sh

srcdir = ./src/
bindir = ./bin/

sources = $(srcdir)subnettr.c

debug = -g

subnettr : $(srcdir)subnettr.c
	gcc -o $(bindir)subnettr $(debug) $(srcdir)subnettr.c -lm

.PHONY : clean
.PHONY : backup

clean :
	rm $(bindir)subnettr
backup :
	$(bindir)backup.sh
