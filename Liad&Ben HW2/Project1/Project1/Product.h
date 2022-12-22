#pragma once
#define NAME_LEN 21 // 20 characters + '\0'
#define BARCODE_LEN 8 // 7 characters + '\0' 


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

void initProduct(Product* product);
void getBarCode(char* pBar);
void getProductName(char* pName);
int getPrice(float* price);
int getQuantity(int* quantity);
void printProduct(const Product* product);
int isBarCodeValid(char* str);
Type getProductType();

