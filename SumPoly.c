#include<stdio.h>
#include<stdlib.h>
//Node declaration for polynomials and changed its name as QueueNode
typedef struct Node
{
    int co,exp;
    struct Node *next;
}QueueNode;
//function declaration
int isEmpty(QueueNode*);
void display(QueueNode*);
void push(QueueNode**,int,int);
void addPoly(QueueNode*,QueueNode*,QueueNode**);

int main()
{
    //required variables declarations
    QueueNode *poly1 = NULL,*poly2 = NULL, *sum = NULL;
    int co,exp,choice = 0;
    do{
        printf("\nEnter cofficient of 1st polynomial:- ");
        scanf("%d",&co);
        printf("Enter exponent of 1st polynomial:- ");
        scanf("%d",&exp);
        push(&poly1,co,exp);
    }while(exp != 0);
    do{
        printf("\nEnter cofficient of 2nd polynomial:- ");
        scanf("%d",&co);
        printf("Enter exponent of 2nd polynomial:- ");
        scanf("%d",&exp);
        push(&poly2,co,exp);
    }while(exp != 0);
    addPoly(poly1,poly2,&sum);
    printf("\nPolynomial 1:- ");
    display(poly1);
    printf("\nPolynomial 2:- ");
    display(poly2);
    printf("\nPolynomial sum:- ");
    display(sum);
    return 0;
}
//isEmpty function return one if there is no any elements in stack
//take one argument that is address of last element of stack
int isEmpty(QueueNode *top){
    return top == NULL;
}

//push is used to push element in last of stack
//take two argument that is address of address of last element of stack and data to be pushed
void push(QueueNode **head,int co, int exp){
    QueueNode *curr = NULL;
    QueueNode *temp = (QueueNode *) malloc(sizeof(QueueNode));
    if(temp == NULL){
        printf("\nNot enough memory.");
    }else{
        temp->co = co;
        temp->exp = exp;
        temp->next = NULL;
        if(*head == NULL){
            *head = temp;
        }else if(exp > (*head)->exp && *head != NULL){
            temp->next = *head;
            *head = temp;
        }else{
            curr = *head;
            while (curr->next != NULL && curr->exp >= exp)
            {
                curr = curr->next;
            }
            temp->next = curr->next;
            curr->next = temp;
        }
    }
}
//display return nothing take one argument which is address of last element of stack
//traverse each element and print it
void display(QueueNode *left){
    while (left != NULL)
    {
        printf("%d^%d",left->co,left->exp);
        left = left->next;
        if (left != NULL)
        {
            printf(", ");
        } 
    }
    printf("\n");
}


void addPoly(QueueNode *p1,QueueNode *p2,QueueNode **sum ){
    QueueNode *res = NULL;

    // if (*sum == NULL)
    // {
    //     *sum = (QueueNode *)malloc(sizeof(QueueNode *));
    //     res = *sum;
    // }else{
    //     res->next = (QueueNode *)malloc(sizeof(QueueNode *));
    //     res = res->next;
    // }
    
    if (p1 != NULL && p2 == NULL)
    {
        *sum = p1;
        return;
    }

    if (p1 == NULL)
    {
        *sum = p2;
        return;
    }

    while (p1 != NULL && p2 != NULL)
    {
        if (*sum == NULL)
        {
            *sum = (QueueNode *)malloc(sizeof(QueueNode *));
            res = *sum;
        }else{
            res->next = (QueueNode *)malloc(sizeof(QueueNode *));
            res = res->next;
        }
        //if the exponent of poly1 greater than poly2  add poly2 in  result
        if (p1->exp > p2->exp)
        {
            res->co = p1->co;
            res->exp = p1->exp;
            p1 = p1->next;
        }
        //if the exponent of poly 2 greater than poly1  add poly2 in  result
        else if (p1->exp < p2->exp)
        {
            res->co = p2->co;
            res->exp = p2->exp;
            p2 = p2->next;
        }
        //if both the exponent is same add both and store in result 
        else if (p1->exp ==  p2->exp)
        {
            res->co = p1->co + p2->co;
            res->exp = p1->exp;
            p1 = p1->next;
            p2 = p2->next;
        }
           
    }//end of while
    //run loop to add rest of the elements to result of polynomial 1
    while (p1 != NULL)
    {
        res->next = (QueueNode *)malloc(sizeof(QueueNode *));
        res = res->next;
        res->co = p1->co;
        res->exp = p1->exp;
        p1 = p1->next;
        
    }
    //run loop to add rest of the elements to result of polynomial 2
    while (p2 != NULL)
    {
        res->next = (QueueNode *)malloc(sizeof(QueueNode *));
        res = res->next;
        res->co = p2->co;
        res->exp = p2->exp;
        p2 = p2->next;
    }
    res->next = NULL;   
}//end of sum
