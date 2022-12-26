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
	printf("name: %s Address: ", market->name);
	printAddress(&market->address);

	printf("\n");

	getListOfCustomers(market);
	
	getListOfProducts(market);
	
}
void freeSuperMarket(SuperMarket* market)
{
	// free customers
	for (int i = 0; i < market->numOfCustomers; i++)
	{
		freeCustomer(market->allCustomers[i]);
		free(market->allCustomers[i]);
	}

	free(market->allCustomers);

	//free products
	for (int i = 0; i < market->numOfProducts; i++)
	{
		freeProduct(market->allProducts[i]);
	}

	free(market->allProducts);
	
	//free address
	freeAddress(&market->address);

	//free name
	free(market->name);

}
void exitSuperMarket(SuperMarket * market)
{
	/*
	exit

	input: SuperMarket
	output: exit from program after all cutomers have paid
	*/
	
	if (market->numOfCustomers > 0) //check if there are customers.
	{
		
		getListOfCustomers(market);
		getListOfCustomerWhoNeedsToPay(market);
	}
	freeSuperMarket(market);

	/*
		for (int i = 0; i < market->numOfCustomers; i++)
			if (market->allCustomers[i]->balance)
			{
				printf("Customer: %s didnt pay his balance. Please pay:\n", market->allCustomers[i]->name);
				while (market->allCustomers[i]->balance)
				{
					customerPay(market, market->allCustomers[i]);
					
					if (market->allCustomers[i]->balance)
						printf("There is more to pay:\n");
				}
			}
	*/
	

}


