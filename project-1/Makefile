PRIMES=primes.c
NAME=${PRIMES}
FLAGS=-g -std=c11 -pedantic -Wall -Wextra -lm -O2
LC_ALL=cs_CZ.utf8

all:
	gcc -o build/primes ${FLAGS} primes.c 
	gcc -o build/primes-i ${FLAGS} -DUSE_INLINE primes.c 

run:
	gcc -o build/primes ${FLAGS} primes.c 
	gcc -o build/primes-i ${FLAGS} -DUSE_INLINE primes.c 
	./build/primes && echo && ./build/primes-i 

primes:
	gcc -o build/primes ${FLAGS} primes.c 

primes-i:
	gcc -o build/primes-i ${FLAGS} -DUSE_INLINE primes.c 

clean:
	rm a.out build/*

x32:
	gcc ${FLAGS} -m32 ${NAME}