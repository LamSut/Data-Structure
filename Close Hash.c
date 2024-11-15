#include<stdio.h>
#include<stdlib.h>

#define B 20
#define EMPTY   -9788
#define DELETED 9097

typedef int ElementType;

typedef struct {
    ElementType buckets[B];
} HashTable;

int h(ElementType x) {
    return ((x % B) + B) % B;
}

void makeNull(HashTable *pT) {
    int i;
	for (i=0; i<B; i++)
        pT->buckets[i] = EMPTY;
}

int locate(ElementType x, HashTable *pT) {
    int initial = h(x);
    int i = 0;
    while (i < B && pT->buckets[(initial + i)%B] != x && pT->buckets[(initial + i)%B] != EMPTY)
    i++;
    return (initial + i)%B;
}

int member(ElementType x, HashTable *pT){
    int i = locate(x, pT);
    return pT->buckets[i] == x;
}

int locate1(ElementType x, HashTable *pT) {
    int initial = h(x);
    int i = 0;
    while (i < B && pT->buckets[(initial + i)%B] != x && pT->buckets[(initial + i)%B] != EMPTY && pT->buckets[(initial + i)%B] != DELETED)
        i++;
    return (initial + i)%B;
}


void insert(ElementType x, HashTable *pT) {
    int i = locate1(x, pT);
    if(pT->buckets[i]==x)
        return;
    if (pT->buckets[i] == EMPTY || pT->buckets[i] == DELETED) {
        pT->buckets[i] = x;
    } 
    else
        return;
}

void delete(ElementType x, HashTable *pT) {
    int i = locate(x,pT);
    if(pT->buckets[i]==x)
        pT->buckets[i]= DELETED;
}

printHashTable(HashTable *pT){
	int i = 0;
	for(i;i<B;i++){
		printf("%d ",pT->buckets[i]);
	}
	printf("\n");
}

int main(){
	HashTable T;
	makeNull(&T);
	int A[] = {-17, -52, 67, 66, -57, -61, -19, 45, 21, -46, 7, 85};
	int n = 12;
	int i;
	for (i = 0; i < n; i++)
	    insert(A[i], &T);
	printHashTable(&T);
	printf("===\n");
	int D[] = {-84, -23, 66, 75, 45, 7};
	n = 6;
	for (i = 0; i < n; i++)
	    delete(D[i], &T);
	printHashTable(&T);
}

