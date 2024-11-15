#include<stdio.h>
#include<stdlib.h>

#define NULL_NODE NULL

typedef char LabelType;

typedef struct NodeTag {
    struct NodeTag *parent;
    struct NodeTag *leftmost_child;
    struct NodeTag *right_sibling;
    LabelType label;
} Node;

typedef Node *Tree; //Tree is a pointer to the root

void makeNull(Tree *pT){
    *pT=NULL_NODE;
}

int empty(Tree *pT){
    if(*pT==NULL_NODE){
    return 1;}
    return 0;
}

Node* parent(Node *n){
    if(n==NULL){
        return NULL_NODE;
    }
    return n->parent;
}

Node * leftmostChild(Node* n){
    if(n==NULL){
        return NULL_NODE;
    }
    return n->leftmost_child;
}

Node * rightSibling(Node* n){
    if(n==NULL){
        return NULL_NODE;
    }
    return n->right_sibling;
}

LabelType label(Node* n){
    if(n==NULL){
        return '?';
    }
    return n->label;
}

void preorder(Node *n){

        printf("%c ",label(n));
        Node* i= leftmostChild(n);
        while(i!=NULL_NODE){
            preorder(i);
            i=rightSibling(i);
        }
    
}

void postorder(Node *n){
        Node* i= leftmostChild(n);
        while(i!=NULL_NODE){
            postorder(i);
            i=rightSibling(i);
        }
        printf("%c ",label(n));
}

void inorder(Node* n){
        Node* i= leftmostChild(n);
        if(i!=NULL_NODE){
            inorder(i);
        }
        printf("%c ",label(n));
        i=rightSibling(i);
        while(i!=NULL_NODE){
            inorder(i);
            i=rightSibling(i);
        }
}

int height( Node* n){
    if(n== NULL_NODE) return -1;
    if(leftmostChild(n)==NULL_NODE && rightSibling(leftmostChild(n))== NULL_NODE) return 0;
    else{
        int l = height(leftmostChild(n));
        int r = height(rightSibling(leftmostChild(n)));
        if (l>r) return 1 + l;
        else return 1 + r;
    }
}

int depth(Node* n){
	if(n==NULL_NODE){
		return -1;
	}
	int d=0;
    while(n!=NULL_NODE){
    	n=n->parent;
		d++;
	}
	return d-1;
}

Tree create0(LabelType v){
    Node *n = (Node*) malloc(sizeof(Node));
    n->label=v;
    n->leftmost_child=NULL;
    n->right_sibling=NULL;
    return n;
}

Tree create1(LabelType v, Node * T1){
    if(T1==NULL_NODE){
        printf("Error: T1 is null, cannot create1.\n");
    }
    else{
	Tree n = (Tree) malloc(sizeof(Node));
    n->label=v;
    n->parent=NULL;
    n->right_sibling=NULL;
    n->leftmost_child=T1;
    T1->parent=n;
    T1->right_sibling=NULL;
    return n; }
    
    return 0;
}

Tree create2(LabelType v, Tree T1, Tree T2){
    if(T1==NULL_NODE){
        printf("Error: T1 or T2 is null, cannot create2.\n");
    }
    Node *n = (Node*) malloc(sizeof(Node));
    n->label=v;
    n->parent=NULL;
    n->right_sibling=NULL;
    n->leftmost_child=T1;
    T1->parent=n;
    T2->parent=n;
    T1->right_sibling=T2;
    T2->right_sibling=NULL;
    return n;
}



Node * locate(LabelType v, Node *n){
    if(n==NULL_NODE){
        return NULL_NODE;
    }
    if(n->label==v){
                return n;
    }
        Node* i= n->leftmost_child;
        while(i!=NULL_NODE){
            locate(v,i);
            i=i->right_sibling;
        }
    return NULL_NODE;
}

