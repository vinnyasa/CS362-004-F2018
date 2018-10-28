/**
 * Assignment:  CS362 - Assignment 3
 * Date: October 27, 2018
 * Author: Vinny Harris-Riviello
 * Description: Unit Test section: Unit tests for four functions (not card implementations, and not cardEffect)
 * This is unitest4, testing  gainCard() function from dominion.c a function of more than 5 lines of code.
 */


#include "dominion.h"
#include "dominion_helpers.h"
#include <stdio.h>
#include <assert.h>

void testGainCard();

int main () {
	testGainCard();
}


void testGainCard()
{
	struct gameState state;
	state.numPlayers = 1;
	state.handCount[0] = 1;
	state.supplyCount[2] = 0;

	//test failed
	int failedGain = gainCard(2, &state, 0, 0);
	assert(-1 == failedGain);

	state.supplyCount[2] = 3;

	// test added to discard
	int discarded = gainCard(2, &state, 0, 0);
	state.discardCount[0] = 0;
	assert(0 == discarded);
	assert(1 == state.discardCount[0]);

	//test added to deck
	int toDeck = gainCard(2, &state, 1, 0);
	state.deckCount[0] = 0;
	assert(0 == toDeck);
	assert(1 == state.deckCount[0]);

	//test added to hand
	int toHand = gainCard(2, &state, 2, 0);
	assert(0 == toHand);
	assert(2 == state.handCount[0]);

	//test supplyCount decreased
	assert(0 == state.supplyCount[2]);
}


