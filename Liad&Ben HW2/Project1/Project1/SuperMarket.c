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
	char* pName = createDynStr("SuperMarket's name");
	if (!pName)
		return 0;

	market->name = pName;
	
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
			printCustomer(market->allCustomers[i]);
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

void freeSuperMarket(SuperMarket* market)
{
	// free customers
	for (int i = 0; i < market->numOfCustomers; i++)
		freeCustomer(market->allCustomers[i]);
	free(market->allCustomers);

	//free products
	for (int i = 0; i < market->numOfProducts; i++)
		freeProduct(market->allProducts[i]);
	free(market->allProducts);
	
	//free address
	freeAddress(&market->address);

	//free name
	free(market->name);

	//free superMarket
	free(market);

}

void exitSuperMarket(SuperMarket * market)
{
	/*
	exit

	input: SuperMarket
	output: Can OR Cannot exit from program, (are al customers payed?)
	*/
	
	if (market->numOfCustomers)
		for (int i = 0; i < market->numOfCustomers; i++)
			if (market->allCustomers[i]->balance)
			{
				printf("Customer: %s didnt pay his balance. Please pay: \n", market->allCustomers[i]->name);
				while (market->allCustomers[i]->balance)
				{
					customerPay(market, market->allCustomers[i]);
					
					if (market->allCustomers[i]->balance)
						printf("There is more to pay: ");
				}
			}
	
	freeSuperMarket(market);

}


int addProductToSuperMarket(SuperMarket* market)
{
	// show user all products in superMarket
	getListOfProducts(market);

	int val;

	// get the user's choice, and check if his answer is valid.
	do {

		printf("To add a new product press 0\nTo add existing prodcut enter its number in list\n");
		scanf("%d", &val);
		getchar();

	} while (val < 0 || val > market->numOfProducts);
	
	// if the user wants to add new product
	if (!val)
	{
		Product* p = (Product*) malloc(sizeof(Product));
		if (!p)
			return 0;
		

		initProduct(p); 
		
		while (isProductBarcodeExists(market, p->barCode))
		{
			printf("there is already Barcode like this, try again\n");
			getBarCode(p->barCode);

		}
			
		 
		
		// allocate new memory for new product and add the new product.
		market->allProducts = (Product**)realloc(market->allProducts, (market->numOfProducts + 1) * sizeof(Product*));
		if (!market->allProducts)
			return 0;

		market->allProducts[market->numOfProducts++] = p;
	}
	// if the user wants to add an existing product.
	else
	{
		int amount;
		do {

			printf("what is the amount you want to add?\n");
			scanf("%d", &amount);
		} while (amount <= 0);
		
		market->allProducts[val - 1]->quantity += amount;
	}

	return 1;
}

void getListOfProducts(const SuperMarket* market)
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

int isProductBarcodeExists(SuperMarket* market, char* barCode)
{
	for (int i = 0; i < market->numOfProducts; i++)
	{
		if (!strcmp(market->allProducts[i]->barCode, barCode))
			return (i + 1);
	}
	return 0;
}

void printAllProductsByType(const SuperMarket* market)
{
	Type productType = getProductType();
	int count = 0;
	for (int i = 0; i < market->numOfProducts; i++)
	{
		if (!strcmp((char*)(market->allProducts[i]->productType), (char*)productType))
			printProduct(market->allProducts[i]);

		count++;
	}
	if (!count)
		printf("there are no products of this type in superMarket!\n");
}


int addCustomerToSuperMarket(SuperMarket* market)
{
	// show list of registerd customers for checks
	//getListOfCustomers(market);

	Customer* c = (Customer*)malloc(sizeof(Customer));
	if (!c)
		return 0;
	
	// init new customer and check if his name is already in registerd customers. 
	//if name exists free it before getting a new one

	if (!initCustomer(c))
	{
		printf("failed to allocate memory\n");
		return 0;
	}

	while (isCustomerExist(market, c->name))
	{
		free(c->name);
		if (!initCustomer(c))
		{
			printf("failed to allocate memory\n");
			return 0;
		}
	}
	
	market->allCustomers = (Customer**)realloc(market->allCustomers, (market->numOfCustomers + 1) * sizeof(Customer*));
	if (!market->allCustomers)
		return 0;

	market->allCustomers[market->numOfCustomers++] = c;

	return 1;
}

