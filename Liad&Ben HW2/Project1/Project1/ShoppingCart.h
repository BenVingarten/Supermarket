#pragma once
#include "ShoppingItem.h"

typedef struct
{
	ShoppingItem** items;
	int numOfDifferentItems;
	
}ShoppingCart;


void initShoppingCart(ShoppingCart* shopCart);
void printShoppingCart(const  ShoppingCart *pShopCart);
void freeShoppingCart(ShoppingCart *pShopCart);

int addItemToShoppingCart(ShoppingCart* shopCart, Product* p);
void addExistingShoppingItem(int amount, ShoppingItem* item, Product* p);
int addNewShoppingItem(ShoppingCart* shopCart, ShoppingItem* pItem, Product* p);
ShoppingItem* findBarCodeInCart(ShoppingCart* shopCart, char* barCode);
int getAmount(Product* p);

float getTotalSumOfCart(const ShoppingCart* pShopCart);
