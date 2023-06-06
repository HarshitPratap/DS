#include<stdio.h>
#include<stdlib.h>
//Node declaration for Queue and changed its name as QueueNode
typedef struct Node
{
    int info;
    struct Node *next;
}QueueNode;
//function declaration
int isEmpty(QueueNode*);
void display(QueueNode*);
void push(QueueNode**,QueueNode**,int);
void pop(QueueNode**,QueueNode**);

int main()
{
    //required variables declarations
    QueueNode *left = NULL,*right = NULL;
    int data,choice = 0;
    do{
        printf("\n1.PUSH\n2.POP\n3.DISPLAY\n4.EXIT");
        printf("\nEnter your choice:- ");
        scanf("%d",&choice);
        switch (choice)
        {
            case 1:
                //Ask for data from user
                printf("\nEnter data to be pushed:- ");
                scanf("%d",&data);
                //Function call
                push(&left,&right,data);
                break;
            case 2:
                //Checking underflow
                if(isEmpty(left)){
                    printf("\nQueue underflow.");
                }else{
                    //Function call
                    pop(&left,&right);
                }
                break;
            case 3:
                //Checking underflow
                if(isEmpty(left)){
                    printf("\nQueue underflow.");
                }else{
                    //function call
                    display(left);
                }
                break;
            case 4:
                exit(0);
                break;
        }
    }while(1);
    return 0;
}
//isEmpty function return one if there is no any elements in Queue
//take one argument that is address of first element of Queue
int isEmpty(QueueNode *top){
    return top == NULL;
}

//push is used to push element in last of Queue
//take two argument that is address of address of first & last element of Queue and data to be pushed
void push(QueueNode **head,QueueNode **tail,int data){
    QueueNode *temp = (QueueNode *) malloc(sizeof(QueueNode));
    if(temp == NULL){
        printf("\nNot enough memory.");
    }else{
        temp->info = data;
        temp->next = NULL;
        if(*head == NULL){
            *head = *tail = temp;
        }else{
            (*tail)->next = temp;
            *tail = temp;
        }
        printf("\nData pushed to Queue successfully.");
    }
}
//display return nothing take one argument which is address of first element of Queue
//traverse each element and print it
void display(QueueNode *left){
    printf("\nElemnets of Queue are:- ");
    while (left != NULL)
    {
        printf("%d",left->info);
        left = left->next;
        if (left != NULL)
        {
            printf(", ");
        } 
    }
    printf("\n");
}
//pop is used to remove first element from Queue
//take address of address of first & last elemnet of Queue
void pop(QueueNode **head, QueueNode **tail){
    QueueNode *temp = NULL;
    printf("\nData to be poped is %d.",(*head)->info);
    temp = *head;
    *head = (*head)->next;
    if(*head == NULL)
        *tail = NULL;
    free(temp);
} 