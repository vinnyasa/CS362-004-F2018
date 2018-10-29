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
#include "testUtility.h"

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

	myAssert(0, successfulEffect, "councilRoomEffect()", " where function ends successfully");
	myAssert(4, state.handCount[currentPlayer], "councilRoomEffect()", "where player gains the cards correctly");

	myAssert(gardens, state.hand[currentPlayer][0], "councilRoomEffect()", "where player has the correct hand");
	myAssert(silver, state.hand[currentPlayer][1], "councilRoomEffect()", "here player has the correct hand");
	myAssert(duchy, state.hand[currentPlayer][2], "councilRoomEffect()", "here player has the correct hand");

	myAssert(council_room, state.playedCards[state.playedCardCount], "councilRoomEffect()", "here player has the correct hand");

	//test player2
	myAssert(2, state.handCount[player2], "councilEffect()", " where function ends successfully");
	myAssert(adventurer, state.hand[player2][1], "councilRoomEffect()", "here player has the correct hand");
}







