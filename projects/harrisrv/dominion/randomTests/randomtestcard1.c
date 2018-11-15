/**
 * Assignment:  CS362 - Assignment 4
 * Date: Nov 3, 2018
 * Author: Vinny Harris-Riviello
 * Description: Random Test -  council room card effect from dominion.c.
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


int testCouncilRoomCard(struct gameState * , int, int, int [],  int, int, int);

int main () {

	srand(time(NULL));

	int i, n, currentPlayer, player2, handPos, cpHandCount, p2HandCount, card;
	int topCards[ 5 ];
	int failedTests = 0;
	int testCount = 0;


	int k[10] = {adventurer, council_room, feast, gardens, mine,
				 remodel, smithy, village, baron, great_hall};

	struct gameState state;


	printf ("Testing council_room effect.\n");
	printf ("RANDOM TESTS.\n");

	int testRand = rand() % 48;
	printf("testing rand %d", testRand);


	for (n = 0; n < 2000; n++) {
		int playersCount = rand() % MAX_PLAYERS + 1;
		state.numPlayers = playersCount;

		currentPlayer = rand() % playersCount;
		printf("current player: %d \n", currentPlayer);
		state.deckCount[currentPlayer] = rand() % MAX_DECK;

		printf("deckCount %d ", state.deckCount[currentPlayer]);

		state.discardCount[currentPlayer] = rand() % MAX_DECK;
		cpHandCount = rand() % MAX_HAND;
		state.handCount[currentPlayer] = cpHandCount;

		//init all hands for players?


		handPos = 0;
		if (cpHandCount > 0) {
			handPos = rand() % cpHandCount;
			state.hand[currentPlayer][0] = council_room;
		}
		state.numBuys = rand() % MAX_DECK;
		state.playedCardCount = rand() % MAX_DECK;

		do {
			player2 = rand() % playersCount;
		} while (currentPlayer == player2 && playersCount >= 2);

		// initialize card count of all players


		p2HandCount = rand() % MAX_HAND;
		state.handCount[player2] = p2HandCount;
		state.deckCount[player2] = rand() % (MAX_DECK - 1) + 1;

		// set the top 4 deck cards for player
		for (i = 0; i < 4; i++) {
			card = rand() % 10;
			topCards[i] = k[card];
			state.deck[currentPlayer][state.handCount[currentPlayer] - i] = card;
			state.deckCount[currentPlayer]++;
		}
		card = rand() % 10;
		printf("the value of i after loop %d", i);
		topCards[i] = k[card];
		state.deck[currentPlayer][state.handCount[player2] - i] = card;
		state.deckCount[player2]++;

		failedTests += testCouncilRoomCard(&state, currentPlayer, player2, topCards, handPos, cpHandCount, p2HandCount);

		testCount += 8;
	}

	printf("Total tests: %d, ", testCount);
	printf("Successful: %d , Failed: %d\n", (testCount-failedTests), failedTests);

	printf ("ALL TESTS OK\n");

	return 0;
}

/**
 *  +4 Cards. +1 Buy. Each other player draws a card.
 **/

int testCouncilRoomCard(struct gameState * state, int currentPlayer, int player2, int cards[],  int handPos,
	int cpHandCount, int p2HandCount)
{

	int failedTests = 0;

	//int successfulEffect = cardEffect(council_room, 0, 0, 0, state, handPos, 0);
	//int councilRoomEffect(struct gameState *state, int currentPlayer, int handPos);
	//int successfulEffect = cardEffect(council_room, 0, 0, 0, state, handPos, 0);
	int successfulEffect = councilRoomEffect(state, currentPlayer, handPos);

	failedTests += myAssert(0, successfulEffect, "councilRoomEffect()", " where function ends successfully");
	failedTests += myAssert(cpHandCount+4, state->handCount[currentPlayer], "councilRoomEffect()", "where player gains the cards correctly");

	for(int i = 0; i < 3; i++) {
		failedTests += myAssert(cards[i], state->hand[currentPlayer][i], "councilRoomEffect()", "where player has the correct hand");

	}

	failedTests += myAssert(council_room, state->playedCards[state->playedCardCount], "councilRoomEffect()", "where player has the correct hand");

	//test player2
	failedTests += myAssert(p2HandCount+1, state->handCount[player2], "councilEffect()", " where other players gain a card");
	failedTests += myAssert(cards[4], state->hand[player2][p2HandCount-1], "councilRoomEffect()", "where player has the correct hand");

	return failedTests;
}










