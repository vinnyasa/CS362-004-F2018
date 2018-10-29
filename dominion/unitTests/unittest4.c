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
#include "testUtility.h"

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
	myAssert(-1, failedGain, "testGainCard()", " where failed to gain card");

	state.supplyCount[2] = 3;

	// test added to discard
	int discarded = gainCard(2, &state, 0, 0);
	state.discardCount[0] = 0;
	myAssert(0, discarded, "testGainCard()", " where added to discard");
	myAssert(1, state.discardCount[0], "testGainCard()", " where added to discard and against discard count");

	//test added to deck
	int toDeck = gainCard(2, &state, 1, 0);
	state.deckCount[0] = 0;
	myAssert(0, toDeck, "testGainCard()", " where added to deck");
	myAssert(1, state.deckCount[0], "testGainCard()", " where added to deck and against deck count");

	//test added to hand
	int toHand = gainCard(2, &state, 2, 0);
	myAssert(0, toHand, "testGainCard()", " where added to hand");
	myAssert(2, state.handCount[0], "testGainCard()", " where added to hand and against hand count");

	//test supplyCount decreased
	myAssert(0, state.supplyCount[2], "testGainCard()", " where supply count to decrease");
}


