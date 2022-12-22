#define _CRT_SECURE_NO_WARNINGS
#include "Address.h"
#include "ShoppingItem.h"
#include "Customer.h"
#include "ShoppingCart.h"
#include "SuperMarket.h"
#include <stdio.h>

void main()
{
	
	SuperMarket mar;
	initSuperMarket(&mar);
	printSuperMarket(&mar);
	printf("------------------\n");
	addProductToSuperMarket(&mar);
	printSuperMarket(&mar);
	printf("------------------\n");
	addProductToSuperMarket(&mar);
	printSuperMarket(&mar);
	
	
}
	



