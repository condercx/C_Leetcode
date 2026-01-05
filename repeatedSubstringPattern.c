#include <stdio.h>
#include <stdbool.h>
#include <string.h>

bool repeatedSubstringPattern(char* s)
{
	int n = strlen(s);
	char doubled[2*n+1];
	strcpy(doubled, s);
	strcat(doubled, s);
	doubled[2*n-1] = '\0';
	return strstr(doubled+1, s) != NULL;
}