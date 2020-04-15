# @file Makefile
# @author Marek Filip (xfilip46), FIT BUT
# @date 31/Mar/2020
# @brief IJC-DU2, příklad a), b)
# @details Makefile for IJC project. Tries to use general makefile rules.
#		   Project only recompiles when some file changes.
#          Compiled: gcc 9.3

# Napište soubor Makefile tak, aby příkaz make vytvořil programy
# "tail", "wordcount", "wordcount-dynamic" a knihovny "libhtab.a",
# "libhtab.so" (nebo "htab.dll" atd.).
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
STATIC_LIB   = libhtab.a
DYNAMIC_LIB  = libhtab.so

# base objects + all the individual hashtable modules
STATIC_OBJS  = io.o private.o
STATIC_OBJS += htab_hash_fun.o htab_init.o htab_size.o htab_bucket_count.o \
	htab_find.o htab_lookup_add.o htab_erase.o htab_begin.o htab_end.o \
	htab_iterator_get_value.o htab_iterator_set_value.o htab_clear.o \
	htab_iterator_next.o htab_iterator_get_key.o htab_free.o
DYNAMIC_OBJS := $(patsubst %.o, %-d.o, $(STATIC_OBJS)) # string substitution
STATIC_OBJS  := $(DYNAMIC_OBJS)

BUILD_DIR = build

.PHONY: all libs pack clean


all: $(PROGRAMS)
run: all
	./wordcount
	LD_LIBRARY_PATH='.' ./wordcount-dynamic

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
	@find . -name '*.o' -exec rm -rf {} +
	@find . -name 'vgcore.*' -exec rm -rf {} +
	@find . -name '*.a' -exec rm -rf {} +
	@find . -name '*.so' -exec rm -rf {} +
	@rm -rf $(PROGRAMS)
	@echo Cleaned nonessential files.
