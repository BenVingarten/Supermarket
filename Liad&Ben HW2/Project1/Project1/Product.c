#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include "Product.h"
#include <ctype.h>
#include <string.h>
#include "GeneralFunc.h"
#include "SuperMarket.h"
#include <stdlib.h>



const char* typeTitles[eNOfTypes] = { "Shelf", "Frozen", "Fridge", "FruitVegtable"};

int isBarCodeValid(char* str)
{
	if (strlen(str) != (BARCODE_LEN -1))
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
void initProduct(Product* product)
{
	getProductName(product->name);
	product->productType = getProductType();
	getPrice(&product->price);
	getQuantity(&product->quantity);
	getBarCode(product->barCode);
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
			getchar();

	} while (val < 0 || val >= eNOfTypes);

	return (Type)val;
}
void printProduct(const Product* product)
{
	printf("name: %s | barcode: %s | type: %s | price: %f | quantity: %d\n", product->name, product->barCode, typeTitles[product->productType], product->price, product->quantity);
}
void getBarCode(char* pBar)
{
	char temp[MAX_LENGTH];

	do {
		printf("please select a BarCode for the product \nmake sure it's valid and different from existing Barcodes\n");
		scanf("%[^\n]s", temp);
		getchar();

	} while (!(isBarCodeValid(temp)));

	strcpy(pBar, temp);
}
void getPrice(float* price)
{
	float val;
	do{

		printf("please enter valid product's price\n");
		scanf("%f", &val);
		getchar();

	} while (val <= 0);
	
	*price = val;
	
}
void getQuantity(int* quantity)
{
	int val;
	do {

		printf("please enter valid product's quantity\n");
		scanf("%d", &val);
		getchar();
	} while (val <= 0);

	*quantity = val;
	
}
void getProductName(char* pName)
{
	char temp[MAX_LENGTH];

	do {
		printf("please enter product's name, up to %d characters\n", NAME_LEN - 1);
		scanf("%[^\n]s", temp);
		getchar();

	} while (!isNameValid(temp,NAME_LEN - 1));

	strcpy(pName, temp);
	
}

void freeProduct(Product * p)
{
	/*
	freeProduct

	input: Product
	output: free the space of Product elements
	*/

	free(p);
}

