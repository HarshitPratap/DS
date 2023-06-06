#include<stdio.h>
#include<stdlib.h>
//Node declaration for stack and changed its name as NodeType
typedef struct Node
{
    int info;
    struct Node *next;
}NodeType;
//function declaration
int isEmpty(NodeType*);
void display(NodeType*);
void push(NodeType**,NodeType**,int);
void pushNode(NodeType**,NodeType**,NodeType*);
void split(NodeType*,NodeType**,NodeType**,NodeType**,NodeType**);

int main()
{
    //required variables declarations
    NodeType *left = NULL,*right = NULL;
    NodeType *pleft = NULL,*pright = NULL;
    NodeType *nleft = NULL,*nright = NULL;
    int data,key,choice = 0;
    do{
        printf("\n1.PUSH\n2.SPLIT AND DISPLAY\n3.EXIT");
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
                    printf("\nList underflow.");
                }else{
                    //Function call
                    split(left,&pleft,&pright,&nleft,&nright);
                }
                break;
            case 3:
                exit(0);
                break;
        }
    }while(1);
    return 0;
}
//isEmpty function return one if there is no any elements in list
int isEmpty(NodeType *top){
    return top == NULL;
}

//push is used to push element in last of list
void push(NodeType **head,NodeType **tail,int data){
    NodeType *temp = (NodeType *) malloc(sizeof(NodeType));
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
    }
}
void pushNode(NodeType** h,NodeType** t,NodeType* n){
    if(*h == NULL){
        *h = *t = n;
    }else{
        (*t)->next = n;
        *t = n;
    }
}
void split(NodeType* h,NodeType** ph,NodeType** pt,NodeType** nh,NodeType** nt){
    printf("\nMain list:- ");
    display(h);
    NodeType *t = NULL;
    int i = 1;
    while (h != NULL)
    {
        t = h;
        h = h->next;
        t->next = NULL;
        if((i % 2) ==  0){
            pushNode(ph,pt,t);
        }else{
            pushNode(nh,nt,t);
        }
        i++;
    }
    printf("\nR contain non ood element from main list:- ");
    if ((*ph) != NULL)
    {
        display((*ph));
    }
    printf("\nN contain ood element from main list:- ");
    if ((*nh) != NULL)
    {
        display((*nh));
    }
}
//traverse each element and print it
void display(NodeType *left){
    printf("\nElements of Linked List are:- ");
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
