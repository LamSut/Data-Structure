#include<stdio.h>
#include<stdlib.h>
#define B 5

typedef int ElementType;

typedef struct CellTag {
    ElementType element;
    struct CellTag *next;
} Cell;

typedef Cell *Position;

typedef struct {
    Position buckets[B];
} HashTable;

int h(ElementType x) {
    return ((x % B) + B) % B; //(= x % B), avoid neagtive result
}

void makeNull(HashTable *pT){
    int i=0;
	for(i; i<B; i++)
        pT->buckets[i] = NULL;
}

int member(ElementType x, HashTable *pT) {
    int i = h(x);
    Position p = pT->buckets[i];
    while (p != NULL) {
        if (x == p->element)
            return 1;
        p = p->next;
    }
    return 0;
}

void insert (ElementType x, HashTable *pT){
    int i= h(x);
    if (member(x, pT)) 
        printf("%d has already existed in the hash table, ignore.\n",x);
    else {
        Position del= pT->buckets[i];
        pT->buckets[i] = (Cell*) malloc(sizeof(Cell));
        pT->buckets[i]->element = x;
        pT->buckets[i]->next = del;
    }
}

void delete(ElementType x, HashTable *pT){
    int i= h(x);
    if(pT->buckets[i]==NULL)
        return;
    if (x == pT->buckets[i]->element) {
        Position del = pT->buckets[i];
        pT->buckets[i] = del->next;
        free(del);
        return;
    }
    Position p= pT->buckets[i];
    while(p->next!=NULL){
        if (x == p->next->element){
            Position del1 = p->next;
            p->next = del1->next;
            free(del1);
            return;
        }
        p = p->next;
    }
    printf("%d does not exist, ignore.\n",x);
}

void printHashTable(HashTable *pT){
	int i=0;
	for(i;i<B;i++){
		printf("bucket[%d]: ",i);
		printf("%d ",pT->buckets[i]->element);
		Position p= pT->buckets[i];
		while(p->next!=NULL){
        	printf("%d ",p->next->element);
        	p = p->next;
    	}
    	printf("\n");
	}
}

int main(){
	HashTable T;
	makeNull(&T);
	int A[20] = {29, 39, 37, 19, 49, 34, -1, -29, 23, -49, -42, -26, -13, 33, -30, 14, 16, -9, -7, 32};
	int n = 20;
	int i=0;
	for (i = 0; i < n; i++)
	    insert(A[i], &T);
	printHashTable(&T);
	int D[20] = {33, -11, -14, 10, 34, -8, -3, -13, 16, 29};
	n = 10;
	for (i = 0; i < n; i++) {
	    delete(D[i], &T);
	}
	printHashTable(&T);
}


