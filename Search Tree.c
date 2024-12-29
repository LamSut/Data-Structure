#include <stdio.h>
#include <stdlib.h>

#define NULL_NODE NULL

typedef int LabelType;

typedef struct NodeTag {
    struct NodeTag *parent;
    struct NodeTag *left;
    struct NodeTag *right;
    LabelType label;
} Node;

typedef Node *Tree;

void makeNull(Tree* pT){
    *pT=NULL_NODE;
}

void preorder(Tree n){
    if(n!=NULL_NODE){
    printf("%d ",n->label);
    preorder(n->left);
    preorder(n->right);}
}

void inorder(Tree n){
    if(n!=NULL_NODE){
    inorder(n->left);
     printf("%d ",n->label);
    inorder(n->right);}
}

void postorder(Tree n){
    if(n!=NULL_NODE){
    postorder(n->left);
    postorder(n->right);
    printf("%d ",n->label);}
}

void insert(LabelType x, Tree* pT){
    
    if ((*pT) == NULL) {
        Node *root = (Node*)malloc(sizeof(Node));
        root->label = x;
        root->left = NULL_NODE;
        root->right = NULL_NODE;
        (*pT) = root;
        return;
    }
    
    if (x == (*pT)->label)
        printf("Error: %d has existed in the tree. Cannot insert.\n",x);
    else if (x < (*pT)->label)
        insert(x, &((*pT)->left));
    else
        insert(x, &((*pT)->right));

}

LabelType deleteMin(Tree *pT) {

    if ((*pT)->left == NULL_NODE) {
        LabelType label = (*pT)->label;
        (*pT) = (*pT)->right;
        return label;
    }
    return deleteMin(&((*pT)->left));
}

void deletel(LabelType x, Tree *pT) {
    if ((*pT) == NULL_NODE) return;
    
    if (x < (*pT)->label) 
        deletel(x, &((*pT)->left));
    
    else if (x > (*pT)->label) 
        deletel(x, &((*pT)->right));
    
    else {
        if ((*pT)->left == NULL_NODE && (*pT)->right == NULL_NODE) {
            *pT = NULL_NODE;
            return;
        }
        if ((*pT)->left != NULL_NODE && (*pT)->right != NULL_NODE) {
            (*pT)->label = deleteMin(&((*pT)->right));
            return;
        }

        Node *child;
        if ((*pT)->left == NULL_NODE) child = (*pT)->right;
        else child = (*pT)->left;
        (*pT) = child;
    }
}

int main(){
	Tree T = NULL;
int A[] = {69, 91, 93, 77, 4, 85};
int n = 6;
for (int i = 0; i < n; i++)
    insert(A[i], &T);
postorder(T);
}
	


