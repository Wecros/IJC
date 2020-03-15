CC=gcc
PRIMES=primes.c
NAME=${PRIMES}
CFLAGS=-g -std=c11 -pedantic -Wall -Wextra -O2
LDFLAGS=-lm
LC_ALL=cs_CZ.utf8

LOGIN = xfilip46
SERVER = merlin.fit.vutbr.cz
SERVER_DIR = ~/test/ijc-proj1
ZIP_FILE = ${LOGIN}.zip

EXECUTABLES = primes primes-i
OBJS = error.o eratosthenes.o primes.o 

.PHONY: all run clean pack valgrind fresh 

all: ${EXECUTABLES}

run: all
	ulimit -s 65535 && ./primes && ./primes-i

primes: ${OBJS}
	${CC} ${CFLAGS} -o $@ $^ ${LDFLAGS}
primes-i: CFLAGS += -DUSE_INLINE
primes-i: ${OBJS}
	${CC} ${CFLAGS} -o $@ $^ ${LDFLAGS}
%.o: %.c
	${CC} ${CFLAGS} -c $^

pack: ${ZIP_FILE}
${ZIP_FILE}: *.c *.h Makefile
	zip $@ $^

valgrind: $(EXECUTABLES)  # does not work
	ulimit -s 65535 && valgrind ./primes $(ARGS) && valgrind ./primes-i $(ARGS)

clean: 
	rm -f ${EXECUTABLES} *.o

fresh: clean all