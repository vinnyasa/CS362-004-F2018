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
#include <stdbool.h>
#include "testUtility.h"


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
	myAssert(0, successfulEffect, "feastEffect()", "where function ends successfully");
	myAssert(2, state.handCount[currentPlayer], "feastEffect()", "where hand count increments as it is supposed to with goodChoice");

	// test was reset properly
	myAssert(0, successfulEffect, "feastEffect()", "where function ends successfully");
	int minionGained = state.hand[currentPlayer][state.hand[currentPlayer][state.handCount[currentPlayer] -1]];
	myAssert(minion, minionGained, "feastEffect()", "where card is gained succesfully");

	int cardtrashed = feast != state.hand[currentPlayer][0];
	printf("Feast no longer in hand: %d, should be true", cardtrashed);

	// test branch no supply
	successfulEffect = cardEffect(feast, noSupplyChoice, 0, 0, &state, handPos, 0);
	int cardtNotGained = adventurer != state.hand[currentPlayer][state.handCount[currentPlayer] -1];
	myAssert(0, successfulEffect, "feastEffect()", "where function ends successfully in no supply choice");
	printf("Adventurer not in hand in hand: %d, should be true", cardtNotGained);


	// test branch high cost
	successfulEffect = cardEffect(feast, highChoice, 0, 0, &state, handPos, 0);
	myAssert(0, successfulEffect, "feastEffect()", "where function ends successfully with high choice");
	bool badCard = gold != state.hand[currentPlayer][state.handCount[currentPlayer] -1];
	printf("Adventurer not in hand in hand: %d, should be true", badCard);
}



