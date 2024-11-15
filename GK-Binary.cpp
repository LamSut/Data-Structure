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
    root->parent = root->left = root->right = NULL;
    return root;
}

Tree create2(LabelType v, Tree T1, Tree T2){
	    Node *T = (Node*) malloc(sizeof(Node));
        T->label=v;
        T->parent=NULL_NODE;
        T->right=T2;
        T->left=T1;
        if (T1 != NULL_NODE)
        T1->parent = T;
        if (T2 != NULL_NODE)
        T2->parent = T;
        return T;
}
Tree copyBinaryTree(Node* n){
    if(n == NULL_NODE)
        return NULL_NODE;
    
    Node* child = create0(n->label);
    
    child->left = copyBinaryTree(n->left);
    child->right = copyBinaryTree(n->right);
    
    return child;
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
int height( Node* n){
    if(!n) return -1;

    int l = height(n->left);
    int r = height(n->right);
    if (l>r) 
		return 1 + l;
    else 
		return 1 + r;

}
int numberOfInteriorNodes(Node *n){
	if(n==NULL_NODE)
	return 0;
	if(n->left==NULL_NODE&&n->right==NULL_NODE)
	return 0;
	return 1 + numberOfInteriorNodes(n->left) + numberOfInteriorNodes(n->right);
}

int main(){
	Node *n0 = (Node*)malloc(sizeof(Node)); n0->label = 'E';

Node *n1 = (Node*)malloc(sizeof(Node)); n1->label = 'C';

Node *n2 = (Node*)malloc(sizeof(Node)); n2->label = 'F';

Node *n3 = (Node*)malloc(sizeof(Node)); n3->label = 'D';

Node *n4 = (Node*)malloc(sizeof(Node)); n4->label = 'B';

Node *n5 = (Node*)malloc(sizeof(Node)); n5->label = 'A';

n0->parent = NULL_NODE;

n0->left = n1; n0->right = n2;

n1->parent = n0;

n1->left = NULL_NODE; n1->right = n3;

n2->parent = n0;

n2->left = NULL_NODE; n2->right = NULL_NODE;

n3->parent = n1;

n3->left = n4; n3->right = NULL_NODE;

n4->parent = n3;

n4->left = NULL_NODE; n4->right = n5;

n5->parent = n4;

n5->left = NULL_NODE; n5->right = NULL_NODE;


printf("#interiors(E) = %d\n", height(n0));

printf("#interiors(C) = %d\n", numberOfInteriorNodes(n1));

printf("#interiors(F) = %d\n", numberOfInteriorNodes(n2));

printf("#interiors(D) = %d\n", numberOfInteriorNodes(n3));

printf("#interiors(B) = %d\n", numberOfInteriorNodes(n4));

printf("#interiors(A) = %d\n", numberOfInteriorNodes(n5));
}

	