void getListOfCustomers(const SuperMarket* market)
{
	if (!market->allCustomers)
		printf("there are no customers\n");
	else
	{
		printf("there are %d registerd customers in superMarket\n", market->numOfCustomers);
		for (int i = 0; i < market->numOfCustomers; i++)
		{
			printf("%d) ", (i + 1));
			printCustomer(market->allCustomers[i]);
		}

	}
}

int isCustomerExist(const SuperMarket* market, char* name)
{
	for (int i = 0; i < market->numOfCustomers; i++)
	{
		if (!strcmp(market->allCustomers[i]->name, name))
			return (i+1);
	}
	return 0;
}

void printCustomerCart(const SuperMarket * market)
{
	/*
	printCustomerCart

	input: SuperMarket 
	output: print selected costumer cart
	*/

	Customer* currentCustomer = customerSelect(market);
	if (!currentCustomer)		//message printed from customerSelect
		return;

	printShoppingCart(currentCustomer->cart);
	
	
}

void customerPay(SuperMarket * market)
{
	/*
	customerPay

	input: SuperMarket
	output: pay selected costumer cart or some of it
	*/

	Customer* currentCustomer = customerSelect(market);
	if (!currentCustomer)		//message printed from customerSelect
		return;

	//get amount of money customer wants to pay
	float amount, customerBalance = currentCustomer->balance;
	printf("Customer current balance is %f, please intsert the total sum you want to pay", customerBalance);
	scanf("%f", &amount);
	while(amount < 0)
	{
		printf("Invalid amount of money, try again: ");
		scanf("%f", &amount);
	}

	customerBalance -= amount;
	
	if (customerBalance <= 0)
	{

		if (customerBalance < 0)
		{
			float change = 0 - customerBalance;
			customerBalance = 0;
			printf("Your change is %f ILS", change);
		}
			
		freeShoppingCart(currentCustomer->cart);
		//or currentCustomer->cart = NULL;
		
	}

	
	printf("Thanks for paying, your current balance is: %f", customerBalance);
	currentCustomer->balance = customerBalance;

	
}

Customer* customerSelect(const SuperMarket * market)
{
	if (!market->numOfCustomers)
	{
		printf("there are no Customers\n");
		return NULL;
	}
	
	getListOfCustomers(market);		//if we want to print all customers


	char* pName = getName("customer's name you want to choose");
	int customerNumber = isCustomerExist(market, pName); //customer number = customer index + 1
	while (!customerNumber)
	{
		printf("there is no customer with this name\n");
		pName = getName("customer's name you want to buy with");
		customerNumber = isCustomerExist(market, pName);
	}

	int customerIndex = customerNumber - 1;
	return market->allCustomers[customerIndex];
}


int purchase(SuperMarket* market)
{
	
	Customer* currentCustomer = customerSelect(market);
	if (!currentCustomer)		//message printed from customerSelect
		return 0;

	// if customer has no cart yet
	if (!currentCustomer->cart)
	{
		initEmptyCart(currentCustomer);
	}
	
	//show list of products
	getListOfProducts(market);

	int keepBuying; // variable that will decide if to keep buy or not.
	char* barcode; // getting user barcode's choice

	do
	{
		//get user choice if to keep buying or not
		do
		{
			printf("if you want to add product to your cart enter 1 else enter 0\n");
			scanf("%d", &keepBuying);

		} while(keepBuying < 0 || keepBuying > 1);
		
		if (keepBuying)
		{
			// get from user the product's barcode
			barcode = getName("the product's barcode you want to add,make sure it exists");
			int productNumber = isProductBarcodeExists(market, barcode);

			//while user selects non existing barcode keep getting new barcode
			while (!productNumber)
			{
				barcode = getName("the product's barcode you want to add,make sure it exists");
				productNumber = isProductBarcodeExists(market, barcode);
			}

			int productIndex = productNumber - 1;
			Product* p = market->allProducts[productIndex];

			if(!addItemToShoppingCart(currentCustomer->cart, p)) // adds new item to current customer's cart
				printf("couldn't add the item, try again if you want! ");
		}
		
	} while (keepBuying);

	currentCustomer->balance = getTotalSumOfCart(currentCustomer->cart);
	return 1;
}


	