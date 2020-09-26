SHELL = /bin/sh

srcdir = ./src/
bindir = ./bin/
testdir = ./test/

sources = $(srcdir)subnettr.c
tests = $(testdir)test_subnettr.c
debug = -g

subnettr : $(srcdir)subnettr.c
	gcc -o $(bindir)subnettr $(debug) $(srcdir)subnettr.c -lm

.PHONY : clean
.PHONY : test
.PHONY : tests
.PHONY : backup

clean :
	rm $(bindir)subnettr $(testdir)test
tests :
	gcc $(debug) -o $(testdir)test $(debug) $(tests) $(sources) -lcmocka
test :
	$(testdir)test
backup :
	$(bindir)backup.sh
