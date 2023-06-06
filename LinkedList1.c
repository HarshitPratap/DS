#include<stdio.h>
#include<stdlib.h>
#include "./Node.c"


int main()
{
    Node *temp = NULL,*tail = NULL;
    int data,choice;
    while (1)
    {
        temp = (Node *) malloc(sizeof(Node));
        if(temp == NULL){
            printf("Insufficient Memory.");
            break;
        }
        printf("Enter data:- ");
        scanf("%d",&data);
        temp->data = data;
        temp->next = tail;
        tail = temp;
        printf("Do you want to add more press 1 else press 0.");
        scanf("%d",&choice);
        if (choice == 0)
        {
            break;
        }
    }
    temp = tail;
    while (temp != NULL)
    {
        printf("%d, ",temp->data);
        temp = temp->next;
    }
    free(temp);
    free(tail);
    return 0;
}
