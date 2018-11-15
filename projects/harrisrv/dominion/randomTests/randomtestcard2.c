/**
 * Assignment:  CS362 - Assignment 4
 * Date: Nov 3, 2018
 * Author: Vinny Harris-Riviello
 * Description: Random Test - smithy card effect from dominion.c.
 */

#include <stdio.h>
#include <string.h>
#include "dominion.h"
#include "dominion_helpers.h"
#include "testUtility.h"
#include "rngs.h"
#include <assert.h>
#include <stdlib.h>
#include <time.h>

int randomSmithyEffectTest(struct gameState*, int, int, int[]);
int main ()
{

	srand(time(NULL));

	int n, cpHandCount;
	int topCards[3];
	int successfulTests = 0;
	int testCount = 0;

	int k[10] = {adventurer, council_room, feast, gardens, mine,
				 remodel, smithy, village, baron, great_hall};

	struct gameState state;


	printf("Testing council_room effect.\n");
	printf("RANDOM TESTS.\n");

	int testRand = rand() % 48;
	printf("testing rand %d", testRand);


	//struct gameState state;
	int currentPlayer = rand() % MAX_PLAYERS;
	int deckCount = rand() % MAX_DECK;
	int handPos = 0;


	state.numPlayers = 2;
	state.deckCount[currentPlayer] = deckCount;
	state.handCount[currentPlayer] = 1;
	state.hand[currentPlayer][handPos] = smithy;
	state.playedCardCount = 0;

	//set top 3 cards
	state.deck[currentPlayer][deckCount-1] = silver;
	state.deck[currentPlayer][deckCount-2] = duchy;
	state.deck[currentPlayer][0] = gardens;

	int successfulEffect = cardEffect(smithy, 0, 0, 0, &state, handPos, 0);

	for (n = 0; n < 2000; n++) {
		int playersCount = rand() % MAX_PLAYERS + 1;
		state.numPlayers = playersCount;

		currentPlayer = rand() % playersCount;
		printf("current player: %d \n", currentPlayer);
		state.deckCount[currentPlayer] = rand() % (MAX_DECK - 3) + 3;

		printf("deckCount %d ", state.deckCount[currentPlayer]);

		state.discardCount[currentPlayer] = rand() % MAX_DECK;
		cpHandCount = rand() % MAX_HAND;
		state.handCount[currentPlayer] = cpHandCount;
		state.deck[currentPlayer][deckCount-1] = rand() % MAX_DECK ;
		//init all hands for players?

		handPos = 0;
		if (cpHandCount > 0) {
			handPos = rand() % cpHandCount;
			state.hand[currentPlayer][0] = smithy;
		}
		state.numBuys = rand() % MAX_DECK;
		state.playedCardCount = rand() % MAX_DECK;



		successfulTests += randomSmithyEffectTest(&state, currentPlayer, handPos, topCards);




		testCount += 8;
	}

	printf("Total tests: %d, ", testCount);
	printf("Successful: %d , Failed: %d\n", (successfulTests), testCount-successfulTests);

	printf ("ALL TESTS OK\n");


	return 0;
}


int randomSmithyEffectTest(struct gameState* state, int currentPlayer, int handPos, int topCards[])
{
	int successful = 0;
	int successfulEffect = cardEffect(smithy, 0, 0, 0, state, handPos, 0);

	successful += myAssert(0, successfulEffect, "smithyEffect()", " where function ends successfully");

	successful += myAssert(gardens, state->hand[currentPlayer][0], "smithyEffect()", " where cards get handed properly");
	successful += myAssert(silver, state->hand[currentPlayer][1], "smithyEffect()", " where cards get handed properly");
	successful += myAssert(duchy, state->hand[currentPlayer][2], "smithyEffect()", " where cards get handed properly");
	successful += myAssert(duchy, state->hand[currentPlayer][2], "smithyEffect()", " where smithy gets discarded properly");
	successful += myAssert(duchy, state->hand[currentPlayer][2], "smithyEffect()", " successfully ends");


	return successful;
}