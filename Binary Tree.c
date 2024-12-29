#include <stdio.h>
#include <stdlib.h>

#define NULL_NODE NULL

typedef char LabelType;

typedef struct NodeTag {
    struct NodeTag *parent;
    struct NodeTag *left;
    struct NodeTag *right;
    LabelType label;
} Node;

typedef Node *Tree;

Tree create0(LabelType v) {
    Node *root = (Tree)malloc(sizeof(Node));
    root->label = v;
    root->parent = root->left = root->right = NULL_NODE;
    return root;
}

Tree create2(LabelType v, Tree T1, Tree T2){
	    Node *T = (Node*) malloc(sizeof(Node));
        T->label=v;
        T->parent=NULL;
        T->right=T2;
        T->left=T1;
        if (T1 != NULL)
        T1->parent = T;
        if (T2 != NULL)
        T2->parent = T;
        return T;
}

void preorder(Tree n){
    if(n!=NULL_NODE){
    printf("%c ",n->label);
    preorder(n->left);
    preorder(n->right);}
}

void inorder(Tree n){
    if(n!=NULL_NODE){
    inorder(n->left);
     printf("%c ",n->label);
    inorder(n->right);}
}

void postorder(Tree n){
    if(n!=NULL_NODE){
    postorder(n->left);
    postorder(n->right);
    printf("%c ",n->label);
    }
}

int main(){
	


