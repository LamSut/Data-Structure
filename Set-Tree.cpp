#include <stdio.h>
#include <stdlib.h>
typedef int LabelType;

typedef struct NodeTag {
    LabelType label;
    struct NodeTag *left, *right;
} Node;

typedef Node *Set; //Set is a pointer to root of the tree

void makeNull(Set *pS) {
    *pS = NULL;
}



void printSet(Set *pS) {
    //print the set in format {a1, a2, ..., an}
}

int member(int x, Set *pS) {
    if(*pS==NULL)
        return 0;
    else if((*pS)->label==x)
        return 1;
    else if(x<(*pS)->label)
        return member(x,&(*pS)->left);
    else if(x>(*pS)->label)
        return member(x,&(*pS)->right);
    return 0;
}

void insert(LabelType x, Set *pS) {
    Node *node = *pS;
    Node *parent = NULL;
    while (node != NULL) {
        if (x == node->label) {
            printf("Error: element %d has existed.\n",x);
            return;
        }
        parent = node;
        if (x < node->label)
            node = node->left;
        else
            node = node->right;
    }
    node = (Set)malloc(sizeof(Node));
    node->label = x;
    node->left = NULL;
    node->right = NULL;
    
    if (parent == NULL)
        *pS = node;
    else if (x < parent->label)
        parent->left = node;
    else
        parent->right = node;
}

void traversalAndInsert(Set *pA, Set *pB) {
    if ((*pA) == NULL)
        return;
    insert((*pA)->label, pB);
    traversalAndInsert(&(*pA)->left, pB);
    traversalAndInsert(&(*pA)->right, pB);
}
void setUnion(Set *pA, Set *pB, Set *pC) {
    makeNull(pC);
    traversalAndInsert(pA, pC);
    traversalAndInsert(pB, pC);
}

void traversalTestAndInsert(Set *pA, Set *pB, Set *pC) {
    if ((*pA) == NULL)
        return;
    if (member((*pA)->label, pB))
    insert((*pA)->label, pC);
    traversalTestAndInsert(&(*pA)->left, pB, pC);
    traversalTestAndInsert(&(*pA)->right, pB, pC);
}

void setIntersection(Set *pA, Set *pB, Set *pC) {
    makeNull(pC);
    traversalTestAndInsert(pA, pB, pC);
}

void traversalTestAndInsert1(Set *pA, Set *pB, Set *pC) {
    if ((*pA) == NULL)
        return;
    if (!member((*pA)->label, pB))
        insert((*pA)->label, pC);
    traversalTestAndInsert1(&(*pA)->left, pB, pC);
    traversalTestAndInsert1(&(*pA)->right, pB, pC);
}

void setDifference(Set *pA, Set *pB, Set *pC) {
    makeNull(pC);
    traversalTestAndInsert1(pA, pB, pC);
}

LabelType deleteMin(Set *pS) {

    if ((*pS)->left == NULL) {
        LabelType label = (*pS)->label;
        (*pS) = (*pS)->right;
        return label;
    }
    return deleteMin(&((*pS)->left));
}

void delete(LabelType x, Set *pT) {
    if (*pT == NULL) {
        printf("Error: element %d does not exist.\n", x);
        return;
    }
    if (x < (*pT)->label)
        delete(x, &(*pT)->left);
    else if (x > (*pT)->label)
        delete(x, &(*pT)->right);
    else {
        if ((*pT)->left == NULL && (*pT)->right == NULL) {
            (*pT) = NULL;
            return;
        }
        if ((*pT)->left != NULL && (*pT)->right != NULL) {
            (*pT)->label = deleteMin(&(*pT)->right);
            return;
        }
        if ((*pT)->left != NULL)
            (*pT) = (*pT)->left;
        else
            (*pT) = (*pT)->right;
    }
}

void recursive_assign(Set *pA, Set *pB) {
    if ((*pA) == NULL)
        return;
    insert((*pA)->label, pB);
    recursive_assign(&(*pA)->left, pB);
    recursive_assign(&(*pA)->right, pB);
}

void assign(Set *pA, Set *pB) {
    (*pA) = NULL;               //make null *pA
    recursive_assign(pB, pA);   //insert elements of pB to pA
}

int isSubset(Set *pA, Set *pB) { 
    if(*pA==NULL)
        return 1;
    if(!member((*pA)->label,pB))
        return 0;
    return isSubset(&(*pA)->left,pB);
    return isSubset(&(*pA)->right,pB);
}

int equal(Set *pA, Set *pB) {
    return isSubset(pA, pB) && isSubset(pB, pA);
}

int main(){
	Set S;
	makeNull(&S);
	insert(-41, &S);
	insert(80, &S);
	insert(52, &S);
	insert(33, &S);
	insert(26, &S);
	insert(3, &S);
	printf("S = ");
	printSet(&S);
}


