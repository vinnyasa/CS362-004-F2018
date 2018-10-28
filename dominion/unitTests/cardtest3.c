/**
 * Assignment:  CS362 - Assignment 3
 * Date: October 27, 2018
 * Author: Vinny Harris-Riviello
 * Description: Unit Test section: Unit tests for four card functions.
 * This is cardtest3, testing council room card effect from dominion.c.
 */

#include "dominion.h"
#include "dominion_helpers.h"
#include <stdio.h>
#include <assert.h>

void testCouncilRoomEffect();

int main () {
	testCouncilRoomEffect();
}

/**
 *  +4 Cards. +1 Buy. Each other player draws a card.
 **/

void testCouncilRoomEffect()
{
	struct gameState state;
	int currentPlayer = 0;
	int deckCount = 4;
	int handPos = 0;

	//setup currentPlayer
	state.numPlayers = 2;
	state.deckCount[currentPlayer] = deckCount;
	state.handCount[currentPlayer] = 1;

	state.hand[currentPlayer][handPos] = council_room;
	state.numBuys = 0;
	state.playedCardCount = 0;

	//set top 3 cards
	state.deck[currentPlayer][deckCount-1] = silver;
	state.deck[currentPlayer][deckCount-2] = duchy;
	state.deck[currentPlayer][deckCount-3] = village;
	state.deck[currentPlayer][0] = gardens;

	//setup player2
	int player2 = 1;
	state.handCount[player2] = 1;
	state.deckCount[currentPlayer] = 5;
	state.hand[player2][0] = gold;
	state.deck[player2][4] = adventurer;



	int successfulEffect = cardEffect(council_room, 0, 0, 0, &state, handPos, 0);
	assert(0 == successfulEffect);
	assert(4 == state.handCount[currentPlayer]);
	assert(gardens == state.hand[currentPlayer][0]);
	assert(silver == state.hand[currentPlayer][1]);
	assert(duchy == state.hand[currentPlayer][2]);
	assert(council_room == state.playedCards[state.playedCardCount]);

	//test player2
	assert(2 == state.handCount[player2]);
	assert(adventurer == state.hand[player2][1]);

}







