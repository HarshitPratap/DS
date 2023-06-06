#include<stdio.h>
#include<stdlib.h>

typedef struct Node
{
    int info;
    struct Node *next;
}CLListNode;
CLListNode * insertAtLast(CLListNode *, int data);
CLListNode * insertAtFirst(CLListNode *, int data);
CLListNode * deleteLast(CLListNode *);
CLListNode * deleteFirst(CLListNode *); 
void display(CLListNode *);
int main()
{
    CLListNode *tail = NULL;
    int choice,data;
    do
    {
        printf("\n1.INSERTFIRST\n2.INSERTLAST\n3.DELETEFIRST\n4.DELETELAST\n5.DISPLAY\n6.EXIT");
        printf("\nPlease enter your choice:- ");
        scanf("%d",&choice);
        switch (choice)
        {
        case 1:
            //Asking for data from user
            printf("\nEnter data to insert:- ");
            scanf("%d",&data);
            //calling function
            tail = insertAtFirst(tail,data);
            break;
        case 2:
            //Asking for data from user
            printf("\nEnter data to insert:- ");
            scanf("%d",&data);
            //calling function
            tail = insertAtLast(tail,data);
            break;
        case 3:
            //checking list is empty or not
            if(tail == NULL){
                printf("\nList underflow.");
            }else{
                //calling function
                tail = deleteFirst(tail);
            }
            break;
        case 4:
            //checking list is empty or not
            if(tail == NULL){
                printf("\nList underflow.");
            }else{
                //calling function
                tail = deleteLast(tail);
            }
            break;
        case 5:
            //checking list is empty or not
            if(tail == NULL){
                printf("\nList underflow.");
            }else{
                //calling function
                display(tail);
            }
            break;
        case 6:
            exit(0);
        default:
            printf("\nPlease enter a valid choice");
            break;
        }//end of switch
    } while (1);//end of while
    return 0;
}//end of main

void display(CLListNode *tail){
    CLListNode *temp = tail;
    do
    {
        printf("%d",temp->info);
        temp = temp->next;
        if (temp != tail)
        {
            printf(", ");
        }
        
    } while (temp != tail);
    printf("\n");
}

CLListNode* deleteFirst(CLListNode *tail){
    CLListNode *temp = tail->next;
    printf("\nData deleted is %d.",temp->info);
    if (tail == tail->next)
    {
        tail = NULL;
    }else{
        tail->next = temp->next;
    }
    free(temp);
    return tail;
}

CLListNode* deleteLast(CLListNode *tail){
    CLListNode *temp = tail;
    printf("\nData to be deleted is %d.",temp->info);
    if (tail == tail->next)
    {
        tail = NULL;
        free(temp);
    }else{
        while (temp->next != tail)
        {
            temp = temp->next;
        }
        temp->next = tail->next;
        tail = temp;
    }
    return tail;
}

CLListNode* insertAtLast(CLListNode* tail,int data){
    CLListNode* temp = (CLListNode *)malloc(sizeof(CLListNode));
    if (temp == NULL)
    {
        printf("\nInsuficient storage.");
    }else{
        temp->info = data;
        if(tail == NULL){
            tail = temp;
            tail->next = temp;
        }else{
            temp->next = tail->next;
            tail->next = temp;
            tail = temp;
        } 
    }
   return tail; 
}

CLListNode* insertAtFirst(CLListNode *tail,int data){
    CLListNode* temp = (CLListNode *)malloc(sizeof(CLListNode));
    if (temp == NULL)
    {
        printf("\nInsuficient storage.");
    }else{
        temp->info = data;
        if(tail == NULL){
            tail = temp;
            tail->next = temp;
        }else{
            temp->next = tail->next;
            tail->next = temp;
        } 
    }
   return tail; 
}
