#include<stdio.h>
#include<stdlib.h>
struct node
{
	int data;
	struct node *next;
};

void insert();
void del();
void display();
void search();


struct node *temp;
struct node *head=NULL;
int position=1;



int main()
{
	int choice;
	char ch;
	do
	{
	printf("1.insert  2.delete  3.display  4.search");
	printf("\nEnter your choice:");
	scanf("%d",&choice);
	switch(choice)
	{
		case 1:
			insert();
			display();
			break;
		case 2:
			del();
			display();
			break;
		case 3:
			display();
			break;
		case 4:
			search();
			break;
	}
	printf("\nDo you want to continue:");
	scanf(" %c",&ch);
    }while(ch=='y'||ch=='Y');
}

void insert()
{
	int ele,pos;
	struct node *newnode;
	newnode=(struct node*)malloc(sizeof(struct node));
	printf("\nEnter the element to be inserted:");
	scanf("%d",&ele);
	printf("\nEnter the position to be inserted(1 to %d):",position);
	scanf("%d",&pos);
	if(pos==1)
	{
		newnode->data=ele;
		newnode->next=NULL;
		head=newnode;
	}else
	{
		int i;
		temp=head;
		for(i=2;i<pos;i++)
		{
			temp=temp->next;
		}
		newnode->data=ele;
		newnode->next=temp->next;
		temp->next=newnode;
		
	}
	position++;
}

void display()
{
	if(head==NULL)
	{
		printf("list is empty");
	}
    else
	{
		printf("HEAD  ");
		for(temp=head;temp!=NULL;temp=temp->next)
		{
			printf("%d -> ",temp->data);
		}
		printf("NULL");
	
	}
}

void del()
{
	int pos;
	struct node *delnode,*temp;
	if(head==NULL)
	{
		printf("list is empty");
	}
    else
	{
		for(int i=2; i< position; i++) {
            if(temp->next!=NULL) {
                temp = temp->next;
            }
        }
        temp->next = temp->next->next;
	}
}

void search()
{
	int ele;
	int i=0;
	printf("\nEnter the element to be searched:");
	scanf("%d",&ele);
	for(temp=head;temp!=NULL;temp=temp->next)
	{
		i++;
		if(temp->data==ele)
		{
			printf("Element is found at %d",i);
			return;
		}
	}
	printf("Element is not found");
}