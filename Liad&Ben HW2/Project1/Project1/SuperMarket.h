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
void exitSuperMarket(SuperMarket* market);

void addProductToSuperMarket(SuperMarket* market);
void getListOfProducts(const SuperMarket* market);
int isProductBarcodeExists(SuperMarket* market, char* barCode);
void printAllProductsByType(const SuperMarket* market);

void addCustomerToSuperMarket(SuperMarket* market);
void getListOfCustomers(const SuperMarket* market);
void getListOfCustomerWhoNeedsToPay(SuperMarket* market);
int isCustomerExist(const SuperMarket* market, char* name);
void printCustomerCart(const SuperMarket* market);

void customerPay(SuperMarket* market);
Customer* customerSelect(const SuperMarket* market);

void purchase(SuperMarket* market);
//int NotEverybodyPaid(SuperMarket* market);


