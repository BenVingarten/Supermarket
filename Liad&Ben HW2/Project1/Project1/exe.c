#define _CRT_SECURE_NO_WARNINGS
#include "exe.h"


void checkAddress(Address* ad)
{
	if (!initAddress(&ad))
		printf("Error!\n");
	if (!getAddress(&ad))
		printf("Error!\n");
	printAddress(&ad);
	freeAddress(&ad);
}


