/**
 * Assignment:  CS362 - Assignment 4
 * Date: Nov 3, 2018
 * Author: Vinny Harris-Riviello
 * Description: Random Test - adventurer card effect from dominion.c.
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


#define DEBUG 0
#define NOISY_TEST 1

int isTresaure(int);
void randomTestAdventurerEffect();
int t[3] = {gold, silver, copper};

int main () {

	srand(time(NULL));
	randomTestAdventurerEffect();
	return 0;
}



/**
 *  Reveal cards from your deck until you reveal 2 Treasure cards.
 *  Put those Treasure cards into your hand and discard the other revealed cards.
 **/

void randomTestAdventurerEffect()
{
	int successTests = 0;
	int testCount = 0;
	int k[10] = {adventurer, council_room, feast, gardens, mine,
				 remodel, smithy, village, baron, great_hall};
	struct gameState state;
	int currentPlayer = 0;

	int deckCount = rand() % MAX_DECK;
	state.numPlayers = rand() % (MAX_PLAYERS - 1) + 1;

	if (state.numPlayers > 0) {
		currentPlayer = rand() % state.numPlayers;
	}

	state.deckCount[currentPlayer] = deckCount;
	state.handCount[currentPlayer] = rand() %MAX_HAND;

	//set top 2 cards to a treasure
	int tIndex = rand() % 3;
	state.deck[currentPlayer][deckCount-1] = t[tIndex];
	state.deck[currentPlayer][deckCount-2] = t[tIndex];
	int nIndex = rand() % 10;
	state.deck[currentPlayer][deckCount-deckCount] = k[nIndex];

	for (int n = 0; n < 2000; n++) {

		// test treasure cards branch, run card effect with adventurer
		int successfulEffect = cardEffect(adventurer, 0, 0, 0, &state, 0, 0);

		int goldCard = state.hand[currentPlayer][state.handCount[currentPlayer]-1];
		int silverCard = state.hand[currentPlayer][state.handCount[currentPlayer]-2];
		successTests += myAssert(1, isTresaure(goldCard), "adventureEffect()", "where card is treasure card");
		successTests += myAssert(1, isTresaure(silverCard), "adventureEffect()", "where card is treasure card");
		successTests += myAssert(0, successfulEffect, "adventureEffect()", "where card is treasure card and succesfully finished");

		//test no treasure cards branch
		deckCount = rand() % MAX_DECK;
		state.discardCount[currentPlayer] = rand() % MAX_HAND;
		state.deckCount[currentPlayer] = deckCount;

		//set hand top 2 non treasure
		nIndex = rand() % 10;
		state.deck[currentPlayer][deckCount-1] = k[nIndex];
		nIndex = rand() % 10;
		state.deck[currentPlayer][deckCount-2] = k[nIndex];
		tIndex = rand() % 3;
		state.deck[currentPlayer][deckCount-3] = t[tIndex];
		tIndex = rand() % 3;
		state.deck[currentPlayer][deckCount-deckCount] = t[tIndex];


		successfulEffect = cardEffect(adventurer, 0, 0, 0, &state, 0, 0);
		successTests += myAssert(gardens, state.discard[currentPlayer][0], "discardCount()", "where card is no treasure card");
		successTests += myAssert(village, state.discard[currentPlayer][1], "discardCount()", "where card is no treasure card");

		silverCard = state.hand[currentPlayer][state.handCount[currentPlayer]-1];
		int copperCard = state.hand[currentPlayer][state.handCount[currentPlayer]-2];
		successTests += myAssert(silver, silverCard, "discardCount()", "where card is treasure card after two non treasures");
		successTests += myAssert(copper, copperCard, "discardCount()", "where card is treasure card after two non treasures");
		successTests += myAssert(0, successfulEffect, "discardCount()", "where card is not treasure card and successfully finished");

		testCount += 8;
	}

	printf("Total tests: %d, ", testCount);
	printf("Successful: %d , Failed: %d\n", (successTests), testCount-successTests);

	printf ("ALL TESTS OK\n");

}


int isTresaure(int card) {
	for (int i = 0; i < 3; ++i) {
		if(card == t[i]) {
			return 1;
		}
	}
	return 0;
}

