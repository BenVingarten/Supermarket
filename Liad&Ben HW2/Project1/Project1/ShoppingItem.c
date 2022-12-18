#define _CRT_SECURE_NO_WARNINGS
#include "Product.h"
#include "ShoppingItem.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>





int getShoppingItemByProduct(ShoppingItem* item, Product* p)
{
	strcpy(item->BarCode, p->barCode);
	item->price = p->price;

	

}
void printShoppingItem(ShoppingItem* item)
{
	printf("barcode: %s\nprice: %f\namount: %d\n", item->BarCode, item->price, item->amount);
}

int getAmount(int* pAmount, Product* p)
{
	int val;
	printf("enter How many items of this type would you like in the cart\nin stock there are only %d", p->quantity);
	scanf("%d", &val);

	if (val > p->quantity || val < 0)
		return 0;

	return val;
	
}