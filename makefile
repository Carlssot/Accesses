CC = g++
CPPFLAGS = -g -Wall


accesses: accesses.o syslog.o sysentry.o

accesses.o: accesses.cpp syslog.h 

syslog.o: syslog.h syslog.cpp

sysentry.o: sysentry.cpp sysentry.h

clean:
	rm -f *.o accesses myoutput.txt
