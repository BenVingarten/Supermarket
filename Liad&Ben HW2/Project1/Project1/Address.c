
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>
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

	
		printf("Please enter address by the next format: street#number#city \nMax Lenght is 254 & no spaces with the number\n");
		myGets(insertedAdd, MAX_ADDRESS);
		numOfDel = countCharInString(insertedAdd, '#');

	if(!insertedAdd || numOfDel != 2)
		return 0;


	char* addressParts[3];
	char* temp = strtok(insertedAdd, del);

	for(int i = 0; i < 3; i++)
	{
		if (!temp || strlen(temp) == 0)
			return 0;
		addressParts[i++] = temp;
		temp = strtok(NULL, del);
	}

	strcpy(address->street, addressParts[0]);
	address->homeNumber = *(addressParts[1]) + '0';
	strcpy(address->city, addressParts[2]);
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
	char* del = " ";
	char* pAddressStreet = strtok(address->street, del);
	char* pAddressCity = strtok(address->city, del);

	int numOfWordsInStreet = countWordsInString(&address->street);
	int numOfWordsInCity = countWordsInString(&address->city);
	 
	int countStreet = 0;
	int countCity = 0;

	while (pAddressStreet) {
		countStreet++;
		if (!isupper(pAddressStreet[0]) && countStreet < numOfWordsInStreet )
			toupper(pAddressStreet[0]);
		else if(!islower(pAddressStreet[0]) && countStreet == numOfWordsInStreet)
			tolower(pAddressStreet[0]);
	}

	strcpy(address->street, pAddressStreet);

	while (pAddressCity) {
		countCity++;
		if (!isupper(pAddressCity[0]) && countCity < numOfWordsInCity)
			toupper(pAddressCity[0]);
		else if (!islower(pAddressCity[0]) && countCity == numOfWordsInCity)
			tolower(pAddressCity[0]);
	}
	strcpy(address->city, pAddressCity);
}