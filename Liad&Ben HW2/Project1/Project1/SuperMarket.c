#define _CRT_SECURE_NO_WARNINGS
#include "SuperMarket.h"
#include <stdlib.h>

int initSuperMarket(SuperMarket* market)
{
	//init name
	char* str;
	str = createDynStr("SuperMarket's name");

	if (!str)
		return 0;

	market->name = (char*)malloc((strlen(str) + 1) * sizeof(char));

	if (!market->name)
		return 0;

	strcpy(market->name, str);
	
	//init address
	if (!initAddress(&market->address))
		return 0;

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
	printf("name: %s\naddress: %s\n", market->name, market->address);
	printf("there are %d registerd customers in SuperMarket\n", market->numOfCustomers);

	for (int i = 0; i < market->numOfCustomers; i++)
		printCustomer(&market->allCustomers[i]);

	printf("there are %d products in SuperMarket\n", market->numOfProducts);
	for (int i = 0; i < market->numOfProducts; i++)
		printProduct(&market->allProducts[i]);
}
