#pragma once
#include "Product.h"

typedef struct
{
	char BarCode[BARCODE_LEN];
	float price;
	int amount;

}ShoppingItem;

void getAmountOfItem(int* amount);
void getShoopingItem1(ShoppingItem* item, Product* p);
void getShoopingItem2(ShoppingItem* item);
void printShoppingItem(ShoppingItem* item);