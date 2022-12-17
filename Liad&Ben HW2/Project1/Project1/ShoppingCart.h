#pragma once
#include "ShoppingItem.h"
#define MAX_CART_LEN 50

typedef struct
{
	ShoppingItem** cart;
	int numOfDifferentItems;

}ShoppingCart;

void initShoppingCart(ShoppingCart* shopCart);
void printShoppingCart(ShoppingCart* shopCart);
void getShoppingCart(ShoppingCart* shopCart);
