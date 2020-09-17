SHELL = /bin/sh

libdir = ./lib/
srcdir = ./src/
bindir = ./bin/
testdir = ./test/

objects = $(libdir)condtest.o $(libdir)convlib.o\
	$(libdir)netstructs.o $(libdir)strmanip.o
sources = $(libdir)condtest.c $(libdir)convlib.c\
	$(libdir)netstructs.c $(libdir)strmanip.c
tests = $(testdir)test_subnettr.c

subnettr : $(srcdir)subnettr.c netlib.a
	gcc -o $(bindir)subnettr $(srcdir)subnettr.c $(libdir)netlib.a
netlib.a : $(objects)
	ar rs $(libdir)netlib.a $(objects)
condtest.o : $(libdir)condtest.h
convlib.o : $(libdir)convlib.h
netstructs.o : $(libdir)netstructs.h
strmanip.o : $(libdir)strmanip.h

.PHONY : clean
.PHONY : tests
.PHONY : test
.PHONY : backup

clean :
	rm $(bindir)subnettr $(libdir)netlib.a $(objects) $(testdir)test
tests :
	gcc -o $(testdir)test $(tests) $(sources) -lcmocka
test :
	$(testdir)test
backup :
	$(bindir)backup.sh
