#include<stdio.h>
#include<stdlib.h>

typedef struct Node{
    int dest;
    int pro;
    struct Node *next;
}GraphNode;

typedef struct ListNode{
    GraphNode *head;
}AdjListHead;

typedef struct GraphHeadNode
{
   int ver;
   AdjListHead *array;
}GraphHead;

GraphHead * createHead(int);
GraphNode * createNewNode(int);
void addEdge(GraphHead *, int, int);
void display(GraphHead *);
void DFS(GraphHead *,int);
int main()
{
    int V = 5;
    GraphHead *ghead = createHead(V);
    
    addEdge(ghead,0,1);
    //printf("%d",ghead->array[0].head->dest);
    addEdge(ghead,0,2);
    //printf("%d",ghead->array[0].head->next->dest);
    addEdge(ghead,0,3);
    addEdge(ghead,3,4);
    //printf("%d",ghead->array[2].head->dest);
    addEdge(ghead,1,2);
    addEdge(ghead,2,3);
    display(ghead);
    DFS(ghead,0);
    return 0;
}

//create head of graph

GraphHead * createHead(int v){
    int i = 0;
    GraphHead *gh = (GraphHead *) malloc(sizeof(GraphHead));
    gh->ver = v;
    gh->array = (AdjListHead *) malloc(sizeof(AdjListHead) * v);
    for (i = 0; i < v; i++)
    {
        gh->array[i].head = NULL;
    }
    return gh;
}

GraphNode* createNewNode(int dest){
    GraphNode *newNode = (GraphNode*)malloc(sizeof(GraphNode));
    newNode->dest = dest;
    newNode->pro = 0;
    newNode->next = NULL;
    return newNode;
}

void addEdge(GraphHead *g,int s, int d){
    GraphNode *curr = NULL;
    GraphNode *newNode = createNewNode(d);
    if(g->array[s].head == NULL){
        newNode->next = g->array[s].head;
        g->array[s].head = newNode;
    }else{
        curr = g->array[s].head;
        while (curr->next != NULL)
        {
            curr = curr->next;
        }
        curr->next = newNode;
    }
    newNode = createNewNode(s);
    if(g->array[d].head == NULL){
        newNode->next = g->array[d].head;
        g->array[d].head = newNode;
    }else{
        curr = g->array[d].head;
        while (curr->next != NULL)
        {
            curr = curr->next;
        }
        curr->next = newNode;
    }
}

void display(GraphHead* g){
    int v = 0;
    for ( v = 0; v < g->ver; v++)
    {
        GraphNode *h = g->array[v].head;
        printf("\nEdge from %d vertex are:-\nhead",v);
        while (h)
        {
            printf(" -> %d",h->dest);
            h = h->next;
        }
        printf("\n");
    } 
}

void DFS(GraphHead* g, int s){
    GraphNode *c = NULL;
    int st[g->ver];
    int top = -1;
    st[++top] = s;
    while (top != -1)
    {
        c = g->array[st[top--]].head;
        if (c->pro == 0)
        {
            c->pro = 1;
            printf("%d, ",c->dest);
        }
        c=c->next;
        printf("\n");
        while (c != NULL)
        {
            st[++top] = c->dest;
            printf("%d,",st[top]);
            c = c->next;   
        }        
    }
}