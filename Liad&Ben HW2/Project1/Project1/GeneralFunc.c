#define _CRT_SECURE_NO_WARNINGS
#include <string.h>
#include <stdio.h>
#include "Address.h"
#include "GeneralFunc.h"
#include <ctype.h>



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
	for (int i = 0; i < strlen(str); i++)
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

