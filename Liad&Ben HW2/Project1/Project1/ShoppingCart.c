#define _CRT_SECURE_NO_WARNINGS
#include "ShoppingCart.h"
#include <stdlib.h>
#include <string.h>
#include <stdio.h>


void initShoppingCart(ShoppingCart* pShopCart)
{
	ShoppingCart shopCart;
	pShopCart = &shopCart;
	pShopCart->items = NULL;
	pShopCart->numOfDifferentItems = 0;
}

int addItemToShoppingCart(ShoppingCart* pShopCart, Product* p)
{
	/*
	addItemToShoppingCart
	
	input: Shopping cart and Product
	output: add the product to the shopping cart (considering if its already in or not)
	*/

	int amount = getAmount(p);
	if (!amount)	//if asked for more than available
		return 0;

	//check if item is in already in cart by barcode
	ShoppingItem* pItem; 
	pItem = findBarCodeInCart(pShopCart, p->barCode);


	if (pItem)	//if item is already in cart
		addExistingShoppingItem(amount ,pItem, p);

	else
	{
		if (!initShoppingItem(p, pItem, amount) || !addNewShoppingItem(pShopCart, pItem, p)) //create pItem
		{
			freeShoppingItem(pItem);		//if couldn't find place for shopping item OR bigger shopping cart - free the new shopping item
			return 0;
		}
	}

	return 1;

}


ShoppingItem* findBarCodeInCart(ShoppingCart* pShopCart, char* barCode)
{
	/*
	isBarCodeInCart

	input: Shopping cart and Barcode
	output: if the item already added - return the item | else - NULL
	*/

	for (int i = 0; i < pShopCart->numOfDifferentItems; i++)
	{
		if(!strcmp(pShopCart->items[i]->BarCode,barCode))
			return pShopCart->items[i];
	}
	return NULL;

}

void addExistingShoppingItem(int amount, ShoppingItem* pItem, Product* p)
{
	/*
	addExistingShoppingItem

	input: Amount, Shopping item and Product
	output: add the item to the shopping cart (pItem pointing to item inside the cart)
			**remember amount is already been chacked**
	*/

	pItem->amount += amount;
	p->quantity -= amount;


}

int addNewShoppingItem(ShoppingCart* pShopCart, ShoppingItem *pItem, Product* p)
{
	/*
	addNewShoppingItem

	input: Shopping cart, Shopping item and Product
	output: add the *NEW* item to the shopping cart (pItem pointing to new item outside the cart)
			**remember amount is in the new item amount and already been chacked**
	*/


	pShopCart->items = (ShoppingItem**)realloc(pShopCart->items, sizeof(ShoppingItem*) * ((pShopCart->numOfDifferentItems) + 1 ));
	if (!pShopCart->items)		//if not succeeded to fine place in memory
		return 0;

	pShopCart->items[++pShopCart->numOfDifferentItems] = pItem;	//if succeeded add to cart

	p->quantity -= pItem->amount;

	return 1;
}

int getAmount(Product* p)
{
	/*
	getAmount

	input: Product
	output: return the amount wanted from the product (NULL if more then product quantity)
	*/

	int val;
	printf("enter How many items of this type would you like in the cart\nin stock there are only %d\n", p->quantity);
	scanf("%d", &val);

	if (val > p->quantity || val < 0)
		return 0;

	return val;

}

void freeShoppingCart(ShoppingCart *pShopCart) 
{
	/*
	freeShoppingCart

	input: Shopping cart
	output: free the space of shopping cart and whats inside (items)
	*/

	for (int i = 0; i < pShopCart->numOfDifferentItems; i++)
		freeShoppingItem(pShopCart->items[i]);

	free(pShopCart);

}

void printShoppingCart(ShoppingCart* pShopCart)
{
	if (pShopCart->numOfDifferentItems)
	{
		printf("There are %d items in cart\n", pShopCart->numOfDifferentItems);

		for (int i = 0; i < pShopCart->numOfDifferentItems; i++)
			printShoppingItem(pShopCart->items[i]);

		printf("\n");

	}
	else
	{
		printf("There are 0 items in cart");
	}
	
	
}