#include<stdio.h>
#define N 30

typedef struct {
    unsigned char data[N];
} Set;

void makeNull(Set *pS){
    int i;
	for(i=0; i<N; i++)
        pS->data[i] = 0;
}

int member(int x, Set *pS) {
    int i = x / 8;
    int j = x % 8;
    return pS->data[i] & (1 << j);
}

void insert(int x, Set *pS) {
    if((member(x,pS)))
        printf("Error: element %d has existed.\n",x);
    int i = x / 8;
    int j = x % 8;
    pS->data[i] |= (1 << j);

}

void delete(int x, Set *pS) {
    if(!(member(x,pS)))
        printf("Error: element %d does not exist.\n",x);
    else{
    int i = x / 8;
    int j = x % 8;
    pS->data[i] &= ~(1 << j);
    }
}

void setDifference(Set *pA, Set *pB, Set *pC) {
    int i;
	for (i = 0; i < N; i++)
        pC->data[i] = pA->data[i] & ~pB->data[i];
}

void setIntersection(Set *pA, Set *pB, Set *pC) {
	int i;
	for (i = 0; i < N; i++)
	pC->data[i] = pA->data[i] & pB->data[i];
}

void setUnion(Set *pA, Set *pB, Set *pC) {
	int i;
	for (i = 0; i < N; i++)
	pC->data[i] = pA->data[i] | pB->data[i];
}

int main(){
Set S;
makeNull(&S);
insert(270, &S);
insert(9, &S);
insert(101, &S);
insert(32, &S);
insert(96, &S);
insert(48, &S);
insert(187, &S);
insert(96, &S);
insert(225, &S);
insert(247, &S);
insert(275, &S);
insert(288, &S);
insert(175, &S);
insert(110, &S);
insert(224, &S);
int i;
for (i = 0; i < 39; i++)
    printf("%d ", S.data[i]);
printf("\n");
delete(52, &S);
delete(17, &S);
delete(32, &S);
delete(252, &S);
delete(135, &S);
delete(171, &S);
delete(62, &S);
delete(281, &S);
delete(145, &S);
delete(287, &S);
delete(277, &S);
delete(213, &S);
delete(278, &S);
delete(216, &S);
delete(226, &S);
delete(283, &S);
delete(133, &S);
delete(218, &S);
delete(145, &S);

for (i = 0; i < 39; i++)
    printf("%d ", S.data[i]);

}	