int main(){
Node *n0 = (Node*)malloc(sizeof(Node));
n0->label = 'B';
Node *n1 = (Node*)malloc(sizeof(Node));
n1->label = 'O';
Node *n2 = (Node*)malloc(sizeof(Node));
n2->label = 'C';
Node *n3 = (Node*)malloc(sizeof(Node));
n3->label = 'V';
Node *n4 = (Node*)malloc(sizeof(Node));
n4->label = 'F';
Node *n5 = (Node*)malloc(sizeof(Node));
n5->label = 'T';
Node *n6 = (Node*)malloc(sizeof(Node));
n6->label = 'N';
Node *n7 = (Node*)malloc(sizeof(Node));
n7->label = 'P';
Node *n8 = (Node*)malloc(sizeof(Node));
n8->label = 'J';
Node *n9 = (Node*)malloc(sizeof(Node));
n9->label = 'I';
Node *n10 = (Node*)malloc(sizeof(Node));
n10->label = 'S';
Node *n11 = (Node*)malloc(sizeof(Node));
n11->label = 'Y';
Node *n12 = (Node*)malloc(sizeof(Node));
n12->label = 'D';
Node *n13 = (Node*)malloc(sizeof(Node));
n13->label = 'U';
Node *n14 = (Node*)malloc(sizeof(Node));
n14->label = 'G';
Node *n15 = (Node*)malloc(sizeof(Node));
n15->label = 'K';
Node *n16 = (Node*)malloc(sizeof(Node));
n16->label = 'A';
Node *n17 = (Node*)malloc(sizeof(Node));
n17->label = 'W';
n0->parent = NULL_NODE;
n0->leftmost_child = n1;
n0->right_sibling = NULL_NODE;
n1->parent = n0;
n1->leftmost_child = n4;
n1->right_sibling = n2;
n2->parent = n0;
n2->leftmost_child = n5;
n2->right_sibling = n3;
n3->parent = n0;
n3->leftmost_child = NULL_NODE;
n3->right_sibling = NULL_NODE;
n4->parent = n1;
n4->leftmost_child = NULL_NODE;
n4->right_sibling = NULL_NODE;
n5->parent = n2;
n5->leftmost_child = n6;
n5->right_sibling = NULL_NODE;
n6->parent = n5;
n6->leftmost_child = n9;
n6->right_sibling = n7;
n7->parent = n5;
n7->leftmost_child = n13;
n7->right_sibling = n8;
n8->parent = n5;
n8->leftmost_child = n14;
n8->right_sibling = NULL_NODE;
n9->parent = n6;
n9->leftmost_child = n15;
n9->right_sibling = n10;
n10->parent = n6;
n10->leftmost_child = NULL_NODE;
n10->right_sibling = n11;
n11->parent = n6;
n11->leftmost_child = NULL_NODE;
n11->right_sibling = n12;
n12->parent = n6;
n12->leftmost_child = n16;
n12->right_sibling = NULL_NODE;
n13->parent = n7;
n13->leftmost_child = NULL_NODE;
n13->right_sibling = NULL_NODE;
n14->parent = n8;
n14->leftmost_child = NULL_NODE;
n14->right_sibling = NULL_NODE;
n15->parent = n9;
n15->leftmost_child = NULL_NODE;
n15->right_sibling = NULL_NODE;
n16->parent = n12;
n16->leftmost_child = NULL_NODE;
n16->right_sibling = n17;
n17->parent = n12;
n17->leftmost_child = NULL_NODE;
n17->right_sibling = NULL_NODE;

test_locate('V', n0);
test_locate('I', n0);
test_locate('K', n0);
test_locate('S', n0);
test_locate('U', n0);
test_locate('M', n0);
test_locate('W', n0);
test_locate('C', n0);
test_locate('G', n0);
test_locate('Q', n0);
test_locate('J', n0);
test_locate('A', n0);
test_locate('I', n0);
test_locate('K', n0);
test_locate('R', n0);
test_locate('Y', n0);
test_locate('J', n0);
test_locate('K', n0);	
}
