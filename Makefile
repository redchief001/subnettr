SHELL = /bin/sh

libdir = ./lib/
srcdir = ./src/
bindir = ./bin/
testdir = ./test/

objects = $(libdir)convlib.o $(libdir)netstructs.o $(libdir)strmanip.o
sources = $(libdir)convlib.c $(libdir)netstructs.c $(libdir)strmanip.c
tests = $(testdir)test_subnettr.c
debug = -g

subnettr : $(srcdir)subnettr.c netlib.a
	gcc -o $(bindir)subnettr $(debug) $(srcdir)subnettr.c $(libdir)netlib.a
netlib.a : $(objects)
	ar rs $(libdir)netlib.a $(objects)
convlib.o : $(libdir)convlib.h
netstructs.o : $(libdir)netstructs.h
strmanip.o : $(libdir)strmanip.h

.PHONY : clean
.PHONY : test
.PHONY : tests
.PHONY : backup

clean :
	rm $(bindir)subnettr $(libdir)netlib.a $(objects) $(testdir)test
tests :
	gcc $(debug) -o $(testdir)test $(debug) $(tests) $(sources) -lcmocka
test :
	$(testdir)test
backup :
	$(bindir)backup.sh
