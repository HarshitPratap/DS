#include<stdio.h>
#include<stdlib.h>
//Node declaration for stack and changed its name as QueueNode
typedef struct Node
{
    struct Node *left;
    int info;
    struct Node *right;
}TreeNode;
TreeNode* createNode(int data){
    TreeNode *temp = (TreeNode *)malloc(sizeof(TreeNode));
    if (temp == NULL)
    {
        printf("\nNot enough memory.");
    }else{
        temp->info = data;
        temp->left = temp->right = NULL;
    }
    return temp;
}
void insert(TreeNode **rt,TreeNode *t){
    if ((*rt) == NULL)
    {
        (*rt) = t;
    }else if ((*rt)->info < t->info)
    {
        insert(&((*rt)->right),t);
    }
    else if ((*rt)->info > t->info)
    {
        insert(&((*rt)->left),t);
    } 
}
void countLeafNode(TreeNode *rt,int *ct){
    if(rt != NULL){
        if(rt->left != NULL && rt->right != NULL)
            (*ct)++;
        countLeafNode(rt->left,ct);
        countLeafNode(rt->right,ct);
    }
}

int main(){
    int count = 0;
    TreeNode *rt = NULL;
    TreeNode *t = createNode(100);
    insert(&rt,t);
    t = createNode(200);
    insert(&rt,t);
    t = createNode(300);
    insert(&rt,t);
    t =createNode(400);
    insert(&rt,t);
    t =createNode(250);
    insert(&rt,t);
    t =createNode(50);
    insert(&rt,t);
    countLeafNode(rt,&count);
    printf("%d",count);
    return 0;  
}