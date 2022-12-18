#define _CRT_SECURE_NO_WARNINGS
#include "Address.h"
#include "ShoppingItem.h"
#include "Customer.h"
#include "ShoppingCart.h"
#include <stdio.h>

void main()
{
	Product p1, p2, p3;
	getProduct(&p1);

	printf("--------------------------------------(1)---------------------------\n");
	printProduct(&p1);
	printf("--------------------------------------(~1~)---------------------------\n");

	Customer c1;
	if (!initCustomer(&c1))
		printf("Error!");

	printCustomer(&c1);
	

	
	
		
	
	
	
}
	



