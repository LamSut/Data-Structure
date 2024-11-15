#define N 32

typedef struct {
    char data[N];
} Set;

int member(int x, Set *pS) {
    return (pS->data[x] == 1);
}

void delete(int x, Set *pS) {
    if(pS->data[x] == 0)
        printf("Error: element %d does not exist.\n",x);
    pS->data[x] = 0;
}

void insert(int x, Set *pS) {
    if(pS->data[x]==1)
    printf("Error: element %d has existed.\n",x);
    pS->data[x] = 1;
}

void setUnion(Set *pA, Set *pB, Set *pC) {
    for (int i = 0; i < N; i++)
    pC->data[i] = pA->data[i] || pB->data[i];
}
void setIntersection(Set *pA, Set *pB, Set *pC) {
	for (int i = 0; i < N; i++)
	pC->data[i] = pA->data[i] && pB->data[i];
}
void setDifference(Set *pA, Set *pB, Set *pC) {
    for (int i = 0; i < N; i++)
        pC->data[i] = pA->data[i] && (!pB->data[i]);
}

void assign(Set *pA, Set *pB) {
	for (int i = 0; i < N; i++)
	pA->data[i] = pB->data[i];
}

int equal(Set *pA, Set *pB) {
	for (int i = 0; i < N; i++)
	if (pA->data[i] != pB->data[i])
	return 0;
	return 1;
}

