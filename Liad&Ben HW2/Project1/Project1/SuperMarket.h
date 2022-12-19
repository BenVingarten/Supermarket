#pragma once
#include "Address.h"
#include "Customer.h"

typedef struct
{
	char* name;
	Address address;
	Customer** allCustomers;
	int numOfCustomers;
	Product** allProducts;
	int numOfProducts;

}SuperMarket;

int initSuperMarket(SuperMarket* market);
void printSuperMarket(const SuperMarket* market);
int addProductToSuperMarket(SuperMarket* market);
int addCustomerToSuperMarket(SuperMarket* market);
int purchase(SuperMarket* market);
void printAllProductsByType(SuperMarket* market);


