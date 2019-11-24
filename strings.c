#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include "words.h"

void target(char*, char*);
void solving(char*, char*);

int main(void)
{
	char word[MAX];
	wordlist(word);
	char solution[MAX];
	target(word, solution);
	solving(word, solution);
	system("pause");
}

void target(char b[MAX], char c[MAX])
{
	int i;
	for (i = 0; b[i] != '\0'; i++)
	{
		if (b[i] == '-')
		{
			c[i] = '-';
		}
		else
		{
			c[i] = '_';
		}
	}
	c[i] = '\0';
}

void solving(char w[MAX], char s[MAX])
{
	puts("Let's play hangman!");
	char alphabet[] = "abcdefghijklmnopqrstuvwxyz";
	char insert;
	int tries = 10;
	do
	{
		printf("%s\n", s);
		printf("%s\n", alphabet);
		printf("You have %d tries.\n", tries);
		if (strcmp(w, s) == 0)
		{
			break;
		}
		scanf("%c", &insert);
		getchar();
		if (insert < 'a' || insert > 'z')
		{
			do
			{
				puts("Enter a character from a to z in the English alphabet!");
				scanf("%c", &insert);
				getchar();
			}
			while (insert < 'a' || insert > 'z');
		}
		if (strchr(alphabet, insert) == NULL)
		{
			do
			{
				puts("You've already entered that character!");
				insert = getchar();
			}
			while (strchr(alphabet, insert) == NULL);
		}
		if (strchr(w, insert) == NULL)
		{
			puts("Wrong!");
			int loc = strchr(alphabet, insert) - alphabet;
			alphabet[loc] = ' ';
			tries--;
		}
		else
		{
			if (strchr(w, insert) == strrchr(w, insert))
			{
				int loc = strchr(alphabet, insert) - alphabet;
				alphabet[loc] = ' ';
				loc = strchr(w, insert) - w;
				s[loc] = insert;
			}
			else
			{
				char *s_loc = strchr(alphabet, insert);
				int loc = s_loc - alphabet;
				alphabet[loc] = ' ';
				int i;
				for (i = 0; w[i] != '\0'; i++)
				{
					if (w[i] == insert)
					{
						s[i] = insert;
					}
				}
			}
		}
		system("cls");
	}
	while (tries > 0);
	if (tries == 0)
	{
		printf("Failure. The word was %s\n", w);
	}
	else
	{
		printf("Well done!\n");
	}
}

