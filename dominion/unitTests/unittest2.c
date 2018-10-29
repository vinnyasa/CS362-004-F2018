/**
 * Assignment:  CS362 - Assignment 3
 * Date: October 27, 2018
 * Author: Vinny Harris-Riviello
 * Description: Unit Test section: Unit tests for four functions (not card implementations, and not cardEffect)
 * This is unitest2, testing getCost function from dominion.c a function of more than 5 lines of code.
 */


#include "dominion.h"
#include "dominion_helpers.h"
#include <stdio.h>
#include <assert.h>
#include "testUtility.h"

void testGetCost();

int main () {
	testGetCost();
}


void testGetCost()
{
	myAssert(0, getCost(curse), "getCost()", " where card is curse");

	myAssert(2, getCost(estate), "getCost()", " where card is estate");

	myAssert(5, getCost(duchy), "getCost()", " where card is duchy");

	myAssert(8, getCost(province), "getCost()", " where card is province");

	myAssert(0, getCost(copper), "getCost()", " where card is copper");

	myAssert(3, getCost(silver), "getCost()", " where card is silver");

	myAssert(6, getCost(gold), "getCost()", " where card is gold");

	myAssert(6, getCost(adventurer), "getCost()", " where card is adventurer");

	myAssert(5, getCost(council_room), "getCost()", " where card is council_room");

	myAssert(6, getCost(gold), "getCost()", " where card is gold");

	myAssert(4, getCost(feast), "getCost()", " where card is feast");

	myAssert(4, getCost(gardens), "getCost()", " where card is gardens);

	myAssert(5, getCost(mine), "getCost()", " where card is mine");

	myAssert(4, getCost(remodel), "getCost()", " where card is remodel");

	myAssert(4, getCost(smithy), "getCost()", " where card is smithy");

	myAssert(3, getCost(village), "getCost()", " where card is village");

	myAssert(4, getCost(baron), "getCost()", " where card is baron");

	myAssert(3, getCost(great_hall), "getCost()", " where card is great_hall");

	myAssert(5, getCost(minion), "getCost()", " where card is minion");

	myAssert(3, getCost(steward), "getCost()", " where card is steward");

	myAssert(5, getCost(tribute), "getCost()", " where card is tribute");

	myAssert(3, getCost(ambassador), "getCost()", " where card is ambassador");

	myAssert(4, getCost(cutpurse), "getCost()", " where card is cutpurse");

	myAssert(2, getCost(embargo), "getCost()", " where card is embargo");

	myAssert(5, getCost(outpost), "getCost()", " where card is outpost");

	myAssert(4, getCost(salvager), "getCost()", " where card is salvanger");

	myAssert(4, getCost(sea_hag), "getCost()", " where card is sea_hag");

	myAssert(4, getCost(treasure_map), "getCost()", " where card is treasure_map");

	myAssert(-1, getCost(-1), "getCost()", " where no card low edge");

	myAssert(-1, getCost(288), "getCost()", " where no card high edge");


}




