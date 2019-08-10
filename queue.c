#include<stdio.h>
#include<stdlib.h>


struct node
{
	int info;
	struct node *next;
};

struct queue
{
	struct node *front;
	struct node *rear;
}queue;



struct node *getnode()
{
	struct node *temp=NULL;
	temp=(struct node*)malloc(sizeof(struct node));
	temp->info=0;
	temp->next=0;
	return temp;
}



void freen(struct node *p)
{
	free(p);
}


void init(struct queue *q)
{
	q->front=NULL;
	q->rear=NULL;
}


void insertq(struct queue *q,int value)
{

	struct node *temp=NULL;
	temp=getnode();
	temp->info=value;
	temp->next=NULL;

	if(q->front==NULL)
		q->front=temp;
	if(q->rear==NULL)
		{
			q->rear=temp;
			return;
		}
	q->rear->next=temp;
	q->rear=temp;
}



int deleteq(struct queue *q)
{
	struct node *temp=NULL;
	int value;

	if(isemptyq(q))
	{
		printf("empty...");
		exit(1);
	}
	temp=q->front;
	q->front=q->front->next;
	value=temp->info;

	if(q->rear==temp)
	{
		q->rear=NULL;
	}
	freen(temp);
	return value;

}


int isemptyq(struct queue *q)
{

	return q->front==NULL && q->rear==NULL;
}


int main()
{

	struct queue q;
	init(&q);




	int choice,n;
	do
	{
		printf("\n MENU \n 1.insert\n2.delete\n3.isempty\n4.exit\n\n choice...?\n");
		scanf("%d",&choice);
		switch(choice)
		{
			case 1: printf("\nenter element to insert....");
				scanf("%d",&n);
				insertq(&q,n);
				break;

			case 2: printf("\nremoved element is ....%d",deleteq(&q));
				break;

			
			case 3: if(isemptyq(&q))
					printf("empty....");
				else
					printf("not empty....");
				break;
			case 4: exit(0);
				break;

			default: printf("invalid");
				 break;
		}
	}
	while(choice!=6);

}
