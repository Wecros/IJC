PRIMES=primes.c
NAME=${PRIMES}
FLAGS=-g -std=c11 -pedantic -Wall -Wextra -lm
LC_ALL=cs_CZ.utf8

all:
	gcc -o build/primes ${FLAGS} primes.c 
	# gcc -o build/primes-i ${FLAGS} -DUSE_INLINE primes.c 

run:
	gcc ${FLAGS} ${NAME}
	./a.out

primes:
	gcc ${FLAGS} primes.c -lm

primes-i:
	gcc ${FLAGS} primes.c -lm -DUSE_INLINE

x32:
	gcc ${FLAGS} -m32 ${NAME}