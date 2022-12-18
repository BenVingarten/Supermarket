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
	//getProduct(&p2);
	//getProduct(&p3);

	printf("--------------------------------------(1)---------------------------");
	printProduct(&p1);
	printf("--------------------------------------(~1~)---------------------------");

	Customer c1;
	initCustomer(&c1);

	initShoppingCart(c1.cart);//-------not working need to initial 
	printf("--------------------------------------(2)---------------------------");
	printCustomer(&c1);
	printf("--------------------------------------(~2~)---------------------------");



}