#define _CRT_SECURE_NO_WARNINGS
#include "exe.h"


void checkAddress(Address* ad)
{
	if (!initAddress(&ad))
		printf("Error!\n");
	
	else if (!getAddress(&ad))
		printf("Error!\n");
	else {
		//fixAddressFormat(&ad);
		printAddress(&ad);
		freeAddress(&ad);
	}
}


