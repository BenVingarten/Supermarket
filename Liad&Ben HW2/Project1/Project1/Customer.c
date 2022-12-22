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
	
	if (!getDynamicName(customer->name, "customer's name"))
		return 0;
	
	customer->cart = NULL; //customer hasnt started purchase yet, so there is no cart now.
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
int initEmptyCart(Customer* customer)
{
	ShoppingCart* pShopCart = (ShoppingCart*)malloc(sizeof(ShoppingCart));
	if (!pShopCart)
		return 0;

	customer->cart = pShopCart;
	initShoppingCart(customer->cart);
	return 1;
}
	