PRIMES=primes.c
NAME=${PRIMES}
FLAGS=-g -std=c11 -pedantic -Wall -Wextra
LC_ALL=cs_CZ.utf8

make:
	gcc ${FLAGS} ${PRIMES}

run:
	gcc ${FLAGS} ${NAME}
	./a.out

primes:
	gcc ${FLAGS} primes.c

primes-i:
	gcc ${FLAGS} primes.c

eratosthenes:
	gcc ${FLAGS} eratosthenes.c -lm

x32:
	gcc ${FLAGS} -m32 ${NAME}