#define _CRT_SECURE_NO_WARNINGS
#include "Customer.h"
#include "GeneralFunc.h"
#include <stdlib.h>
#include <string.h>
#include <stdio.h>

int initCustomer(Customer* customer)
{
	char* pName = createDynStr("customer's name");
	if (!strlen(pName))
		return 0;

	strcpy(customer->name, pName);
	customer->cart = NULL;
	return 1;
}
void printCustomer(const Customer* customer)
{
	printf("customer's name: %s\n", customer->name);
	//printShoppingCart(customer->cart);
}
void freeCustomer(Customer* customer)
{
	free(customer->name);
	free(customer->cart);
}