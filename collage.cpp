#include<stdio.h>
#include<stdlib.h>
struct node
{
int data;
struct node *next;
};
int main()
{
    struct node *n1, *n2,*n3,*n4, *head=NULL,*temp,*ptr,*tr;
    n1=(struct node*)malloc(sizeof(struct node));
    n2=(struct node*)malloc(sizeof(struct node));
    n3=(struct node*)malloc(sizeof(struct node));
    n4=(struct node*)malloc(sizeof(struct node));
    n1->data=10;
    n2->data=20;
    n3->data=30;
    n4->data=40;
    n1->next=n2;
    n2->next=n3;
    n3->next=n4;
    n4->next=NULL;
    head=n1;
    temp=head;

    if(head==NULL)
    {
        printf("empty linked list ");
    }
    else if(head->next==NULL)
    {
        free(head);
    }
    else
    {
        while(temp->next->next!=NULL)
        {
            temp=temp->next;

        }
        ptr=temp->next;
        temp->next=NULL;
        free(ptr);

    }
    tr=head;

   if(tr!=NULL)
    {
    printf("After the the Last Node : ");
    tr=head;
    while(tr!=NULL)
    {
        printf("%d   ",tr->data);
        tr=tr->next;
    }
    }

}