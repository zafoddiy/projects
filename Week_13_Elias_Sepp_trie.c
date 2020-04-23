#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_NAME 32
#define ALPHA_LEN 54

typedef struct node
{
	char ch;
	int isLeaf;
	struct node *chars[ALPHA_LEN];
} trie_t;

void ReadData(trie_t*, char*);
struct node *CreateNode(char);
void InsertNode(struct node*, char[]);
int SearchName(struct node*, char[]);
void PrintNames(struct node*, char[], int);
void ConvertChars(char[]);
int Position(char);
void FreeTrie(struct node*);

int main(void)
{
	trie_t *data = CreateNode('\0');
	ReadData(data, "03_data_long.txt");
	int lvl = 0;
	char string[MAX_NAME];
	PrintNames(data, string, lvl);
    FreeTrie(data);
    return 0;
}

void ReadData(trie_t *trie, char *file)
{
	long int junkID;
	char name[MAX_NAME], lName[MAX_NAME], junkTown[MAX_NAME];

	FILE *fp = fopen(file, "r");
	if (fp == NULL)
		exit(1);

	while (fscanf(fp, "%ld %s %s %s", &junkID, name, lName, junkTown) == 4)
	{
		strcat(name, " ");
		strcat(name, lName);
		if (SearchName(trie, name) == 0)
		{
			InsertNode(trie, name);
		}
	}
	fclose(fp);
}

struct node *CreateNode(char letter)
{
	struct node *trie = (struct node*)malloc(sizeof(struct node));
	if (trie == NULL)
	{
		puts("Memory allocation failed!");
		exit(1);
	}
	trie->isLeaf = 0;
	trie->ch = letter;
	int i;
	for (i = 0; i < ALPHA_LEN; ++i)
		trie->chars[i] = NULL;
	return trie;
}

void InsertNode(struct node *trie, char name[])
{
    int pos;
	struct node *pTemp = trie;
    for (int i = 0; i < strlen(name); ++i)
    {
		pos = Position(name[i]);
        if (pTemp->chars[pos] == NULL)
        {
            pTemp->chars[pos] = CreateNode(name[i]);
        }
        pTemp = pTemp->chars[pos];
    }
    pTemp->isLeaf = 1;
}

int SearchName(struct node *trie, char name[])
{
	struct node *pTemp = trie;
	if (pTemp == NULL)
		return 0;
	int pos;
	for (int i = 0; name[i] != '\0'; ++i)
	{
		pos = Position(name[i]);
		if (pTemp->chars[pos] == NULL)
			return 0;
		pTemp = pTemp->chars[pos];
	}
	if (pTemp != NULL && pTemp->isLeaf == 1)
        return 1;
	return 0;
}

void PrintNames(struct node *trie, char buf[], int level) 
{
    if (trie->isLeaf == 1)  
    {
        buf[level] = '\0'; 
        printf("%s\n", buf);
    }
    int i;
    for (i = 0; i < ALPHA_LEN; ++i)  
    {
        if (trie->chars[i] != NULL)  
        {
			if (i >= 0 && i <= 25)
				buf[level] = i + 'a';
			else if (i >= 26 && i <= 51)
				buf[level] = i - 26 + 'A';
			else if (i == 52)
				buf[level] = i - 7;
			else if (i == 53)
				buf[level] = i - 21;
            PrintNames(trie->chars[i], buf, level + 1); 
        }
    }
} 

int Position(char letter)
{
	int pos;
	if (letter >= 'a' && letter <= 'z')
		pos = (int)letter - 'a';
	else if (letter >= 'A' && letter <= 'Z')
		pos = (int)letter - 'A' + 26;
	else if (letter == '-')
		pos = 52;
	else
		pos = 53;
	return pos;
}

void FreeTrie(struct node *trie)
{
	int i;
    if (trie != NULL && trie->isLeaf == 0){
      for (i = 0; i < ALPHA_LEN; ++i)
      {
         if (trie->chars[i] != NULL)
         {
            FreeTrie(trie->chars[i]);
            trie->chars[i] = NULL;
         }
      }
    }
    free(trie);
}

void ConvertChars(char name[])
{
	for (int i = 0; name[i] != '\0'; ++i)
	{
		if (name[i] >= 'A' && name[i] <= 'Z')
		{
			name[i] += 32;
		}
	}
}
