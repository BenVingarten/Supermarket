#include "ShoppingCart.h"


int initShoppingCart(ShoppingCart* shopCart)
{
	shopCart->cart = (ShoppingItem**)malloc(sizeof(ShoppingItem*) * MAX_CART_LEN);
	if (!shopCart->cart)
		return 0;

	shopCart->numOfDifferentItems = 0;
	return 1;
}

void getShoppingCart(ShoppingCart* shopCart)
{

}
