#define _CRT_SECURE_NO_WARNINGS
#include "Product.h"
#include "ShoppingItem.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>




int initShoppingItem(Product *product, ShoppingItem *pShoppingItem, int amount)
{
	/*
	initShoppingItem

	input: Product and Shopping item
	output: points the shoppingItem values to the product values
	*/
	pShoppingItem = (ShoppingItem*)malloc(sizeof(ShoppingItem));
	if (!pShoppingItem)
		return 0;
	
	strcpy(pShoppingItem->BarCode, product->barCode);
	pShoppingItem->price = product->price;
	pShoppingItem->amount = amount;
	
	return 1;
}

void printShoppingItem(ShoppingItem* item)
{
	printf("barcode: %s\nprice: %f\namount: %d\n", item->BarCode, item->price, item->amount);
}

void freeShoppingItem(ShoppingItem *pItem) 
{
	free(pItem);
}

