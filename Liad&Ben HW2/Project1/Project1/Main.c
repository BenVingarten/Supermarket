#define _CRT_SECURE_NO_WARNINGS
#include "Address.h"
#include "ShoppingItem.h"
#include "Customer.h"
#include "ShoppingCart.h"
#include "SuperMarket.h"
#include <stdio.h>

void main()
{
	Customer c1;
	if (!initCustomer(&c1))
		printf("Error!\n");

	printCustomer(&c1);
	
}
	



