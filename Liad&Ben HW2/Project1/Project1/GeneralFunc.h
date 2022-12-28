#pragma once
#define MAX_LENGTH 255


char* myGets(char* buf, int size);
int countCharInString(const char* str, char c);
int checkAndUpdateString(char* str);
char*	createDynStr(const char* msg);
int isNameValid(char* str, int limit);
//char* getName(char* msg);
