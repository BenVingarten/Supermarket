
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "Address.h"
#include "GeneralFunc.h"



int initAddress(Address* address) 
{
	address->street = malloc(MAX_LENGTH * sizeof(char));
	address->city = malloc(MAX_LENGTH * sizeof(char));
	if (!address->street || !address->city)
		return 0;
	return 1;
}

int getAddress(Address* address)
{/*
 getAdress - argument: Address* | return: NULL (0) if didn't get valid data, else return true (!0)
 get the address in format of street#number#city
 */
	// check if the user entered string by format.
	char* del = "#";
	char insertedAdd[MAX_ADDRESS];
	int numOfDel;

	do
	{
		printf("Please enter address by the next format: street#number#city \nMax Lenght is 254 & no spaces with the number\n");
		myGets(insertedAdd, MAX_ADDRESS);
		numOfDel = countCharInString(insertedAdd, '#');

	} while (!insertedAdd && numOfDel != 2);


	char* addressParts[3];
	char* temp = strtok(insertedAdd, del);
	int i = 0;

	while(temp)
	{
		if (strlen(temp) == 0)
			return 0;
		strcpy(addressParts[i++],temp);
		temp = strtok(NULL, del);
	}

	strcpy(address->street, addressParts[0]);
	address->homeNumber = *addressParts[1] - '0';
	strcpy(address->city, addressParts[0]);
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