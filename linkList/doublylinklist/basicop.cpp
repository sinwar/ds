/*
	SINWAR PREM
	premsinwar4@gmail.com
*/
//update required
#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
struct node{
	int data;
	struct node* lptr;
	struct node* rptr;
};
struct node *inform(struct node* naya)
{
	naya=(struct node *)malloc(sizeof(struct node));
	printf("enter data for new node\n");
	scanf("%d",&naya->data);
	naya->lptr=NULL;
	naya->rptr=NULL;
	return naya;
}
int dat;
struct node* head=NULL;
struct node* temp;
void insert()
{
	int a;
	struct node* naya;	
	printf("Press \n1 for front \n2 for in-between \n3 for end\n");
	scanf("%d",&a);
	naya=inform(naya);//calling inform function
	switch(a){
		case 1:
			if(head==NULL)
			{
				head=naya;
			}
			else
			{
				naya->rptr=head;
				head=naya;
			}
			break;
		case 2:
			temp=head;
			printf("Enter the data after you want to insert node\n");
			scanf("%d",&dat);
			while(temp->data!=dat)
			temp=temp->rptr;//set temp equal to prev node of new node
			naya->rptr=temp->rptr;//set right poitner of new node equal to right pointer of new ndoe
			temp->rptr=naya;
			naya->lptr=temp;
			if(naya->rptr!=NULL)
			naya->rptr->lptr=naya;
			break;
		case 3:
			temp=head;
			while(temp->rptr!=NULL)
			temp=temp->rptr;
			temp->rptr=naya;
			naya->lptr=temp;
		default:
			printf("Invalid Choice\n");
	}
}
void print()
{
	if(head==NULL)
	printf("There is no element for display\n");
	else
	{
		temp=head;
		printf("\n%d ",temp->data);
		while(temp->rptr!=NULL)
		{
			temp=temp->rptr;
			printf("%d ",temp->data);
		}
		printf("\n");
	}
}
void del()
{
	int ps,lal;
	printf("Press \n1 for front \n2 for in-between \n3 for end\n");
	scanf("%d",&ps);
	switch(ps)
	{
		case 1:
			if(head==NULL)
			printf("There is no element for deletion\n");
			else
			{
				temp=head;
				head=temp->rptr;
				free(temp);
			}
			break;
		case 2:
			printf("Enter the data of node to be deleted\n");
			scanf("%d",&lal);
			temp=head;
			while(temp->data!=lal)
			{
				temp->rptr=temp;
			}
			if(temp->lptr==NULL)
			printf("invalid you are trying for front node\n");
			else if(temp->rptr==NULL)
			printf("invalid you are trying for last node\n");
			else
			{
				temp->rptr->lptr=temp->lptr;
				temp->lptr->rptr=temp->rptr;
				temp->rptr=temp->lptr=NULL;
				free(temp);
			}
			break;
		case 3:
			temp=head;
			while(temp->rptr!=NULL)
			temp=temp->rptr;
			temp->lptr->rptr=NULL;
			temp->lptr=temp->rptr=NULL;
			free(temp);
			break;
		default:
			printf("Invalid choice\n");
			break;
	}
}
int main()
{
	int a;
	lable:
	printf("Press \n1 for insertion \n2 for deletion \n3 for display\n");
	scanf("%d",&a);
	switch(a)
	{
		case 1:
			insert();
			break;
		case 2:
			del();
			break;
		case 3:
			print();
			break;
	}
	goto lable;
}
