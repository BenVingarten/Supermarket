#pragma once
#define MAX_LENGHT 100

typedef struct
{
	int homeNumber;
	char street[MAX_LENGHT];
	char city[MAX_LENGHT];
} Address;

int getAddress(Address* address);