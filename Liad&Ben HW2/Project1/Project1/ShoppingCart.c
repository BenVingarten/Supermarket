#include "ShoppingCart.h"
#include <stdlib.h>
#include <string.h>


void initShoppingCart(ShoppingCart* shopCart)
{
	shopCart->cart = NULL;
	shopCart->numOfDifferentItems = 0;
}

int addItemToShoppingCart(ShoppingCart* shopCart, Product* p)
{
	ShoppingItem* pItem; //(ShoppingItem*)malloc(sizeof(ShoppingItem));
	pItem = isShoppingItemInCart(shopCart, p->barCode);


	if (pItem)
	{
		
		

		
	}
	else
	{

	}

	
	return 1;
	

	
}


ShoppingItem* isBarCodeInCart(ShoppingCart* shopCart, char* barCode)
{
	for (int i = 0; i < shopCart->numOfDifferentItems; i++)
	{
		if(strcmp(shopCart->cart[i]->BarCode,barCode))
			return shopCart->cart[i];
	}
	return NULL;

}

int addExistingShoppingItem(ShoppingItem* item, Product* p)
{



}
int addNewShoppingItem(ShoppingCart* shopCart, ShoppingItem* pItem, Product* p)
{
	if (!getAmount(&pItem->amount, p))
		return 0;

	shopCart->cart = (ShoppingCart**)realloc(shopCart->cart, sizeof(ShoppingItem*) * (shopCart->numOfDifferentItems) + 1);
	if (!shopCart->cart)
		return 0;

	shopCart->cart[shopCart->numOfDifferentItems - 1] = pItem;
	shopCart->numOfDifferentItems++;
	return 1;
}