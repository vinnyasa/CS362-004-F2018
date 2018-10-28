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

void testGetCost();

int main () {
	testGetCost();
}


void testGetCost()
{
	assert(0 == getCost(curse));
	assert(2 == getCost(estate));
	assert(5 == getCost(duchy));
	assert(8 == getCost(province));
	assert(0 == getCost(copper));
	assert(3 == getCost(silver));
	assert(6 == getCost(gold));
	assert(6 == getCost(adventurer));
	assert(5 == getCost(council_room));
	assert(4 == getCost(feast));
	assert(4 == getCost(gardens));
	assert(5 == getCost(mine));
	assert(4 == getCost(remodel));
	assert(4 == getCost(smithy));
	assert(3 == getCost(village));
	assert(4 == getCost(baron));
	assert(3 == getCost(great_hall));
	assert(5 == getCost(minion));
	assert(3 == getCost(steward));
	assert(5 == getCost(tribute));
	assert(3 == getCost(ambassador));
	assert(4 == getCost(cutpurse));
	assert(2 == getCost(embargo));
	assert(5 == getCost(outpost));
	assert(4 == getCost(salvager));
	assert(4 == getCost(sea_hag));
	assert(4 == getCost(treasure_map));
	assert(-1 == getCost(-1));
	assert(-1 == getCost(144));
}




