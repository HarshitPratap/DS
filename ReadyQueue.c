#include<stdio.h>
#include<stdlib.h>
#define MAX 4
typedef struct Node
{
    int id;
    int info;
    struct Node *next;
}CLListNode;
void insertAtLast(CLListNode **, CLListNode *);
void deleteFirst(CLListNode **); 
void display(CLListNode **);

int main()
{
    int time;
    CLListNode *tail = NULL;
    int i;
    for ( i = 0; i < MAX; i++)
    {
        printf("\nEnter cpu time of process %d:- ",i+1);
        scanf("%d",&time);
        CLListNode* temp = (CLListNode *)malloc(sizeof(CLListNode));
        if (temp == NULL)
        {
            printf("\nInsuficient storage.");
        }else{
            temp->info = time;
            temp->id = i + 1;
            insertAtLast(&tail,temp);
        }
    }
    display(&tail);
    return 0;
}//end of main

void display(CLListNode **tail){
    CLListNode *temp = (*tail)->next;
    int time = 0;
    
    while(temp != NULL){
        
        if ((temp->info) > 10)
        {
            time += 10;
            temp->info = (temp->info) - 10;    
        }else{
            time += temp->info;
            temp->info = 0;
        }
        if (temp->info != 0)
        {
            deleteFirst(tail);
            insertAtLast(tail,temp);
        }else{
            deleteFirst(tail);
            printf("\nProcess %d completes in %d unit time.",temp->id,time);
        }
        if (*tail == NULL)
        {
            break;
        }else{
            temp = (*tail)->next;
        }
    }
    printf("\n");
}

void deleteFirst(CLListNode **tail){
    if (*tail == (*tail)->next)
    {
        *tail = NULL;
    }else{
        (*tail)->next = (*tail)->next->next;
    }
}

void insertAtLast(CLListNode** tail,CLListNode *temp){
    if(*tail == NULL){
        *tail = temp;
        (*tail)->next = temp;
    }else{
        temp->next = (*tail)->next;
        (*tail)->next = temp;
        *tail = temp;
    }
}
