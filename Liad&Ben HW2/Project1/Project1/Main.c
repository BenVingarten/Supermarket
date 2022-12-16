#define _CRT_SECURE_NO_WARNINGS
#include "Product.h"
#include "ShoppingItem.h"


void main()
{
	Product p;
	getProduct(&p);
	printProduct(&p);
	ShoppingItem s;
	getShoopingItem1(&s, &p);
	printShoppingItem(&s);

	
}