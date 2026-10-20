//Q. Implement a ‘C’ program to insert element into the queue and delete
#include<stdio.h>
#include<stdlib.h>
#define MAX 5
int main()
{
int queue[MAX];
int rear,front,ch, item;
rear=-1;
front=-1;
do
{
    printf("1. insert \n 2.Delete \n 3. Exit");
    printf("\nEnter your Choice:");
    scanf("%d",&ch);
    switch(ch)
    {
        case 1: 
            printf("Enter the item to be inserted:" );
            scanf("%d",&item);
            if(rear==MAX-1)
            {
                printf("Queue is Full\n");
                break;
            }
            else
            {
                if(front==-1)
                {
                    front=0;
                }
                rear=rear+1;
                queue[rear]=item;
            break;

            }
        case 2:
            if(front==-1)
            {
                printf("queue is empty");
                break;
            }
            else
            {
                item=queue[front];
                printf("%d",item);
                if(rear==front)
                {
                    front=-1;
                    rear=-1;

                }
                front=front+1;
                break;
            }
        case 3: 
             exit(0);
        
    }
    printf("Do you want to continue 1 for Yes /2 for No");
    scanf("%d",&ch);

}while(ch==1);
}