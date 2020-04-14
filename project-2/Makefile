# @file Makefile
# @author Marek Filip (xfilip46), FIT BUT
# @date 31/Mar/2020
# @brief IJC-DU2, příklad a), b)
# @details Makefile for IJC project. Tries to use general makefile rules.
#		   Project only recompiles when some file changes.
#          Compiled: gcc 9.3

LOGIN = xfilip46
ZIP_FILE = $(LOGIN).zip

CC = gcc
CXX = g++
CFLAGS   = -g -std=c99 -pedantic -Wall -Wextra
CFLAGS  += -O2
CXXFLAGS = -std=c++17 -pedantic -Wall -Wextra
AR = ar

PROGRAMS = tail wordcount wordcount-dynamic
HEADERS  = $(wildcard *.h)
LIBS     = libhtab.a libhtab.so
STATIC_OBJS  = htab.o io.o private.o
DYNAMIC_OBJS = htab-d.o io-d.o private-d.o
STATIC_LIB   = libhtab.a
DYNAMIC_LIB  = libhtab.so

.PHONY: all libs pack clean

# Napište soubor Makefile tak, aby příkaz make vytvořil programy
# "tail", "wordcount", "wordcount-dynamic" a knihovny "libhtab.a",
# "libhtab.so" (nebo "htab.dll" atd.).
all: $(PROGRAMS)

$(STATIC_LIB): $(STATIC_OBJS)
	$(AR) crs $(STATIC_LIB) $^
	ranlib $(STATIC_LIB)

$(DYNAMIC_LIB): $(DYNAMIC_OBJS)
	$(CC) -shared -fPIC $^ -o $@

wordcount: wordcount.o $(STATIC_LIB)
	$(CC) $(CFLAGS) -o $@ -static $< -L. -lhtab

wordcount-dynamic: wordcount.o $(DYNAMIC_LIB)
	$(CC) $(CFLAGS) -o $@ $< -L. -lhtab

%.o: %.c $(HEADERS)
	$(CC) $(CFLAGS) -c $< -o $@

%-d.o: %.c $(HEADERS)
	$(CC) $(CFLAGS) -c -fPIC $< -o $@

libs: $(LIBS)

pack: $(ZIP_FILE)
$(ZIP_FILE): *.c *.cc *.h Makefile
	zip $@ $^

clean:
	@find . -name '*.o' -exec rm -f {} +
	@find . -name 'vgcore.*' -exec rm -f {} +
	@find . -name '*.a' -exec rm -f {} +
	@find . -name '*.so' -exec rm -f {} +
	@rm -rf $(PROGRAMS)
	@echo Cleaned nonessential files.
