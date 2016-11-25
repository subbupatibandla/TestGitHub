#include<stdio.h>

struct node {
	int data;
	struct node *left;
	struct node *right;
};
typedef struct node Node;

Node *root = NULL;
Node *curr = NULL, *next = NULL, *prev = NULL;

void InsertLeftOfTree()
{
	int Data;
	Node *newnode = NULL;
	
	printf("\n Enter Data:");
	scanf("%d",&Data);
	
	newnode = (Node*)malloc(sizeof(Node));
	
	newnode->data = Data;
	newnode->left = NULL;
	newnode->right = NULL;
	
	if (root == NULL)
		root = newnode;
	else
	{
		curr = root;
		while(curr->left != NULL)
			curr = curr->left;
			
		curr->left = newnode;
	}
}

void displayTree()
{
	printf("Element in Tree are :");
	
	
}

int main()
{
	int data, choice = 0;
	
	while(1)
	{
		printf("List of Functionalities of a Binary Tree.\n");
		printf("1. Insert Left of Tree\n");
		printf("2. Insert Right of Tree\n");
		printf("3. Display Tree\n");
		printf("4. Exit\n");
		
		printf("\n Enter Your Choice:");
		scanf("%d",&choice);
		
		switch(choice)
		{
			case 1:
				/* Insert at Left of Tree */
				InsertLeftOfTree();
				break;
			case 2:
				/* Insert at Right of Tree */
				break;
			case 3:
				/* Display Contents in Tree */
				displayTree();
				break;
			case 4:
				/* Exit from Program */
				return 0;
			default:
				printf("Selected Option is not available...!\n");
			break;
		}
	}
	
	return 0;
}
