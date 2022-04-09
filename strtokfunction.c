#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX_LENGTH 80
int main()
{
	char sentence[MAX_LENGTH];
	char *words;
	printf("Enter the sentence: ");
	fgets(sentence, MAX_LENGTH, stdin);
	words = strtok(sentence, " ");
	while (words != NULL)
	{
		printf("%s\n", words);
		words = strtok(NULL, " ");
	}
}