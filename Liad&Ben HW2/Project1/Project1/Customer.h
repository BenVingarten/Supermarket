#pragma once
#include "ShoppingCart.h"

typedef struct
{
	char* name;
	ShoppingCart* cart;
	float balance;

}Customer;

int initCustomer(Customer* customer);
void printCustomer(const Customer* customer);
void freeCustomer(Customer* customer);
int initEmptyCart(Customer* customer);

