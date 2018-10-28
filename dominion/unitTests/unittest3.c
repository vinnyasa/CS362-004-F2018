/**
 * Assignment:  CS362 - Assignment 3
 * Date: October 27, 2018
 * Author: Vinny Harris-Riviello
 * Description: Unit Test section: Unit tests for four functions (not card implementations, and not cardEffect)
 * This is unitest3, testing updateCoins function from dominion.c a function of more than 5 lines of code.
 */


#include "dominion.h"
#include "dominion_helpers.h"
#include <stdio.h>
#include <assert.h>

void testUpdateCoins();

int main () {
	testUpdateCoins();
}


void testUpdateCoins()
{
	struct gameState state;
	state.numPlayers = 1;
	state.handCount[0] = 0;

	// test bonus
	int updated = updateCoins(0, &state, 3);
	assert(3 == state.coins);
	assert(0 == updated);

	state.handCount[0] = 1;

	// test copper branch
	state.hand[0][0] = copper;
	int updated2 = updateCoins(0, &state, 0);
	assert(1 == state.coins);
	assert(0 == updated2);

	//test silver branch
	state.hand[0][0] = silver;
	int updated3 = updateCoins(0, &state, 0);
	assert(2 == state.coins);
	assert(0 == updated3);

	//test gold branch
	state.hand[0][0] = gold;
	int updated4 = updateCoins(0, &state, 1);
	assert(4 == state.coins);
	assert(0 == updated4);

	//test no gain
	state.hand[0][0] = smithy;
	int updated5 = updateCoins(0, &state, 0);
	assert(0 == state.coins);
	assert(0 == updated5);

}





