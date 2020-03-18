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
PRIMES_OBJS = primes.o eratosthenes.o error.o
DECODE_OBJS = steg-decode.o ppm.o eratosthenes.o error.o

.PHONY: all run clean pack valgrind 

all: ${EXECUTABLES}

run: all
	ulimit -s 65535 && ./primes && ./primes-i

primes: ${PRIMES_OBJS}
	${CC} ${CFLAGS} -o $@ $^ ${LDFLAGS}
primes-i: CFLAGS += -DUSE_INLINE
primes-i: ${PRIMES_OBJS}
	${CC} ${CFLAGS} -o $@ $^ ${LDFLAGS}

steg-decode: ${DECODE_OBJS}
	${CC} ${CFLAGS} -o $@ $^ ${LDFLAGS}
steg-decode-i: CFLAGS += -DUSE_INLINE
steg-decode-i: ${DECODE_OBJS}
	${CC} ${CFLAGS} -o $@ $^ ${LDFLAGS}


%.o: %.c %.h
	${CC} ${CFLAGS} -c $^


pack: ${ZIP_FILE}
${ZIP_FILE}: *.c *.h Makefile
	zip $@ $^

valgrind: $(EXECUTABLES)  # does not work
	ulimit -s 65535 && valgrind ./primes $(ARGS) && valgrind ./primes-i $(ARGS)

clean: 
	rm -f ${EXECUTABLES} steg-decode vgcore.* *.o
