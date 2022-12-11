#include "Address.h"
#include "GeneralFunc.h"
#include <string.h>

#define MAX_ADDRESS 254

int getAddress(Address* address)
{/*
 getAdress - argument: Address* | return: NULL (0) if didn't get valid data, else return true (!0)
 get the address in format of street#number#city
 */
	char* del = "#";
	char insertedAdd[MAX_ADDRESS];
	int checkNumOfDel;

	do
	{
		printf("Please enter address by the next format: street#number#city \nMax Lenght is 254 & no spaces with the number");
		
		myGets(insertedAdd, MAX_ADDRESS);
		checkNumOfDel = countCharInString(insertedAdd, '#');

	} while (!insertedAdd && checkNumOfDel != 2);
	
	char* parts[3];
	char* temp = strtok(insertedAdd, del);
	int i = 0;
	while (temp)
	{
		if (strlen(temp) == 0)
			return 0;
		parts[i++] = temp;
		temp = strtok(NULL, del);
	}

	*address->street = *parts[0];
	address->homeNumber = *parts[1] - '0';
	return 1;
	
}