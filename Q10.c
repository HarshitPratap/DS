#include<stdio.h>
#include<stdlib.h>
//Node declaration for stack and changed its name as LinkedListType
typedef struct Node
{
    int info;
    struct Node *next;
}LinkedListType;
//function declaration
int isEmpty(LinkedListType*);
void display(LinkedListType*);
void push(LinkedListType**,LinkedListType**,int);
void pushNode(LinkedListType**,LinkedListType**,LinkedListType*);
void joinList(LinkedListType**,LinkedListType**,LinkedListType*,LinkedListType*);

int main()
{
    //required variables declarations
    LinkedListType *sleft = NULL,*sright = NULL;
    LinkedListType *aleft = NULL,*aright = NULL;
    LinkedListType *bleft = NULL,*bright = NULL;
    int data,key,choice = 0;
    do{
        printf("\n1.PUSH TO A\n2.PUSH TO B\n3.JoinList AND DISPLAY\n4.EXIT");
        printf("\nEnter your choice:- ");
        scanf("%d",&choice);
        switch (choice)
        {
            case 1:
                //Ask for data from user
                printf("\nEnter data to be pushed:- ");
                scanf("%d",&data);
                //Function call
                push(&aleft,&aright,data);
                break;
            case 2:
                //Ask for data from user
                printf("\nEnter data to be pushed:- ");
                scanf("%d",&data);
                //Function call
                push(&bleft,&bright,data);
                break;
            case 3:
                //Checking underflow
                if(isEmpty(aleft) && isEmpty(bleft)){
                    printf("\nList underflow.");
                }else{
                    //Function call
                    joinList(&sleft,&sright,aleft,bleft);
                }
                break;
            case 4:
                exit(0);
                break;
        }
    }while(1);
    return 0;
}
//isEmpty function return one if there is no any elements in list
int isEmpty(LinkedListType *top){
    return top == NULL;
}

//push is used to push element in last of list
void push(LinkedListType **head,LinkedListType **tail,int data){
    LinkedListType *temp = (LinkedListType *) malloc(sizeof(LinkedListType));
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
void pushNode(LinkedListType** h,LinkedListType** t,LinkedListType* n){
    if(*h == NULL){
        *h = *t = n;
    }else{
        (*t)->next = n;
        *t = n;
    }
}
void joinList(LinkedListType** sh,LinkedListType** st,LinkedListType* al,LinkedListType* bl){
    printf("\nA list:- ");
    display(al);
    printf("\nB list:- ");
    display(bl);
    LinkedListType *t = NULL;
    int i = 1;
    while (al != NULL && bl != NULL)
    {
        if((i % 2) !=  0){
            t = al;
            al = al->next;
            t->next = NULL;
        }else{
            t = bl;
            bl = bl->next;
            t->next = NULL;
        }
        pushNode(sh,st,t);
        i++;
    }
    if (al != NULL)
    {
        while (al != NULL)
        {
            t = al;
            al = al->next;
            t->next = NULL;
            pushNode(sh,st,t);
        }
    }else if(bl != NULL){
        while (bl != NULL)
        {
            t = bl;
            bl = bl->next;
            t->next = NULL; 
            pushNode(sh,st,t);
        }
    }
    printf("\nR list:- ");
    if ((*sh) != NULL)
    {
        display((*sh));
    }
}
//traverse each element and print it
void display(LinkedListType *left){
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
