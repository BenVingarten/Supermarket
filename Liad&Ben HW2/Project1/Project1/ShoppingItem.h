#pragma once
#include "Product.h"

typedef struct
{
	char BarCode[BARCODE_LEN];
	float price;
	int amount;

}ShoppingItem;

int getShoppingItemByProduct(ShoppingItem* item, Product* p);
void printShoppingItem(ShoppingItem* item);
int getAmount(int* pAmount);