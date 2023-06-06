#include<stdio.h>
#include<stdlib.h>
//Node declaration for stack and changed its name as QueueNode
typedef struct Node
{
    int info;
    struct Node *next;
}QueueNode;
//function declaration
int isEmpty(QueueNode*);
void display(QueueNode*);
void push(QueueNode**,QueueNode**,int);
void pop(QueueNode**,QueueNode**,int);

int main()
{
    //required variables declarations
    QueueNode *left = NULL,*right = NULL;
    int data,key,choice = 0;
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
                    printf("\nEnter key to delete:- ");
                    scanf("%d",&key);
                    pop(&left,&right,key);
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
//isEmpty function return one if there is no any elements in stack
//take one argument that is address of last element of stack
int isEmpty(QueueNode *top){
    return top == NULL;
}

//push is used to push element in last of stack
//take two argument that is address of address of last element of stack and data to be pushed
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
        printf("\nData pushed to stack successfully.");
    }
}
//display return nothing take one argument which is address of last element of stack
//traverse each element and print it
void display(QueueNode *left){
    printf("\nElemnets of Linked List are:- ");
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
//pop is used to remove last element from stack
//take address of address of last elemnet of stack
void pop(QueueNode **head, QueueNode **tail,int key){
    QueueNode *temp = NULL;
    QueueNode *curr = NULL;
    curr = temp = *head;
    if((*head)->info == key){
        *head = (*head)->next;
        if(*head == NULL)
            *tail = NULL;
    }else {
        while(curr->next->info != key && curr->next != NULL){
            curr = curr->next;
        }
        if (curr->next->info == key && curr->next == *tail)
        { 
            temp = curr->next;
            curr->next = temp->next;
            *tail = curr;
        }else if(curr->next->info == key && curr->next != *tail){
            temp = curr->next;
            curr->next = temp->next;
        }else{
            printf("\n%d is not present in the list.",key);
        }
    }
    printf("\nData to be poped is %d.",temp->info);
    free(temp);
} 