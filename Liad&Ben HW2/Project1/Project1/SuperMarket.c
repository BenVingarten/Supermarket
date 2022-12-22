#define _CRT_SECURE_NO_WARNINGS
#include "SuperMarket.h"
#include <stdlib.h>
#include "GeneralFunc.h"
#include <stdio.h>
#include <string.h>
#include "Product.h"
#include "Customer.h"


int initSuperMarket(SuperMarket* market)
{
	//init name
	char temp[MAX_LENGTH];

	strcpy(temp, getName("SuperMarket's name"));
	market->name = (char*)malloc((strlen(temp) + 1) * sizeof(char));

	if (!market->name)
		return 0;

	strcpy(market->name, temp);
	
	//init address
	int address = initAddress(&market->address);
	while (!address)
	{
		printf("inserted address not valid, try again\n");
		address = initAddress(&market->address);
	}
		
	//init customers
	market->allCustomers = NULL;
	market->numOfCustomers = 0;

	//init products
	market->allProducts = NULL;
	market->numOfProducts = 0;

	return 1;


}
void printSuperMarket(const SuperMarket* market)
{
	printf("name: %s\naddress: ", market->name);
	printAddress(&market->address);

	if (!market->allCustomers)
		printf("there are no customers in superMarket\n");
	else
	{
		printf("there are %d registerd customers in SuperMarket\n", market->numOfCustomers);
		for (int i = 0; i < market->numOfCustomers; i++)
			printCustomer(&market->allCustomers[i]);
	}
	
	if(!market->allProducts)
		printf("there are no products in superMarket\n");
	else
	{
		printf("there are %d products in SuperMarket\n", market->numOfProducts);
		for (int i = 0; i < market->numOfProducts; i++)
			printProduct(market->allProducts[i]);
	}
	
}
int addProductToSuperMarket(SuperMarket* market)
{
	getListOfProducts(market);

	int val;

	do {

		printf("To add a new product press 0\nTo add existing prodcut enter its number in list\n");
		scanf("%d", &val);
		getchar();

	} while (val < 0 || val > market->numOfProducts);
	
	if (!val)
	{
		Product* p = (Product*) malloc(sizeof(Product));
		initProduct(p);

		market->allProducts = (Product**)realloc(market->allProducts, (market->numOfProducts + 1) * sizeof(Product*));
		if (!market->allProducts)
			return 0;

		market->allProducts[market->numOfProducts++] = p;

	}
	else
	{
		int amount;
		do {

			printf("what is the amount you want to add?\n");
			scanf("%d", &amount);
		} while (amount <= 0);
		
		market->allProducts[val - 1]->quantity += amount;
	}

}
int checkIfProductExists(SuperMarket* market, char* barCode)
{
	for (int i = 0; i < market->numOfProducts; i++)
	{
		if (strcmp(market->allProducts[i]->barCode, barCode))
			return 1;
	}
	return 0;
}
void getListOfProducts(SuperMarket* market)
{
	if (!market->allProducts)
		printf("there are no products\n");
	else
	{
		printf("there are %d products in superMarket\n", market->numOfProducts);
		for (int i = 0; i < market->numOfProducts; i++)
		{
			printf("%d) ", (i + 1));
			printProduct(market->allProducts[i]);
		}
			
	}
	
		
	
	


}