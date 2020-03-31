# @file Makefile
# @author Marek Filip (xfilip46), FIT BUT
# @date 31/Mar/2020
# @brief IJC-DU2, příklad a), b)
# @details Makefile for IJC project. Tries to use general makefile rules.
#		   Project only recompiles when some file changes.
#          Compiled: gcc 9.2

CC=g++
CFLAGS=-g -std=c++11 -O2

LOGIN = xfilip46
ZIP_FILE = $(LOGIN).zip

HEADERS = $(wildcard *.h)

.PHONY: all run clean pack

all:

run: all


%.o: %.c $(HEADERS)
	$(CC) $(CFLAGS) -c $< -o $@

pack: $(ZIP_FILE)
$(ZIP_FILE): *.c *.cc *.h Makefile
	zip $@ $^

clean:
	@find . -name '*.o' -exec rm -f {} +
