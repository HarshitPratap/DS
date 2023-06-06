#include<stdio.h>
#include<stdlib.h>
#define MAX 5

int isFull(int front,int rear){
    return (rear == (MAX - 1) && front == 0);
}

int isEmpty(int front){
    return front == -1;
}

void enQueue(int* queue,int* front,int* rear){
    int data;
    if(isFull(*(front),*(rear))){
        printf("\nQueue is full");
        return;
    }
    printf("\nEnter data to insert:- ");
    scanf("%d",&data);

    queue[++(*rear)] = data;
    if(*(front) == -1)
        *(front) = 0;
    printf("\n%d",*front);
}

void deQueue(int* queue, int* front, int* rear){
    int e;
    if(isEmpty(*(front))){
        printf("\nQueue is empty.");
        return;
    }
    e = queue[(*front)++];
    if((*front) > (*rear)){
        (*front) = -1;
        (*rear) = -1;
    }
    printf("\nElement enqued is %d",e);
}

void display(int* queue, int front, int rear){
    int i;
    if (isEmpty(front))
    {
        printf("\nQueue is empty.");
        return;
    }
    printf("Front->Rear:-");
    for ( i = front; i <= rear; i++)
    {
        printf("%d",queue[i]);
        if(i != rear){
            printf(",");
        }
    }
    printf("\n");
}

void peek(int* queue, int front){
    if(isEmpty(front)){
        printf("\nQueue is empty.");
        return;
    }
    printf("\nItem peeked is %d.",queue[front]);
}

int main()
{
    int queue[MAX],front = -1,rear = -1,choice;
    do
    {
        printf("\n1.ENQUEUE\n2.DEQUEU\n3.PEEK\n4.DISPLAY\n5.EXIT");
        printf("\nEnter your choice:- ");
        scanf("%d",&choice);
        switch (choice)
        {
            case 1:
                enQueue(queue,&front,&rear);
                break;
            case 2:
                deQueue(queue,&front,&rear);
                break;
            case 3:
                peek(queue,front);
                break;
            case 4:
                display(queue,front,rear);
                break;
            default:
                break;
        }
    } while (choice >= 1 && choice <= 4);
    
    return 0;
}
