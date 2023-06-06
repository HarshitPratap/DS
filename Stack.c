#include<stdio.h>
#include<stdlib.h>

int isFull(int top,int MAX){
    return top == (MAX-1);
}

int isEmpty(int top){
    return top == -1;
}

void push(int* stack,int* top,int MAX){
    int data;
    if(isFull(*top,MAX)){
        printf("\nStack is overflow.");
        return ;
    }
    printf("\nEnter data to push:- ");
    scanf("%d",&data);
    stack[++(*top)] = data;
    printf("\nData pushed to stack successfully.");
    return ;
}

void display(int* stack, int top){
    int i;
    if(isEmpty(top)){
        printf("\nStack is empty.");
        return ;
    }
    printf("\nElemnets of stack are:- ");
    for (i = top; i > -1; i--)
    {
        printf("%d",stack[i]);
        if(i !=0 )
        printf(",");
    }
    return;
}

void pop(int* stack, int* top){
    int x;
    if(isEmpty(*top)){
        printf("\nStack is empty.");
        return;
    }
    x = stack[(*top)--];
    printf("Value poped is %d.",x);
    return;
}

void peek(int* stack, int top){
    int x;
    if(isEmpty(top)){
        printf("\nStack is empty.");
        return;
    }
    x = stack[top];
    printf("Value peeked is %d.",x);
    return;
}

int main()
{
    const int MAX = 5;
    int top = -1;
    int choice = 0;
    int stack[MAX];
    while(1){
        printf("\n1.PUSH\n2.POP\n3.PEEK\n4.DISPLAY\n5.EXIT");
        printf("\nEnter your choice.");
        scanf("%d",&choice);
        switch (choice)
        {
            case 1:
                push(stack,&top,MAX);
                break;
            case 2:
                pop(stack,&top);
                break;
            case 3:
                peek(stack,top);
                break;
            case 4:
                display(stack,top);
                break;
            case 5:
                exit(0);
                break;
            default:
                break;
        }
    }
    return 0;
}
