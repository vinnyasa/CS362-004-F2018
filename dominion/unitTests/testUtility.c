
#include<stdio.h>
#include<stdlib.h>
#include "testUtility.h"


void myAssert(int expected, int actual, char signature[], char msg[])
{
	if(expected == actual)
	{
		printf("PASS: ");
		puts(signature);
		printf(" ... ");
		puts(msg);
		printf("\n");

	} else
	{
		printf("FAILED: ");
		puts(signature);
		printf(" ... ");
		puts(msg);
		printf("Expected: %d but Actual: %d\n", expected,actual);
		printf("_______________________________\n");

	}

}


