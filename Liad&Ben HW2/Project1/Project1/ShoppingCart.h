#pragma once
#include "ShoppingItem.h"

typedef struct
{
	int numOfDifferentItems;
	ShoppingItem** cart;

}ShoppingCart;


void initShoppingCart(ShoppingCart* shopCart);
ShoppingItem* isBarCodeInCart(ShoppingCart* shopCart, char* barCode);
int addItemToShoppingCart(ShoppingCart* shopCart, Product* p);
int getAmount(Product* p);
void addExistingShoppingItem(int amount, ShoppingItem* item, Product* p);
int addNewShoppingItem(ShoppingCart* shopCart, ShoppingItem* pItem, Product* p);
void freeShoppingCart(ShoppingCart *pShopCart);
void printShoppingCart(ShoppingCart *pShopCart);
