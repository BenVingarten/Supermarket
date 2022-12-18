#define _CRT_SECURE_NO_WARNINGS
#include "Customer.h"
#include "GeneralFunc.h"
#include <stdlib.h>
#include <string.h>
#include <stdio.h>

int initCustomer(Customer* customer)
{
	/*
	initCustomer

	input: Customer
	output: 0 if failed creating, 1 if created cutomer
	*/

	

	char temp[MAX_LENGTH];

	do {
		printf("please enter customer's name, up to %d characters\n", MAX_LENGTH - 1);
		scanf("%[^\n]s", temp);
		getchar();

	} while (!strlen(temp));


	customer->name = (char*)malloc((strlen(temp) + 1) * sizeof(char));
	strcpy(customer->name, temp);
	
	customer->cart = NULL;
	
	
	return 1;
}

void printCustomer(const Customer* customer)
{
	printf("customer's name: %s\n", customer->name);
	printShoppingCart(customer->cart);
}


void freeCustomer(Customer* customer)
{
	/*
	freeCustomer

	input: Customer
	output: free the space of shopping cart (which free the items in it) and name
	*/


	freeShoppingCart(customer->cart);
	free(customer->name);
}