#pragma once


typedef struct
{
	int homeNumber;
	char* street;
	char* city;

} Address;

int initAddress(Address* address);
void fixAddressFormat(Address* address);
void freeAddress(Address* address);
void printAddress(const Address* address);