/**
 * Assignment:  CS362 -Assignment 3
 * Date: October 27, 2018
 * Author: Vinny Harris-Riviello
 * Description: Unit Test section: Unit tests for four functions (not card implementations, and not cardEffect)
 * This is unitest1, testing compare function from dominion.c a function of 5 lines of code.
 */


#include "dominion.h"
#include <stdio.h>
#include <assert.h>
#include "testUtility.h"

int compare(const int* a, const int* b);
void testCompare();

int main () {
	testCompare();
}


void testCompare()
{
	int a = 8;
	int b = 5;

	// test greater than
	myAssert(1, compare(&a, &b), "testCompare()", "where greater than");

	// test less than
	a = 1;
	b = 7;
	myAssert(-1, compare(&a, &b), "testCompare()", "where less than");
	//assert(-1 == compare(&a, &b));

	// test equal
	a = 2;
	b = 2;
	myAssert(0, compare(&a, &b), "testCompare()", "where equal to");
}

