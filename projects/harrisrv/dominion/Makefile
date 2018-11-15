CFLAGS= -Wall -fpic -coverage -lm -std=c99

rngs.o: rngs.h rngs.c
	gcc -c rngs.c -g  $(CFLAGS)

dominion.o: dominion.h dominion.c rngs.o
	gcc -c dominion.c -g  $(CFLAGS)

playdom: dominion.o playdom.c
	gcc -o playdom playdom.c -g dominion.o rngs.o $(CFLAGS)
#To run playdom you need to entere: ./playdom <any integer number> like ./playdom 10*/
testDrawCard: testDrawCard.c dominion.o rngs.o
	gcc  -o testDrawCard -g  testDrawCard.c dominion.o rngs.o $(CFLAGS)

badTestDrawCard: badTestDrawCard.c dominion.o rngs.o
	gcc -o badTestDrawCard -g  badTestDrawCard.c dominion.o rngs.o $(CFLAGS)

testBuyCard: testDrawCard.c dominion.o rngs.o
	gcc -o testDrawCard -g  testDrawCard.c dominion.o rngs.o $(CFLAGS)

testAll: dominion.o testSuite.c
	gcc -o testSuite testSuite.c -g  dominion.o rngs.o $(CFLAGS)

interface.o: interface.h interface.c
	gcc -c interface.c -g  $(CFLAGS)

runtests: testDrawCard
	./testDrawCard &> unittestresult.out
	gcov dominion.c >> unittestresult.out
	cat dominion.c.gcov >> unittestresult.out


unittestresults: unittestresults.out

unittestresults.out: unittest1.o dominion.o testUtility.o  rngs.o
gcc -c unittest1.c dominion.c testUtility.c rngs.c

testUtility.o: testUtility.h testUtility.c
	gcc -c testUtility.c -g  $(CFLAGS)

randomtestcard1: randomtestcard1.c dominion.o rngs.o testUtility.o
	gcc -o randomtestcard1 -g  randomtestcard1.c dominion.o rngs.o testUtility.o $(CFLAGS)

randomtestcard2: randomtestcard2.c dominion.o rngs.o testUtility.o
	gcc -o randomtestcard2 -g  randomtestcard2.c dominion.o rngs.o testUtility.o $(CFLAGS)

radomtestadventurer: radomtestadventurer.c dominion.o rngs.o testUtility.o
	gcc -o radomtestadventurer -g  radomtestadventurer.c dominion.o rngs.o testUtility.o $(CFLAGS)

randomtestcard1.out: randomtestcard1.c playdom
	./randomtestcard1 >> randomtestcard1.out
	echo "GCOV After randomtestcard1" >> randomtestcard1.out
	gcov -f dominion.c >> randomtestcard1.out

randomtestcard2.out: randomtestcard2.c playdom
	./randomtestcard2 >> randomtestcard2.out
	echo "GCOV After randomtestcard2" >> randomtestcard2.out
	gcov -f dominion.c >> randomtestcard2.out

randomtestadventurer.out: randomtestadventurer.c playdom
	./randomtestadventurer >> randomtestadventurer.out
	echo "GCOV After randomtestadventurer" >> randomtestadventurer.out
	gcov -f dominion.c >> randomtestadventurer.out

player: player.c interface.o
	gcc -o player player.c -g  dominion.o rngs.o interface.o $(CFLAGS)

all: playdom player

clean:
	rm -f *.o playdom.exe playdom player player.exe  *.gcov *.gcda *.gcno *.so *.out testDrawCard testDrawCard.exe randomtestcard1 randomtestcard2 randomtestadventurer
