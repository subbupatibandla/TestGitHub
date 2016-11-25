#include<stdio.h>
#include<stdlib.h>

struct node {
  int data;
  struct node *next;
};

typedef struct node Node;

Node *Head = NULL;

Node* CreateNewNode();
void DisplayList(void);

Node* CraeteNewNode()
{
	Node * temp = NULL;
	int element = 0;
	
	printf("\nEnter element to insert: ");
	scanf("%d",&element);
			
	temp = (Node*)malloc(sizeof(Node));
	temp->data = element;
	temp->next = NULL;
	
	return temp;
}

void DisplayList()
{
	Node *temp = NULL;
	
	printf("\n Elements in List Are:  ");
	temp = Head;
	while(temp!=NULL)
	{
		printf("%d\t",temp->data);
		temp = temp->next;
	}
}
int main()
{
	Node *temp = NULL, *temp1 = NULL, *temp2 = NULL, *prev = NULL, *curr = NULL, *Last = NULL, *next = NULL;
	int operation = 0, node_number = 0, count_of_nodes = 0, Data = 0, SearchFlag = 0, iteration_cnt = 0;
	
	while(1) {
		
	DisplayList();			
	printf("\nList of Linked List Actions\n");
	printf("1. Insert Element in List at Start\n");
	printf("2. Insert Element in List at End\n");
	printf("3. Insert Element after particular node\n");
	printf("4. Delete node based on data\n");
	printf("5. Delete Node based on Count\n");
	printf("6. Delete Node at Start\n");
	printf("7. Delete Node at End\n");
	printf("8. Sort the List\n");
	printf("9. Search element in the list\n");
	printf("10. Reverse List\n");
	printf("11. Display List\n");
	printf("12. Jumble the List\n");
	printf("13. Exit\n");
	
	printf("Enter Your Choice:");	
	scanf("%d",&operation);
	
	
	switch(operation) {
		/* Insert element at start of List */
		case 1:
			temp = CraeteNewNode();			
			if (Head == NULL)
			{
				Head = temp;
			}
			else 
			{
				temp1 = Head;
				temp->next = temp1;
				Head = temp;
			}
			
			break;
		case 2:
			/* Insert element at end of List */
			temp = CraeteNewNode();			
			if (Head == NULL)
			{
				Head = temp;
			}
			else 
			{
				temp1 = Head;
				
				while(temp1->next != NULL)
					temp1 = temp1->next;
				temp1->next = temp;
			}
			break;
		case 3:
			/*Insert element after nth node */
			temp = CraeteNewNode();
			
			printf("\n Enter Node number for insert new item after this:");
			scanf("%d",&node_number);
			
			temp1 = Head;
			if(temp1 == NULL)
			{
				printf(".....List is Empty. Inserting at Start\n");
				Head = temp;
			}
			else
			{
				while(temp1 != NULL)
				{
					count_of_nodes = count_of_nodes + 1;
					if (node_number == count_of_nodes)
					{
						temp2 = temp1->next;
						temp->next = temp2;
						temp1->next = temp;
						break;
					}
					temp1 = temp1->next;
				}
				if (count_of_nodes < node_number)
					printf("Node Number not found. Existing Nodes in List is : %d\n",count_of_nodes);
			}			
			
			break;
		case 4:
			/* Delete Node based on Data */
			printf("Enter Data to be deleted:");
			scanf("%d",&Data);
			
			temp1 = Head;
			while(temp1 != NULL)
			{
				if (temp1->data == Data)
				{
					if (Head == temp1)
					{
						Head = temp1->next;												
					}
					else
					{
						prev->next = temp1->next;
					}
					free(temp1);					
					break;
				}
				else
				{
					prev = temp1;
					temp1 = temp1->next;	
				}					
			}			
			break;
		case 5:
			/* Delete Node based on Node Number */
			printf("\n Enter Node number to delete from the List:");
			scanf("%d",&node_number);
			
			count_of_nodes = 0;
			
			temp1 = Head;
			if(temp1 == NULL)
			{
				printf(".....List is Empty. Delete is not possible.\n");
			}
			else
			{
				while(temp1 != NULL)
				{
					count_of_nodes = count_of_nodes + 1;
					
					printf("node_number %d count_of_nodes %d temp1->data %d \n",node_number,count_of_nodes,temp1->data);
					if (node_number == count_of_nodes)
					{
						if (Head == temp1)
						{
							Head = temp1->next;						
						}
						else
						{
							printf("Shift donr\n");
							prev->next = temp1->next;
						}
						free(temp1);						
						break;
					}
					prev = temp1;
					printf("prev->data %d\n",prev->data);
					temp1 = temp1->next;					
				}
				if (count_of_nodes < node_number)
					printf("Node Number not found. Existing Nodes in List is : %d\n",count_of_nodes);
			}
			
			break;
		case 6:
			/* Delete Node at Start */
			temp1 = Head;
			if(temp1 == NULL)
				printf("List is Empty..\n");
			else
			{
				Head = temp1->next;
				free(temp1);
			}			
			break;
		case 7:
			/* Delete Node at End */
			
			if(Head == NULL)
				printf("List is Empty.\n");
			else
			{
				temp1 = Head;
				while(temp1->next->next != NULL)
					temp1 = temp1->next;
				
				temp2 = temp1->next;
				temp1->next = NULL;
				free(temp2);
			}
			
			break;
		case 8:
			/* Sort The List using Bubble Sort */
			temp1 = Head;
			temp2 = temp1->next;
			
			while(temp1->next != NULL)
			{
				while (temp2 != NULL)
				{				
					if (temp1->data <= temp2->data)
					{
						Data = temp1->data;
						temp1->data = temp2->data;
						temp2->data = Data;
					}
					temp2 = temp2->next;
				}
				temp1 = temp1->next;
				temp2 = temp1->next;
			}
			
			break;
		case 9:
			/* Search algorithm to find data in List.*/
			printf("\n Enter Element to Search in List:");
			scanf("%d",&Data);
			
			temp1 = Head;
			while(temp1 != NULL)
			{
				if(temp1->data == Data)
				{
					printf("Element %d Found in List.\n",Data);
					SearchFlag = 1;
					break;
				}
				else
					temp1 = temp1->next;
			}
			if(SearchFlag == 1)
				SearchFlag = 0;
			else
				printf("Element %d not found in List.\n",Data);
			
			break;
		case 10:
			/* Reverse Single Linked List */
			temp1 = Head;
			prev = NULL;
			curr = Head;
			
			while(curr != NULL)
			{
				temp1 = curr->next;
				curr->next = prev;
				prev = curr;
				curr = temp1;				
			}
			Head = prev;
			
			break;
		case 11:
			/* Displaying Elements in List.*/
			printf("\nElements in List are : ");			
			temp = Head;
			while(temp!=NULL)
			{
				printf("%d\t",temp->data);
				temp = temp->next;
			}
			
			break;
		case 12:
			/* I/P: 1 2 3 4 5 6
			   O/P: 1 6 2 5 3 4 */
			curr = Head;
			while(curr != NULL)
			{
				temp = curr;
				while(temp->next->next != NULL)
				{
					temp = temp->next;
					iteration_cnt++;
				}
				
				
				Last = temp->next;
				next = curr->next;
				if(Last != next)
    			{
					Last->next = next;
					curr->next = Last;
					temp->next = NULL;
				
					curr = curr->next->next;
				}				
    			else
				break;
			}
			printf("iteration_cnt %d\n",iteration_cnt);
			
			break;
		case 13:
			return 0;
			break;
		default:
			printf("\nNot supported operation \n");
			break;	
	} /* End of Switch Loop.*/
	
	} /* End of While Loop. */	
			
	return 0;
}
