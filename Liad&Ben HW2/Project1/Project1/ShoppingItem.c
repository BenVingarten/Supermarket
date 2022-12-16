#define _CRT_SECURE_NO_WARNINGS
#include "ShoppingItem.h";
#include <stdio.h>
#include <string.h>

void getAmountOfItem(int* amount)
{
	printf("enter How many items of this type would you like in the cart\n");
	scanf("%d", amount);

}
void getShoopingItem1(ShoppingItem* item, Product* p)
{
	strcpy(item->BarCode, p->barCode);
	item->price = p->price;
	getAmountOfItem(&item->amount);
	
}
void getShoopingItem2(ShoppingItem* item)
{
	getBarCode(item->BarCode);
	getPrice(&item->price);
	getAmountOfItem(&item->amount);
}

void printShoppingItem(ShoppingItem* item)
{
	printf("barcode: %s\nprice: %f\namount: %d\n", item->BarCode, item->price, item->amount);
}