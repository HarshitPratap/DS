#include<stdio.h>
#include<stdlib.h>
#include<string.h>
//Node declaration for stack and changed its name as LinkedListType
typedef struct Node
{
    int eId;
    char ename[20];
    struct Node *next;
}LinkedListType;
//function declaration
int isEmpty(LinkedListType*);
void display(LinkedListType*);
void push(LinkedListType**,LinkedListType**,int,char*);
void pushNode(LinkedListType**,LinkedListType**,LinkedListType*);
void joinList(LinkedListType**,LinkedListType**,LinkedListType*);
int search(LinkedListType*,LinkedListType*);

int main()
{
    //required variables declarations
    LinkedListType *aleft = NULL,*aright = NULL;
    LinkedListType *bleft = NULL,*bright = NULL;
    int data,choice = 0;
    char name[20];
    do{
        printf("\n1.PUSH TO A\n2.PUSH TO B\n3.UNION AND DISPLAY\n4.EXIT");
        printf("\nEnter your choice:- ");
        scanf("%d",&choice);
        switch (choice)
        {
            case 1:
                //Ask for data from user
                printf("\nEnter data to be pushed");
                printf("\nEnter Employee Id:- ");
                scanf("%d",&data);
                fflush(stdin);
                printf("\nEnter Employee Name:- ");
                gets(name);
                //Function call
                push(&aleft,&aright,data,name);
                break;
            case 2:
                //Ask for data from user
                printf("\nEnter data to be pushed");
                printf("\nEnter Employee Id:- ");
                scanf("%d",&data);
                fflush(stdin);
                printf("\nEnter Employee Name:- ");
                gets(name);
                //Function call
                push(&bleft,&bright,data,name);
                break;
            case 3:
                //Checking underflow
                if(isEmpty(aleft) && isEmpty(bleft)){
                    printf("\nList underflow.");
                }else{
                    //Function call
                    joinList(&aleft,&aright,bleft);
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
void push(LinkedListType **head,LinkedListType **tail,int data,char *name){
    LinkedListType *temp = (LinkedListType *) malloc(sizeof(LinkedListType));
    if(temp == NULL){
        printf("\nNot enough memory.");
    }else{
        temp->eId = data;
        strcpy(temp->ename,name);
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
void joinList(LinkedListType** al,LinkedListType** ar,LinkedListType* bl){
    printf("\nA list:- ");
    display(*al);
    printf("\nB list:- ");
    display(bl);
    LinkedListType *t = NULL;
    if(bl != NULL){
        while (bl != NULL)
        {
            if (search(*al,bl) == 0)
            {
                t = bl;
                bl = bl->next;
                t->next = NULL; 
                pushNode(al,ar,t);
            }else{
                bl = bl->next;
            }
        }
    }
    printf("\nJoined list:- ");
    if ((*al) != NULL)
    {
        display((*al));
    }
}

int search(LinkedListType *ll,LinkedListType *nll){
    while (ll != NULL)
    {
        if (ll->eId == nll->eId && strcmp(nll->ename,ll->ename) == 0)
        {
            return 1;
        }
        ll = ll->next;
    }
    return 0;
}
//traverse each element and print it
void display(LinkedListType *left){
    printf("\nElements of Linked List are:- ");
    printf("\nEID\tEname\n");
    while (left != NULL)
    {
        printf("%d\t%s",left->eId,left->ename);
        left = left->next;
        printf("\n");
    }
}
