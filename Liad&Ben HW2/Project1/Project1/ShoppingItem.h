#pragma once
#include "Product.h"

typedef struct
{
	char BarCode[BARCODE_LEN];
	float price;
	int amount;

}ShoppingItem;

int initShoppingItem(Product *product, ShoppingItem *pShoppingItem, int amount);
void printShoppingItem(ShoppingItem* item);
void freeShoppingItem(ShoppingItem *pItem);
