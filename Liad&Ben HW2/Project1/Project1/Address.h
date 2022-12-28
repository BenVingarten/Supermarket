#pragma once


typedef struct
{
	int homeNumber;
	char* street;
	char* city;

} Address;

int initAddress(Address* address);
int fixAddressFormat(char* street, char* city);
void freeAddress(Address* address);
void printAddress(const Address* address);