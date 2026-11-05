#include <stdio.h>
#define MAX 5 

int queue[MAX];
int front = -1, rear = -1; 


void insert(int item) {
    if(rear == MAX -1){
        printf("queue is overflow! cannot insert %d\n", item);
        return;
    }
    if (front == -1)
    front = 0;
rear++;
queue[rear] = item;
printf("inserted: %d\n", item);
}
 void delete() { 
    if(front == -1 || front > rear) {
        printf("queue Underflow! queue is empty\n");
        return; 
    }
        printf("deleted: %d\n", queue[front]);
        front++;
        if(front > rear){
        front = rear = -1 ;
    }
}

int main(){
    insert(10);
    insert(20);
    insert(30);
    delete();
    delete();
    insert(40);
    delete();
    delete();
    delete();
    return 0;
    
}