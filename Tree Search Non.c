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

void insert(LabelType x, Tree *pT) {
    if (*pT == NULL) {
        Node *root = (Node*)malloc(sizeof(Node));
        root->label = x;
        root->left = NULL_NODE;
        root->right = NULL_NODE;
        (*pT) = root;
        return;
    }

    Node *node = *pT, *parent;
    while (node != NULL) {
        parent = node;
        if (x == node->label)
            return;
        if (x < node->label)
            node = node->left;
        else
            node = node->right;
    }


    Node *child = (Node*)malloc(sizeof(Node));
    child->label = x;
    if (x < parent->label)
        parent->left = child;
    else
        parent->right = child;

}
LabelType deleteMax(Tree *pT) {
    if ((*pT)->right == NULL_NODE) {
        LabelType label = (*pT)->label;
        (*pT) = (*pT)->left;
        return label;
    }
    return deleteMax(&((*pT)->right));
}

void delete(LabelType x, Tree *pT) {
    if ((*pT) == NULL_NODE) return;
    
    if (x < (*pT)->label) 
        delete(x, &((*pT)->left));
    
    else if (x > (*pT)->label) 
        delete(x, &((*pT)->right));
    
    else {
        if ((*pT)->left == NULL_NODE && (*pT)->right == NULL_NODE) {
            *pT = NULL_NODE;
            return;
        }
        if ((*pT)->left != NULL_NODE && (*pT)->right != NULL_NODE) {
            (*pT)->label = deleteMax(&((*pT)->left));
            return;
        }
        Node *child;
        if ((*pT)->left == NULL_NODE) 
        child = (*pT)->right;
        else child = (*pT)->left;
        (*pT) = child;
    }
}

int main(){
	
}
	


