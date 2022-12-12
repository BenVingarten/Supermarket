#define _CRT_SECURE_NO_WARNINGS
#include "exe.h"


void checkAddress(Address* ad)
{
	if (!initAddress(&ad))
		printf("Error!\n");
	
	else {
		int get = getAddress(&ad);
		while (!get)
			get = getAddress(&ad);
	}
		fixAddressFormat(&ad);
		printAddress(&ad);
		freeAddress(&ad);
	
}


