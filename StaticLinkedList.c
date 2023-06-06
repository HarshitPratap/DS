#include<stdio.h>
typedef struct StaticLinkedList
{
    int info;
    struct StaticLinkedList* next;
}LinkedList;

int main()
{
    LinkedList a,b,c,d;
    LinkedList *head,*temp;
    printf("Enter data of node a:- ");
    scanf("%d",&a.info);
    printf("Enter data of node b:- ");
    scanf("%d",&b.info);
    printf("Enter data of node c:- ");
    scanf("%d",&c.info);
    printf("Enter data of node d:- ");
    scanf("%d",&d.info);
    head = &a;
    a.next = &b;
    b.next = &c;
    c.next = &d;
    d.next = NULL;
    temp = head;
    while (temp != NULL)
    {
        printf("%d, ",temp->info);
        temp = temp->next;
    }
    return 0;
}
