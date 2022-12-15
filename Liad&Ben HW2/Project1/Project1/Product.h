#pragma once
#define NAME_LEN 21
#define BARCODE_LEN 8


typedef enum { eShelf, eFrozen, eFridge, eFruitVegtable, eNOfTypes } Type;
const char* typeTitles[eNOfTypes];


typedef struct
{
	char name[NAME_LEN];
	char barCode[BARCODE_LEN];
	Type productType;
	float price;
	int quantity;

}Product;

void getProduct(Product* product);
void printProduct(Product* product);
int isBarCodeValid(char* str);
Type getProductType();

