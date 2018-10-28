/**
 * Assignment:  CS362 - Assignment 3
 * Date: October 27, 2018
 * Author: Vinny Harris-Riviello
 * Description: Unit Test section: Unit tests for four card functions.
 * This is cardtest4, testing feast card effect from dominion.c.
 */

#include "dominion.h"
#include "dominion_helpers.h"
#include <stdio.h>
#include <assert.h>

void testFeastEffect();

int main () {
	testFeastEffect();
}

/**
 * Trash this card. Gain a card costing up to $5
 **/

void testFeastEffect()
{
	struct gameState state;
	int currentPlayer = 0;
	int deckCount = 3;
	int handPos = 0;
	int goodChoice = minion;
	int highChoice = gold;
	int noSupplyChoice = adventurer;

	//setup currentPlayer
	state.numPlayers = 2;
	state.deckCount[currentPlayer] = deckCount;
	state.handCount[currentPlayer] = 2;

	state.hand[currentPlayer][0] = feast;
	state.hand[currentPlayer][1] = village;
	state.numBuys = 0;
	state.playedCardCount = 0;
	state.supplyCount[gold] = 2;
	state.supplyCount[minion] = 1;
	state.supplyCount[adventurer] = 0;

	//set top 3 cards
	state.deck[currentPlayer][deckCount-1] = silver;
	state.deck[currentPlayer][deckCount-2] = duchy;
	state.deck[currentPlayer][deckCount-3] = minion;
	state.deck[currentPlayer][0] = gardens;

	// test branch good choice
	int successfulEffect = cardEffect(feast, goodChoice, 0, 0, &state, handPos, 0);
	assert(0 == successfulEffect);
	assert(2 == state.handCount[currentPlayer]);

	// test was reset properly
	assert(feast != state.hand[currentPlayer][0]);
	assert(minion == state.hand[currentPlayer][state.hand[currentPlayer][state.handCount[currentPlayer] -1]]);


	// test branch no supply
	successfulEffect = cardEffect(feast, noSupplyChoice, 0, 0, &state, handPos, 0);
	assert(0 == successfulEffect);
	assert(adventurer != state.hand[currentPlayer][state.handCount[currentPlayer] -1]);

	// test branch high cost
	successfulEffect = cardEffect(feast, highChoice, 0, 0, &state, handPos, 0);
	assert(0 == successfulEffect);
	assert(gold != state.hand[currentPlayer][state.handCount[currentPlayer] -1]);

}



