#include<stdio.h>
#include<stdlib.h>
//Node declaration for stack and changed its name as QueueNode
typedef struct Node
{
    struct Node *left;
    int info;
    struct Node *right;
}TreeNode;
TreeNode* createNode(int);
void insert(TreeNode **, TreeNode *);
void inorder(TreeNode *);
void preorder(TreeNode *);
void postorder(TreeNode *);
TreeNode * inorderSucc(TreeNode *);
void deleteNode(TreeNode **, int);
int height(TreeNode *);
int search(TreeNode *,int);
void countNode(TreeNode *,int *);
void countLeafNode(TreeNode *, int *);

int main()
{
    TreeNode *root = NULL,*temp = NULL;
    int data,choice,count = 0;
    do
    {
        printf("\n1.INSERT\n2.INORDER\n3.PREORDER\n4.POSTORDER\n5.DELETE\n6.HEIGHT\n7.SEARCH\n8.COUNT NODES\n9.COUNT LEAF NODE\n10.COUNT NODE OF RIGHT SIDE\n11.EXIT\n");
        printf("Enter Choice:- ");
        scanf("%d",&choice);
        switch (choice)
        {
            case 1:
                printf("\nEnter Data:- ");
                scanf("%d",&data);
                temp = createNode(data);
                if(temp != NULL)
                    insert(&root,temp);
                break;
            case 2:
                printf("\nElements in inorder are:- ");
                if(root != NULL)
                    inorder(root);
                break;
            case 3:
                printf("\nElements in preorder are:- ");
                if(root != NULL)
                    preorder(root);
                break;
            case 4:
                printf("\nElements in postorder are:- ");
                if(root != NULL)
                    postorder(root);
                break;
            case 5:
                if(root != NULL){
                    printf("\nEnter data to be deleted:- ");
                    scanf("%d",&data);
                    deleteNode(&root,data);
                }
                break;
            case 6:
                printf("\nHeight of tree is %d", height(root));
                break;
            case 7:
                if (root != NULL)
                {
                    printf("\nEnter data to search:- ");
                    scanf("%d",&data);
                    data = search(root,data);
                    if (data == 0 )
                    {
                        printf("\nNot found.");
                    }else{
                        printf("\nFound in tree.");
                    }
                }
                break;
            case 8:
                if (root != NULL)
                {
                    countNode(root,&count);
                    printf("Node in tree are %d", count);
                }
                break;
            case 9:
                if (root != NULL)
                {
                    countLeafNode(root,&count);
                    printf("Leaf node in tree are %d", count);
                }
                break;
            case 10:
                if (root != NULL)
                {
                    countNode(root->right,&count);
                    printf("Node in right tree are %d", count);
                }
                break;
            case 11:
                exit(0);
                break;
            default:
                printf("\nEnter valid choice.");
                break;
        }
    } while (choice < 7);
    
    return 0;
}
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
void inorder(TreeNode *rt){
    if(rt != NULL){
        inorder(rt->left);
        printf("%d ",rt->info);
        inorder(rt->right);
    }
}
void preorder(TreeNode *rt){
    if(rt != NULL){
        printf("%d ",rt->info);
        preorder(rt->left);
        preorder(rt->right);
    }
}
void postorder(TreeNode *rt){
    if(rt != NULL){
        postorder(rt->left);
        postorder(rt->right);
        printf("%d ",rt->info);
    }
}
TreeNode * inorderSucc(TreeNode *rt){
    TreeNode *curr = rt->right;
    while (curr && curr->left != NULL)
    {
        curr = curr->left;
    }
    return curr;
}
void deleteNode(TreeNode **rt,int data){
    TreeNode *t = NULL;
    if ((*rt) == NULL)
    {
        return;
    }else if((*rt)->info > data){
        deleteNode(&((*rt)->left),data);
    }else if((*rt)->info < data){
        deleteNode(&((*rt)->right),data);
    }else{
        if ((*rt)->right == NULL)
        {
           t = (*rt)->left;
           (*rt)->left =(*rt)->left->left;
           free(t);  
        }else if ((*rt)->left == NULL)
        {
            t = (*rt)->right;
           (*rt)->right =(*rt)->right->right;
           free(t);
        }else{
            t = inorderSucc(*rt);
            (*rt)->info = t->info;
            deleteNode(&((*rt)->right),t->info);
        }       
    }
}

int height(TreeNode *rt){
    int lh,rh;
    if(rt == NULL)
        return 0;
    lh = height(rt->left);
    rh = height(rt->right);
    if (lh > rh)
    {
        return lh + 1;
    }else{
        return rh + 1;
    }  
}

int search(TreeNode *rt,int data){
    if (rt == NULL)
    {
        return 0;
    }
    if (rt->info == data)
    {
        return 1;
    }
    if (rt->info < data)
    {
        search(rt->right, data);
    }else if(rt->info > data){
        search(rt->left, data);
    }
    
}

void countNode(TreeNode *rt,int *ct){
    if(rt != NULL){
        countNode(rt->left,ct);
        ++(*ct);
        countNode(rt->right,ct);
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