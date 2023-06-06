#include<stdio.h>
#include<stdlib.h>
//Node declaration for stack and changed its name as StackNode
typedef struct Node
{
    int info;
    struct Node *next;
}StackNode;
//function declaration
int isEmpty(StackNode*);
void display(StackNode*);
StackNode * push(StackNode*,int);
StackNode * pop(StackNode*);

int main()
{
    //required variables declarations
    StackNode *top = NULL;
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
                top = push(top,data);
                break;
            case 2:
                //Checking underflow
                if(isEmpty(top)){
                    printf("\nStack underflow.");
                }else{
                    //Function call
                    top = pop(top);
                }
                break;
            case 3:
                //Checking underflow
                if(isEmpty(top)){
                    printf("\nStack underflow.");
                }else{
                    //function call
                    display(top);
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
int isEmpty(StackNode *top){
    return top == NULL;
}

//push is used to push element in last of stack
//take two argument that is address of last element of stack and data to be pushed
StackNode * push(StackNode *top,int data){
    StackNode *temp = (StackNode *) malloc(sizeof(StackNode));
    if(temp == NULL){
        printf("\nNot enough memory.");
    }else{
        temp->info = data;
        temp->next = top;
        printf("\nData pushed to stack successfully.");
    }
    return temp;
}
//display return nothing take one argument which is address of last element of stack
//traverse each element and print it
void display(StackNode *top){
    printf("\nElemnets of stack are:- ");
    while (top != NULL)
    {
        printf("%d",top->info);
        top = top->next;
        if (top != NULL)
        {
            printf(", ");
        } 
    }
    printf("\n");
}
//pop is used to remove last element from stack
//take address of last elemnet of stack
StackNode * pop(StackNode *top){
    StackNode *temp = NULL;
    printf("\nData to be poped is %d.",top->info);
    temp = top;
    top = top->next;
    free(temp);
    return top;
} 