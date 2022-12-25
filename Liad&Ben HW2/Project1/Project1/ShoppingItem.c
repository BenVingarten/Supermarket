#define _CRT_SECURE_NO_WARNINGS
#include "Product.h"
#include "ShoppingItem.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>




void initShoppingItem(Product *product, ShoppingItem* pShoppingItem, int amount)
{
	/*
	initShoppingItem

	input: Product and Shopping item
	output: points the shoppingItem values to the product values
	*/

	strcpy(pShoppingItem->BarCode, product->barCode);
	pShoppingItem->price = product->price;
	pShoppingItem->amount = amount;
	

}
void printShoppingItem(ShoppingItem* item)
{
	printf("barcode: %s\nprice: %f\namount: %d\n", item->BarCode, item->price, item->amount);
}
void freeShoppingItem(ShoppingItem *pItem) 
{
	free(pItem);
}

