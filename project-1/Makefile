CC=gcc
PRIMES=primes.c
NAME=${PRIMES}
CFLAGS=-g -std=c11 -pedantic -Wall -Wextra -lm -O2
LDFLAGS=-lm
LC_ALL=cs_CZ.utf8
DEPS=

EXECUTABLES = primes primes-i
OBJS = eratosthenes.o primes.o

all: ${EXECUTABLES}

run: all clean
	./primes && ./primes-i

primes: ${OBJS}
	${CC} ${CFLAGS} -o $@ $^ ${LDFLAGS}

primes-i: CFLAGS += -DUSE_INLINE
primes-i: ${OBJS}
	${CC} ${CFLAGS} -o $@ $^ ${LDFLAGS}

eratosthenes.o: eratosthenes.c
	${CC} ${CFLAGS} -c $^ ${LDFLAGS}

primes.o: primes.c
	${CC} ${CFLAGS} -c $^ ${LDFLAGS}

clean: 
	rm -f $EXECUTABLES *.o

# all: ${EXECUTABLES}

# ${EXECUTABLES}: ${OBJS}

# primes: ${OBJS}
# 	${CC} ${CFLAGS} -o $@ $^ ${LDFLAGS}

# primes-i: ${OBJS}
# 	${CC} ${CFLAGS} -DUSE_INLINE -o $@ $^ ${LDFLAGS}

# primes.o: primes.c
# 	${CC} ${CFLAGS} -c $^ ${LDFLAGS}

# primes-i.o: primes.c
# 	${CC} ${CFLAGS} -DUSE_INLINE -c $^ ${LDFLAGS}

# erathosthenes.o: erathosthenes.c
# 	${CC} ${CFLAGS} -c $^ ${LDFLAGS}



# OBJS	= error.o ppm.o steg-decode.o ertosthenes.o primes.o
# SOURCE	= error.c ppm.c steg-decode.c ertosthenes.c primes.c
# HEADER	= bitset.h error.h ppm.h

# TODO: new makefiled

# http://ivs.fit.vutbr.cz/IVS2019-20_06-make.pdf

# all: 
# 	${CC} -o build/primes ${FLAGS} primes.c 
# 	${CC} -o build/primes-i ${FLAGS} -DUSE_INLINE primes.c 

# # all: primes.o
# 	# ${CC} -o build/primes primes.o ${LINKER}
# 	# ${CC} -o build/primes-i primes-i.o ${LINKER}
# 	# ${CC} -o build/primes primes-i.o

# primes.o: primes.c
# 	${CC} ${FLAGS} -c primes.c
# 	${CC} ${FLAGS} -DUSE_INLINE -c primes.c

# primes-i.o: primes.c
# 	${CC} ${FLAGS} -DUSE_INLINE -c primes.c

# run: all
# 	./build/primes && echo && ./build/primes-i 

# primes:
# 	${CC} -o build/primes ${FLAGS} primes.c 

# primes-i:
# 	${CC} -o build/primes-i ${FLAGS} -DUSE_INLINE primes.c 

# clean:
# 	rm a.out build/*

# x32:
# 	${CC} ${FLAGS} -m32 ${NAME}

# OBJS	= error.o ppm.o steg-decode.o ertosthenes.o primes.o
# SOURCE	= error.c ppm.c steg-decode.c ertosthenes.c primes.c
# HEADER	= bitset.h error.h ppm.h
# OUT	= primes.out
# CC	 = gcc
# FLAGS	 = -g -c -Wall
# LFLAGS	 = -lm

# all: $(OBJS)
# 	$(CC) -g $(OBJS) -o $(OUT) $(LFLAGS)

# error.o: error.c
# 	$(CC) $(FLAGS) error.c 

# ppm.o: ppm.c
# 	$(CC) $(FLAGS) ppm.c 

# steg-decode.o: steg-decode.c
# 	$(CC) $(FLAGS) steg-decode.c 

# ertosthenes.o: ertosthenes.c
# 	$(CC) $(FLAGS) ertosthenes.c 

# primes.o: primes.c
# 	$(CC) $(FLAGS) primes.c 


# clean:
# 	rm -f $(OBJS) $(OUT)

# run: $(OUT)
# 	./$(OUT)