void addProductToSuperMarket(SuperMarket* market)
{
	// show user all products in superMarket
	getListOfProducts(market);

	int val;

	// get the user's choice, and check if his answer is valid.
	do {

		printf("1) To add a new product press 0 \n2) To add existing prodcut enter its number in list\n");
		scanf("%d", &val);
		getchar();

	} while (val < 0 || val > market->numOfProducts);
	
	// if the user wants to add new product
	if (!val)
	{
		Product* p = (Product*) malloc(sizeof(Product));
		if (!p) 
		{
			printf("Failed to add prouct, try again\n");
			return;
		}
		

		initProduct(p); 
		
		while (isProductBarcodeExists(market, p->barCode))
		{
			printf("There is already Barcode like this, try again\n");
			getBarCode(p->barCode);
			
		}
			
		 
		
		// allocate new memory for new product and add the new product.
		market->allProducts = (Product**)realloc(market->allProducts, (market->numOfProducts + 1) * sizeof(Product*));
		if (!market->allProducts)
		{
			printf("failed to add prouct, try again\n");
			return;
		}
			

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

	
}
void getListOfProducts(const SuperMarket* market)
{
	if (!market->allProducts)
		printf("There are no products\n");
	else
	{
		printf("There are %d products in SuperMarket\n", market->numOfProducts);
		printf("\tname\t\tbarcode\t\ttype\t\tprice\t\tquantity\n");
		printf("------------------------------------------------------------------------------------------\n");
		for (int i = 0; i < market->numOfProducts; i++)
			printProduct(market->allProducts[i]);
			
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
		if (((int)(market->allProducts[i]->productType) == (int)productType))
		{
			printProduct(market->allProducts[i]);
			count++;
		}
	}
	if (!count)
		printf("there are no products of this type in superMarket!\n");
}

void addCustomerToSuperMarket(SuperMarket* market)
{
	// show list of registerd customers for checks
	//getListOfCustomers(market);

	Customer* c = (Customer*)malloc(sizeof(Customer));
	if (!c)
	{
		printf("Failed to add Customer, try again\n");
		return;
	}
	
	// init new customer and check if his name is already in registerd customers. 
	//if name exists free it before getting a new one

	if (!initCustomer(c))
	{
		printf("Failed to add Customer, try again\n");
		return;
	}

	while (isCustomerExist(market, c->name))
	{
		free(c->name);
		if (!initCustomer(c))
		{
			printf("Failed to add Customer, try again\n");
			return;
		}
	}
	
	market->allCustomers = (Customer**)realloc(market->allCustomers, (market->numOfCustomers + 1) * sizeof(Customer*));
	if (!market->allCustomers)
	{
		printf("Failed to add Customer, try again\n");
		return;
	}

	market->allCustomers[market->numOfCustomers++] = c;

}
void getListOfCustomers(const SuperMarket* market)
{
	if (!market->allCustomers)
		printf("There are no customers\n");
	else
	{
		printf("There are %d registerd customers in superMarket\n", market->numOfCustomers);
		for (int i = 0; i < market->numOfCustomers; i++)
		{
			printf("%d) ", (i + 1));
			printf("%s\t| Balance: %f\n", market->allCustomers[i]->name, market->allCustomers[i]->balance);
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
void customerPay(SuperMarket* market)
{
	/*
	customerPay

	input: SuperMarket
	output: pay selected costumer cart or some of it
	*/
	Customer* currentCustomer;

	currentCustomer = customerSelect(market);
	if (!currentCustomer)		//message printed from customerSelect
		return;
	
	if (!currentCustomer->balance)
	{
		printf("customer dont need to pay\n");
		return;
	}

	//get amount of money customer wants to pay
	float amount, customerBalance = currentCustomer->balance;
	

	while (customerBalance > 0)
	{
		printf("Customer current balance is %f, please insert the balance to pay\n", customerBalance);
		scanf("%f", &amount);
		while (amount < 0)
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
				printf("Your change is %f ILS, ", change);
			}

			freeShoppingCart(currentCustomer->cart);
			currentCustomer->cart = NULL;
		}
	}
	
	printf("Thanks for paying, your current balance is: %f\n", customerBalance);
	currentCustomer->balance = customerBalance;
}
Customer* customerSelect(const SuperMarket * market)
{
	if (!market->numOfCustomers)
	{
		printf("there are no Customers\n");
		return NULL;
	}
	
	getListOfCustomers(market);	
	
	char* pName = getName("customer's name");
	int customerNumber = isCustomerExist(market, pName); //customer number = customer index + 1
	while (!customerNumber)
	{
		printf("there is no customer with this name\n");
		pName = getName("customer's name you want to buy/pay with");
		customerNumber = isCustomerExist(market, pName);
	}

	int customerIndex = customerNumber - 1;
	return market->allCustomers[customerIndex];
}
void getListOfCustomerWhoNeedsToPay(SuperMarket* market)
{
	for (int i = 0; i < market->numOfCustomers; i++)
	{
		if (market->allCustomers[i]->balance > 0)
		{
			printf("%f ILS recived from %s. Balance cleared !\n", market->allCustomers[i]->balance, market->allCustomers[i]->name );
		}
	}
}

void purchase(SuperMarket* market)
{
	if (!market->numOfProducts)
	{
		printf("\nThere are no products in superMarket\n");
		return;
	}
	
	Customer* currentCustomer = customerSelect(market);

	if (!currentCustomer)		//message printed from customerSelect
		return;


	// if customer has no cart yet
	if (!currentCustomer->cart)
	{
		initEmptyCart(currentCustomer);
	}
	
	

	int keepBuying; // variable that will decide if to keep buy or not.
	char* barcode; // getting user barcode's choice

	do
	{
		//get user choice if to keep buying or not

		//show list of products
		getListOfProducts(market);
		
		
		printf("press: \n1 - To add product to your cart enter \nAnything else to exit\n");
		scanf("%d", &keepBuying);
		getchar();
		keepBuying = (keepBuying == 1);

		if (keepBuying)
		{
			
			// get from user the product's barcode
			int productNumber;
			do
			{
				barcode = getName("the product's barcode you want to add, make sure it exists");
				productNumber = isProductBarcodeExists(market, barcode);
			} while (!productNumber);

			

			int productIndex = productNumber - 1;
			Product* p = market->allProducts[productIndex];
			if (!p->quantity)
			{
				printf("\t~Product out of stock!~\n");
				return;
			}

			if(!addItemToShoppingCart(currentCustomer->cart, p)) // adds new item to current customer's cart
				printf("\t~Couldn't add the item, try again if you want~\n");
		}
		
	} while (keepBuying);

	currentCustomer->balance = getTotalSumOfCart(currentCustomer->cart);
}

/*int NotEverybodyPaid(SuperMarket* market)
{
	for (int i = 0; i < market->numOfCustomers; i++)
	{
		if (market->allCustomers[i]->balance > 0)
		{
			return 1;
		}
	}

	return 0;
}*/
