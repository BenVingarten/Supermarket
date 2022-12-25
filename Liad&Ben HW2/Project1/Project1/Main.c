#define _CRT_SECURE_NO_WARNINGS
#include "SuperMarket.h"
#include <stdio.h>

void main()
{
	printf("please press ENTER to start!\n");
	SuperMarket market;
	int initMarket = initSuperMarket(&market);

	while (!initMarket)
	{
		printf("there was a problem allocating memory for supermarket, trying again\n");
		initMarket = initSuperMarket(&market);
	}
	
	int selection = 0;
	
	do
	{
		printf("\n\nPlease choose what you want to do: \n1) Print SuperMarket \n2) Add product\n");
		printf("3) Add customer \n4) Purchase \n5) Print customer cart \n6) Customer Pay\n");
		printf("7) Print all products of type \n8) EXIT\n");

		scanf("%d", &selection);
		switch (selection)
		{
			case 1: //Print SuperMarket
				printSuperMarket(&market);
				break;

			case 2:	//Add product
				addProductToSuperMarket(&market);
				break;

			case 3:	//Add customer 
				addCustomerToSuperMarket(&market);
				break;

			case 4:	//Purchase 
				purchase(&market);
				break;

			case 5:	//Print customer cart
				printCustomerCart(&market);
				break;

			case 6:	//Customer Pay
				customerPay(&market);
				break;
			
			case 7:	//Print all products of type
				printAllProductsByType(&market);
				break;

			case 8:	//EXIT
				exitSuperMarket(&market);
				break;

			default:
				printf("Invalid input\n");
			break;
		}


	} while (selection != 8);


	
}
	



