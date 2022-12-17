#pragma once
#include "ShoppingItem.h"

typedef struct
{
	ShoppingItem** cart;
	int numOfDifferentItems;

}ShoppingCart;