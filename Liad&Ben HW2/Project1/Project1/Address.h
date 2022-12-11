#pragma once

#define MAX_LENGTH 100
#define MAX_ADDRESS 254

typedef struct
{
	int homeNumber;
	char* street;
	char* city;

} Address;

int initAddress(Address* address);
int getAddress(Address* address);
void fixAddressFormat(Address* address);
void freeAddress(Address* address);
void printAddress(const Address* address);