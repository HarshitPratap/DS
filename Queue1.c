#include<stdio.h>
#define MAX 5

int isFull(int front, int rear){
    return (((rear + 1) % MAX) == front);
}

int isEmpty(int front){
    return front == -1;
}

void enQueue(int* queue, int* front, int* rear){
    int data;
    if(isFull((*front),(*rear))){
        printf("\nQueue is full.");
        return;
    }
    printf("\nEnter data to insert:- ");
    scanf("%d",&data);
    (*rear) = ((*rear) + 1 ) % MAX;
    queue[(*rear)] = data;
    if((*front) == -1)
        (*front) = 0;
    return;
}

void deQueue(int* queue, int* front, int* rear){
    int e;
    if(isEmpty((*front))){
        printf("\nQueue is empty.");
        return;
    }
    e = queue[(*front)];
    
    if((*front) == (*rear)){
        (*front) = -1;
        (*rear) = -1;
    }else{
        (*front) = ((*front) + 1) % MAX;
    }
    printf("\nElement dequeued id %d",e);
    return;
}

void display(int* queue, int front, int rear){
    int i = front;
    if (isEmpty(front))
    {
        printf("\nQueue is empty.");
        return;
    }
    printf("\nFront->Rear:-");
    while(i != rear){
        printf("%d,",queue[i]);
        i = (i + 1) % MAX;
    }
    printf("%d",queue[i]);
    printf("\n");
}
void peek(int* queue, int front){
    if (isEmpty(front))
    {
        printf("\nQueue is empty.");
        return;
    }
    printf("\nItem peeked is %d.",queue[front]);
    return;    
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
