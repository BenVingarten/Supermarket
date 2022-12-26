
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>
#include "Address.h"
#include "GeneralFunc.h"


void printAddress(const Address* address)
{
	printf("%s %d, %s\n", address->street, address->homeNumber, address->city);
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
int initAddress(Address* address)
{
	
	char* del = "#";
	char insertedAdd[MAX_LENGTH];
	int numOfDel;

	printf("Enter address data by the next format: street#number#city \nNo spaces with the number\n");
	myGets(insertedAdd, MAX_LENGTH);
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

	// allocate Street
	address->street = (char*)malloc(sizeof(char) * (strlen(addressParts[0]) + 1));
	if (!address->street)
		return 0;

	strcpy(address->street, addressParts[0]);

	// initiallize homeNumber
	int num = atoi(addressParts[1]);
	if (!num)
		return 0;
	address->homeNumber = num;

	// allocate City
	address->city = (char*)malloc(sizeof(char) * (strlen(addressParts[2]) + 1));
	if (!address->city)
		return 0;
	strcpy(address->city, addressParts[2]);

	fixAddressFormat(address);
	return 1;
	
}

