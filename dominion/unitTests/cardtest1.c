/**
 * Assignment:  CS362 - Assignment 3
 * Date: October 27, 2018
 * Author: Vinny Harris-Riviello
 * Description: Unit Test section: Unit tests for four card functions.
 * This is cardtest1, testing  aventurer card effect from dominion.c.
 */

#include "dominion.h"
#include "dominion_helpers.h"
#include <stdio.h>
#include "testUtility.h"
#include <assert.h>

void testAdventurerEffect();

int main () {
	testAdventurerEffect();
}


/**
 *  Reveal cards from your deck until you reveal 2 Treasure cards.
 *  Put those Treasure cards into your hand and discard the other revealed cards.
 **/

void testAdventurerEffect()
{
	struct gameState state;
	int currentPlayer = 0;
	//int drawnTreasure = 0;
	int deckCount = 3;
	state.numPlayers = 1;
	state.deckCount[currentPlayer] = deckCount;
	state.handCount[currentPlayer] = 1;

	//set top 2 cards to a treasure
	state.deck[currentPlayer][deckCount-1] = silver;
	state.deck[currentPlayer][deckCount-2] = gold;
	state.deck[currentPlayer][deckCount-deckCount] = smithy;
	//state.supplyCount[2] = 0;

	// test treasure cards branch
	int successfulEffect = cardEffect(adventurer, 0, 0, 0, &state, 0, 0);
	int goldCard = state.hand[currentPlayer][state.handCount[currentPlayer]-1];
	int silverCard = state.hand[currentPlayer][state.handCount[currentPlayer]-2];
	myAssert(gold, goldCard, "adventureEffect()", "where card is treasure card");
	myAssert(silver, silverCard, "adventureEffect()", "where card is treasure card");
	myAssert(0, successfulEffect, "adventureEffect()", "where card is treasure card and succesfully finished");

	//test no treasure cards branch
	deckCount = 4;
	state.discardCount[currentPlayer] = 0;
	state.deckCount[currentPlayer] = deckCount;

	//set hand top 2 non treasure
	state.deck[currentPlayer][deckCount-1] = gardens;
	state.deck[currentPlayer][deckCount-2] = village;
	state.deck[currentPlayer][deckCount-3] = copper;
	state.deck[currentPlayer][deckCount-deckCount] = silver;


	successfulEffect = cardEffect(adventurer, 0, 0, 0, &state, 0, 0);
	myAssert(gardens, state.discard[currentPlayer][0], "discardCount()", "where card is no treasure card");
	myAssert(village, state.discard[currentPlayer][1], "discardCount()", "where card is no treasure card");

	silverCard = state.hand[currentPlayer][state.handCount[currentPlayer]-1];
	int copperCard = state.hand[currentPlayer][state.handCount[currentPlayer]-2];
	myAssert(silver, silverCard, "discardCount()", "where card is treasure card after two non treasures");
	myAssert(copper, copperCard, "discardCount()", "where card is treasure card after two non treasures");
	myAssert(0, successfulEffect, "discardCount()", "where card is not treasure card and successfully finished");

}




