#pragma once
#include "ShoppingItem.h"

typedef struct
{
	ShoppingItem** cart;
	int numOfDifferentItems;

}ShoppingCart;

void initShoppingCart(ShoppingCart* shopCart);
void printShoppingCart(ShoppingCart* shopCart);
int addItemToShoppingCart(ShoppingCart* shopCart, Product* p);
ShoppingItem* isBarCodeInCart(ShoppingCart* shopCart, char* barCode)
int addExistingShoppingItem(ShoppingItem* item, Product* p);
int addNewShoppingItem(ShoppingItem* item, Product* p);