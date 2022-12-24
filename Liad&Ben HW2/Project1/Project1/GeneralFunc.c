#define _CRT_SECURE_NO_WARNINGS
#include <string.h>
#include <stdio.h>
#include "Address.h"
#include "GeneralFunc.h"
#include <ctype.h>
#include <stdlib.h>



char* myGets(char* buf, int size)
{
	if (buf != NULL && size > 0)
	{
		if (fgets(buf, size, stdin))
		{
			buf[strcspn(buf, "\n")] = '\0';
			return buf;
		}
		*buf = '\0';
	}
	return NULL;
	
}
int countCharInString(const char* str, char c)
{
	int counter = 0;
	for(int i = 0; i < (int)strlen(str); i++)
		if (str[i] == c)
			counter++;

	return counter;

}
void fixUpperAndLowerCase(char* str)
{
	int i = 0;
	while (str[i] != '\0')
	{
		if (isalpha(str[i]))
			if (i == 0 && !isupper(str[i]))
				str[i] = toupper(str[i]);
			else if (i > 0 && isupper(str[i]))
				str[i] = tolower(str[i]);
		i++;
	}
}
int isNameValid(char* str, int limit)
{
	if (!strlen(str) || (int)strlen(str) > limit)
		return 0;
	return 1;
}
char* getName(char * msg)
{
	char* str = malloc(sizeof(char) * MAX_LENGTH);
	getchar();
	do {
		printf("enter %s\n", msg);
		scanf("%[^\n]s", str);
		getchar();

	} while (!isNameValid(str, MAX_LENGTH - 1));
	
	return str;
}
char* createDynStr(const char* msg)
{
	char* str;
	char temp[MAX_LENGTH];
	getchar();
	do {

		printf("Enter %s:\n", msg);
		scanf("%[^\n]s", temp);
		getchar();

	} while (!isNameValid(temp,MAX_LENGTH - 1));

	str = (char*)malloc((strlen(temp) + 1) * sizeof(char));
	if (!str)
		return NULL;

	strcpy(str, temp);
	return str;
}



