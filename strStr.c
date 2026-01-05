#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int *set_next(char *needle, int len)
{
	int *next = (int*)malloc(len * sizeof(int));

	next[0] = -1;
	if (len <= 1) {
		return next;
	}
	next[1] = 0;

	int i = 2, j = 0;
	while (i < len) {
		if (needle[i - 1] == needle[j]) {
			j++;
			next[i] = j;
			i++;
		} else if (j > 0) {
			j = next[j];
		} else {
			next[i] = 0;
			i++;
		}
	}

	return next;
}

int strStr(char* haystack, char* needle)
{
	int haystack_len = strlen(haystack);
	int needle_len = strlen(needle);

	int *next = set_next(needle, needle_len);

	int i, j = 0;
	while (i <= haystack_len - needle_len) {
		if (haystack[i + j] == needle[j]) {
			j++;
			if (j == needle_len) {
				free(next);
				next = NULL;
				return i;
			}
		} else {
			i += j - next[j];
			j = j > 0 ? next[j] : 0;
		}
	}

	free(next);
	next = NULL;

	return -1;
}