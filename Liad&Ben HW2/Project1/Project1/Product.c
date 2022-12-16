#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include "Product.h"
#include <ctype.h>
#include <string.h>
#include "GeneralFunc.h"

const char* typeTitles[eNOfTypes] = { "Shelf", "Frozen", "Fridge", "FruitVegtable", };

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
void getProduct(Product* product)
{
	getProductName(product->name);
	getBarCode(product->barCode);
	product->productType = getProductType();
	getPrice(&product->price);
	getQuantity(&product->quantity);
	

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
void getBarCode(char* pBar)
{
	char temp[10];

	do {
		printf("please select a BarCode for the product\nThe barcode contains exactly %d characters\nThe first and last character must be alphabetic\nThe in between can include digits as well\n", BARCODE_LEN - 1);

		scanf("%[^\n]s", temp);
		getchar();

	} while (!(isBarCodeValid(temp)));

	strcpy(pBar, temp);
}
void getPrice(float* price)
{
	printf("please enter the product's price\n");
	scanf("%f", price);
}
void getQuantity(int* quantity)
{
	printf("please enter the product's quantity in stock\n");
	scanf("%d", quantity);
}
void getProductName(char* pName)
{
	char temp[25];

	do {
		printf("please enter product's name, up to %d characters\n", NAME_LEN - 1);
		scanf("%[^\n]s", temp);
		getchar();

	} while (!isNameValid(temp));

	strcpy(pName, temp);
	
}
int isNameValid(char* str)
{
	if (!strlen(str) || strlen(str) > (NAME_LEN - 1))
		return 0;
	return 1;
}
