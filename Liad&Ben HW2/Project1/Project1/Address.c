
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

		if (!insertedAdd || numOfDel != 2)
			return 0;
		


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
	char pStreet[MAX_LENGTH];
	char pCity[MAX_LENGTH];

	strcpy(pStreet, address->street);
	strcpy(pCity, address->city);

	int i = 0;
	while (pStreet[i] != '\0') 
	{
		if(isalpha(pStreet[i]))
			if(i == 0 && !isupper(pStreet[i]))
				pStreet[i] =  toupper(pStreet[i]);
			else if(i > 0 && isupper(pStreet[i]))
				pStreet[i] = tolower(pStreet[i]);
		i++;
	}

	i = 0;
	while (pCity[i] != '\0')
	{
		if (isalpha(pCity[i]))
			if (i == 0 && !isupper(pCity[i]))
				pCity[i] = toupper(pCity[i]);
			else if (i > 0 && !islower(pCity[i]))
				pCity[i] = tolower(pCity[i]);
		i++;
	}

	strcpy(address->street, pStreet);
	strcpy(address->city, pCity);

}