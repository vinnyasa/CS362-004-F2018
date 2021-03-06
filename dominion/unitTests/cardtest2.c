/**
 * Assignment:  CS362 - Assignment 3
 * Date: October 27, 2018
 * Author: Vinny Harris-Riviello
 * Description: Unit Test section: Unit tests for four card functions.
 * This is cardtest2, testing  smithy card effect from dominion.c.
 */

#include "dominion.h"
#include "dominion_helpers.h"
#include <stdio.h>
#include "testUtility.h"

void testSmithyEffect();

int main () {
	testSmithyEffect();
}


/**
 *  +3 cards, discard Smithy.
 *

3. No state change should occur for other players.

4. No state change should occur to the victory card piles and kingdom card piles
 **/

void testSmithyEffect()
{
	struct gameState state;
	int currentPlayer = 0;
	int deckCount = 3;
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

	myAssert(gardens, state.hand[currentPlayer][0], "smithyEffect()", " where cards get handed properly");
	myAssert(silver, state.hand[currentPlayer][1], "smithyEffect()", " where cards get handed properly");
	myAssert(duchy, state.hand[currentPlayer][2], "smithyEffect()", " where cards get handed properly");

	myAssert(duchy, state.hand[currentPlayer][2], "smithyEffect()", " where smithy gets discarded properly");

	myAssert(duchy, state.hand[currentPlayer][2], "smithyEffect()", " successfully ends");

}







