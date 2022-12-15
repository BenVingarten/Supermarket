
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>
#include "Address.h"
#include "GeneralFunc.h"

int initAddress(Address* address) 
{
	address->street = (char*)malloc(MAX_LENGTH * sizeof(char));
	address->city = (char*)malloc(MAX_LENGTH * sizeof(char));
	if (!address->street || !address->city)
		return 0;
	return 1;
}
void printAddress(const Address* address)
{
	printf("%s %d, %s", address->street, address->homeNumber, address->city);
}
void freeAddress(Address* address)
{
	free(address->street);
	free(address->city);
}
void fixAddressFormat(Address* address)
{
	fixUpperAndLowerCase(address->street);
	fixUpperAndLowerCase(address->city);
}
int getAddress(Address* address)
{
	char* del = "#";
	char insertedAdd[MAX_ADDRESS];
	int numOfDel;

	printf("Please enter address by the next format: street#number#city \nMax Lenght is 254 & no spaces with the number\n");
	myGets(insertedAdd, MAX_ADDRESS);
	numOfDel = countCharInString(insertedAdd, '#');

	if (!insertedAdd || numOfDel != 2)
		return 0;

	// split the address data to parts	
	char* addressParts[3];
	char* temp = strtok(insertedAdd, del);

	for(int i = 0; i < 3; i++)
	{
		if (!temp || strlen(temp) == 0)
			return 0;
		addressParts[i] = temp;
		temp = strtok(NULL, del);
	}

	strcpy(address->street, addressParts[0]);
	address->homeNumber = atoi(addressParts[1]);
	strcpy(address->city, addressParts[2]);

	fixAddressFormat(address);
	return 1;
	
}

