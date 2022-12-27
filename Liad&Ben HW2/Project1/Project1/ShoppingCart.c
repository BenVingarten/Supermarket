#define _CRT_SECURE_NO_WARNINGS
#include "ShoppingCart.h"
#include <stdlib.h>
#include <string.h>
#include <stdio.h>


void initShoppingCart(ShoppingCart* pShopCart)
{
	pShopCart->items = NULL;
	pShopCart->numOfDifferentItems = 0;
}

void printShoppingCart(const ShoppingCart* pShopCart)
{
	if (!pShopCart)
	{
		printf("There are no items in cart\n");
		return;
	}
	
	printf("There are %d items in cart\n", pShopCart->numOfDifferentItems);

	for (int i = 0; i < pShopCart->numOfDifferentItems; i++)
	{
		printf("%d) ", (i + 1));
		printShoppingItem(pShopCart->items[i]);
		printf("\n");
	}
		
		
}

void freeShoppingCart(ShoppingCart *pShopCart) 
{
	/*
	freeShoppingCart

	input: Shopping cart
	output: free the space of shopping cart and whats inside (items)
	*/
	if (!pShopCart)
		return;

	for (int i = 0; i < pShopCart->numOfDifferentItems; i++)
	{
		freeShoppingItem(pShopCart->items[i]);
	}
		
	free(pShopCart);
	

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


	if (!pItem)	//if item is not in cart	
	{
		if(!addNewShoppingItem(pShopCart,p, amount)) 
		{
			freeShoppingItem(pItem);		//if couldn't find place for shopping item OR bigger shopping cart - free the new shopping item
			return 0;
		}
	}
	else
		addExistingShoppingItem(amount, pItem, p);
	
	return 1;

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

int addNewShoppingItem(ShoppingCart* ShopCart, Product* p, int amount)
{
	/*
	addNewShoppingItem

	input: Shopping cart, Shopping item and Product
	output: add the *NEW* item to the shopping cart (pItem pointing to new item outside the cart)
			**remember amount is in the new item amount and already been chacked**
	*/	

	// allocate new shopping item
	ShoppingItem* pItem = (ShoppingItem*)malloc(sizeof(ShoppingItem)); 
	if (!pItem)
		return 0;

	initShoppingItem(p, pItem, amount); 
		

	ShopCart->items = (ShoppingItem**)realloc(ShopCart->items, sizeof(ShoppingItem*) * ((ShopCart->numOfDifferentItems) + 1 ));
	if (!ShopCart->items)		//if not succeeded to fine place in memory
		return 0;

	ShopCart->items[ShopCart->numOfDifferentItems++] = pItem;	//if succeeded add to cart

	p->quantity -= pItem->amount; //update product quantity

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


float getTotalSumOfCart(const ShoppingCart* pShopCart)
{
	/*
	getTotalSumOfCart

	input: Shopping cart
	output: total sum of cart to pay
	*/
	
	if (!pShopCart)
	{
		printf("There are no items in cart\n");
		return 0;
	}

	float totalSum = 0;

	for (int i = 0; i < pShopCart->numOfDifferentItems; i++)
		totalSum += pShopCart->items[i]->price  * pShopCart->items[i]->amount;

	return totalSum;
}