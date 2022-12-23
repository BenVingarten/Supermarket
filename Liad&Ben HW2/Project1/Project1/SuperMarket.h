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
int addProductToSuperMarket(SuperMarket* market);
int isProductBarcodeExists(SuperMarket* market, char* barCode);

int addCustomerToSuperMarket(SuperMarket* market);
int purchase(SuperMarket* market);
void printAllProductsByType(SuperMarket* market);
void getListOfProducts(SuperMarket* market);
void freeSuperMarket(SuperMarket* market);
void getListOfCustomers(SuperMarket* market);
int isCustomerExist(SuperMarket* market, char* name);


