#define _CRT_SECURE_NO_WARNINGS
#include <string.h>
#include <stdio.h>
#include "GeneralFunc.h"



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