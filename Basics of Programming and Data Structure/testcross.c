#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

struct node
{
	char *word;
	struct node *left, *right;
};
bool wordFound = false;
void checkThisWord(int wordLength, char *characters, int *charPositions, char *word);

struct node *newNode(char *word)
{
	struct node *temp = (struct node *)malloc(sizeof(struct node));
	temp->word = (char *)malloc(strlen(word) + 1 * sizeof(char));
	strcpy(temp->word, word);
	temp->left = temp->right = NULL;
	return temp;
}


void inorder(struct node *root)
{
	if (root != NULL)
	{
		inorder(root->left);
		printf("%s -> ", root->word);
		inorder(root->right);
	}
}

struct node *preOrder(struct node *root, char *characters, char *rootICameWith)
{
	if (root != NULL)
	{
		if (root->word[0] == characters[0] && strcmp(root->word, rootICameWith) != 0)
		{
			return root;
		}
		preOrder(root->left, characters, rootICameWith);
		preOrder(root->right, characters, rootICameWith);
	}
	else
	{
		return NULL;
	}
}


struct node *insert(struct node *node, char *word)
{
	if (node == NULL)
		return newNode(word);

	if (strcmp(word, node->word) < 0)
		node->left = insert(node->left, word);
	else
		node->right = insert(node->right, word);

	return node;
}

struct node *getNewRoot(struct node *root, char *characters, char *word)
{
	struct node *newroot = preOrder(root, characters, root->word);
	if (newroot == NULL)
	return NULL;
	else
	return newroot;
}
void search(struct node *root, int wordLength, char *characters, int *charPositions)
{
onFirstIF:
	if (root == NULL)
	{
		if (wordFound == false)
		{
			printf("Data Not Found!");
		}
		return;
	}
	if (root->word[0] == characters[0])
	{
		if (strlen(root->word) != wordLength)
		{
			root = getNewRoot(root, characters, root->word);
			goto onFirstIF;
		}
		else
		{
			checkThisWord(wordLength, characters, charPositions, root->word);
			root = getNewRoot(root, characters, root->word);
			goto onFirstIF;
		}
	}
outOfIF:
	if (characters[0] < root->word[0])
	{
		search(root->left, wordLength, characters, charPositions);
	}
	if (characters[0] > root->word[0])
	{
		search(root->right, wordLength, characters, charPositions);
	}
}

void preOrderSearch(struct node *root, int wordLength, char *characters, int *charPositions)
{
	if (root != NULL)
	{
		checkThisWord(wordLength, characters, charPositions, root->word);
		preOrderSearch(root->left, wordLength, characters, charPositions);
		preOrderSearch(root->right, wordLength, characters, charPositions);
	}
}

void checkThisWord(int wordLength, char *characters, int *charPositions, char *word)
{
	if (strlen(word) == wordLength)
	{
		int i;
		for (i = 0; i < strlen(characters); i++)
		{
			if (word[charPositions[i] - 1] != characters[i])
			{
				return;
			}
		}
		wordFound = true;
		printf("\nis this the word you are looking for : %s", word);
	}
}

int main()
{

	struct node *root = NULL;
	int wordLength, i, totalchars;
	int *charPositions;
	char *characters;
	char data[10];

	FILE *filePointer ;
	filePointer = fopen("dict.txt", "r") ;
	if ( filePointer == NULL )
	{
		printf( "dict.txt file failed to open." ) ;
	}
	else
	{
		while (fscanf(filePointer, "%s", data) != EOF)
		{
			root=insert(root,data);
		}
		fclose(filePointer) ;
	}

	printf("\nWhat is the word length? : ");
	scanf("%d", &wordLength);

	printf("\nHow many characters do you know? : ");
	scanf("%d", &totalchars);

	characters = (char *)malloc(totalchars * sizeof(char *));
	printf("\nEnter characters you know in order(do not use space separate) : ");
	scanf("%s", characters);
	if (strlen(characters) != totalchars)
	{
		printf("\nEnter all characters! ");
		exit(0);
	}

	charPositions = (int *)calloc(totalchars, sizeof(int));
	printf("\nEnter the positions of these characters in order(use spaces to separate) : ");
	for (i = 0; i < strlen(characters); i++)
	{
		int data;
		scanf("%d", &data);
		if (data > wordLength || data < 0)
		{
			printf("Entered Invalid position!");
			exit(0);
		}
		charPositions[i] = data;
	}

	if (charPositions[0] == 1)
	{
		search(root, wordLength, characters, charPositions);
	}
	else
	{
		preOrderSearch(root, wordLength, characters, charPositions);
	}
	printf("\n");
}
