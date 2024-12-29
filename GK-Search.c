#include <stdio.h>
#include <math.h>
#include <stdlib.h>
typedef struct CellTag {
    double c; //coefficients
    int e;    //exponents
    
} LabelType;

typedef struct NodeTag {
    LabelType label;
    struct NodeTag *left;
    struct NodeTag *right;
} Node;

typedef Node* Polynomial;

void makeNull(Polynomial* pT){
    *pT=NULL;
}

//insert***
void insert(double c, int e, Polynomial* pT){
    
    if ((*pT) == NULL) {
        Node *root = (Node*)malloc(sizeof(Node));
        root->label.c = c;
        root->label.e = e;
        root->left = NULL;
        root->right = NULL;
        (*pT) = root;
        return;
    }
    
    if (e == (*pT)->label.e)
        printf("The exponent has existed.\n");
    else if (e < (*pT)->label.e)
        insert(c,e, &((*pT)->left));
    else
        insert(c,e, &((*pT)->right));

}

//delete***
LabelType deleteMin(Polynomial *pT) {

    if ((*pT)->left == NULL) {
        LabelType label = (*pT)->label;
        (*pT) = (*pT)->right;
        return label;
    }
    return deleteMin(&((*pT)->left));
}

void deletel(int e, Polynomial *pT) {
    if ((*pT) == NULL) return;
    
    if (e < (*pT)->label.e) 
        deletel(e, &((*pT)->left));
    
    else if (e > (*pT)->label.e) 
        deletel(e, &((*pT)->right));
    
    else {
        if ((*pT)->left == NULL && (*pT)->right == NULL) {
            *pT = NULL;
            return;
        }
        if ((*pT)->left != NULL && (*pT)->right != NULL) {
            (*pT)->label = deleteMin(&((*pT)->right));
            return;
        }

        Node *child;
        if ((*pT)->left == NULL) child = (*pT)->right;
        else child = (*pT)->left;
        (*pT) = child;
    }
}
//coefficient
double coefficient(int e, Polynomial *pT){
    
	if(*pT==NULL)
		return 0;
	else if((*pT)->label.e>e)    
		coefficient(e, &(*pT)->left);
	else if((*pT)->label.e<e)
    	coefficient(e, &(*pT)->right);
	else 
        return (*pT)->label.c; 
}

//evaluate
double evaluate(double val,Polynomial P){
	
    if(P==NULL){
        return 0;
    }
    return pow(val,P->label.e)*P->label.c + evaluate(val,P->left) + evaluate(val,P->right);
}


Polynomial q=NULL;
Polynomial differentiate(Polynomial P){
	if(P==NULL){
		return 0;
	}
	if(P->label.e>0){
		int E=P->label.e;
		double C=P->label.c;
		insert(C*E,E-1,&q);
	}
		
	differentiate(P->left);
	differentiate(P->right);
	return q ;
}

//print

void  order(Polynomial *pT){
    if(*pT!=NULL){
    	order(&(*pT)->left);
     	printf("+ (%.2lf)x^%d ",(*pT)->label.c, (*pT)->label.e);
    	order(&(*pT)->right);
	}

}
void  printPolynomial(Polynomial *pT){
	Node *n= *pT, *p;
	if((*pT)->left==NULL){
		printf("(%.2lf)x^%d ",n->label.c, n->label.e);
		Node *temp = n;
		n=n->right;
		order(&n);
		printf("\n");
		n= temp;
	}
	else {
		while(n->left!=NULL){
			p=n;
			n=n->left;
		}
		printf("(%.2lf)x^%d ",n->label.c, n->label.e);
		Node *temp = p->left;
		p->left=NULL;
		order(pT);
		printf("\n");
		p->left= temp;
	}	
}

int main(){

Node *n1 = (Node*)malloc(sizeof(Node));

Node *n2 = (Node*)malloc(sizeof(Node));

Node *n3 = (Node*)malloc(sizeof(Node));

n1->label.c = 5; n1->label.e = 3;

n2->label.c = 7; n2->label.e = 0;

n3->label.c = 7; n3->label.e = 5;

n1->left = n2; n1->right = n3;

n2->left = n2->right = NULL;

n3->left = n3->right = NULL;

Polynomial P = n1;


double x = 2.0;

printf("P  = "); printPolynomial(&P);

//printf("P(%.2f) = %.2f\n", x, evaluate(x, P));
}
	
