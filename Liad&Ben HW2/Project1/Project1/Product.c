#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include "Product.h"
#include <ctype.h>
#include <string.h>
#include "GeneralFunc.h"

const char* typeTitles[eNOfTypes] = { "Shelf", "Frozen", "Fridge", "FruitVegtable", };

int isBarCodeValid(char* str)
{
	if (strlen(str) < (BARCODE_LEN - 1)) 
		return 0;
	

	int i = 0, digitCount = 0;

	while(str[i] != '\0')
	{
		if (!(isalpha(str[i])) && !(isdigit(str[i])))
			return 0;

		if (isalpha(str[i]) && !isupper(str[i]))
			return 0;

		if (isdigit(str[i]) && (i == 0 || i == BARCODE_LEN - 2))
			return 0;

		if (isdigit(str[i]))
			digitCount++;

		i++;
	}

	if (digitCount < 3 || digitCount > 5)
		return 0;

	return 1;
}


void getProduct(Product* product)
{
	char pName[NAME_LEN];
	do {
		printf("please enter product's name, up to %d characters\n", NAME_LEN - 1);
		 myGets(pName, NAME_LEN);

	} while (pName == NULL || !strlen(pName));

	strcpy(product->name, pName);

	
	char pBarCode[BARCODE_LEN];

	do {
		printf("please select a BarCode for the product\nThe barcode contains exactly %d characters\nThe first and last character must be alphabetic\nThe in between can include digits as well\n", BARCODE_LEN - 1);
		myGets(pBarCode, BARCODE_LEN);

	} while (pName == NULL || !strlen(pName));

	strcpy(product->barCode, pBarCode);

	product->productType = getProductType();

	printf("please enter the product's price\n");
	scanf("%f", &product->price);

	printf("please enter the product's quantity in stock\n");
	scanf("%d", &product->quantity);

}
Type getProductType()
{
	int val;
	do {
		printf("please enter product's type\n");

		for (int i = 0; i < eNOfTypes; i++) {
			printf("%d for %s\n", i, typeTitles[i]);
		}

		scanf("%d", &val);
	} while (val < 0 || val >= eNOfTypes);

	return (Type)val;
}

void printProduct(Product* product)
{
	printf("name: %s\nbarcode: %s\ntype: %s\nprice: %f\nquantity: %d\n", product->name, product->barCode, typeTitles[product->productType], product->price, product->quantity);
}
