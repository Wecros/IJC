# @file Makefile
# @author Marek Filip (xfilip46), FIT BUT
# @date 19/Mar/2020
# @brief IJC-DU1, příklad a), b)
# @details Makefile for IJC project. Tries to use general makefile rules.
#		   Project only recompiles when some file changes.
#          Compiled: gcc 9.2

CC=gcc
PRIMES=primes.c
NAME=$(PRIMES)
CFLAGS=-g -std=c11 -pedantic -Wall -Wextra -O2
LDFLAGS=-lm

LOGIN = xfilip46
ZIP_FILE = $(LOGIN).zip

PRIMES_OBJS = primes.o eratosthenes.o error.o bitset.o
PRIMES_I_OBJS = primes-i.o eratosthenes-i.o bitset-i.o error.o
DECODE_OBJS = steg-decode.o ppm.o eratosthenes.o error.o
HEADERS = $(wildcard *.h)

.PHONY: all run clean pack

all: primes primes-i steg-decode

run: all
	ulimit -s 65535 && ./primes && ./primes-i

primes: $(PRIMES_OBJS)
	$(CC) $(CFLAGS) -o $@ $^ $(LDFLAGS)
primes-i: $(PRIMES_I_OBJS)
	$(CC) $(CFLAGS) -DUSE_INLINE -o $@ $^ $(LDFLAGS)

steg-decode: $(DECODE_OBJS)
	$(CC) $(CFLAGS) -o $@ $^ $(LDFLAGS)

%-i.o: %.c $(HEADERS)
	$(CC) $(CFLAGS) -DUSE_INLINE -c $< -o $@

%.o: %.c $(HEADERS)
	$(CC) $(CFLAGS) -c $< -o $@

pack: $(ZIP_FILE)
$(ZIP_FILE): *.c *.h Makefile
	zip $@ $^

clean:
	rm -f primes primes-i steg-decode vgcore.* *.o
