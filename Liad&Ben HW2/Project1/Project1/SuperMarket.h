#pragma once
#include "Address.h"
#include "Customer.h"
#include "Product.h"


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
void freeSuperMarket(SuperMarket* market);

int addProductToSuperMarket(SuperMarket* market);
void getListOfProducts(SuperMarket* market);
int isProductBarcodeExists(SuperMarket* market, char* barCode);
void printAllProductsByType(SuperMarket* market);

int addCustomerToSuperMarket(SuperMarket* market);
void getListOfCustomers(SuperMarket* market);
int isCustomerExist(SuperMarket* market, char* name);

int purchase(SuperMarket* market);


