#include <stdio.h>

#define MAXLENGTH 100
#define NULL_NODE -1

typedef int Node;
typedef char LabelType;

typedef struct {
    Node      P[MAXLENGTH];
    LabelType L[MAXLENGTH];
    int maxNode;
} Tree;

void buildTree(Tree *pT){
    pT->P[0]=-1;
    pT->L[0]='G';
    pT->P[1]=0;
    pT->L[1]='A';
    pT->P[2]=0;
    pT->L[2]='C';
    pT->P[3]=0;
    pT->L[3]='H';
    pT->P[4]=0;
    pT->L[4]='J';
    pT->P[5]=1;
    pT->L[5]='E';
    pT->P[6]=1;
    pT->L[6]='D';
    pT->P[7]=3;
    pT->L[7]='F';
    pT->P[8]=4;
    pT->L[8]='I';
    pT->P[9]=5;
    pT->L[9]='B';
}

int main() {
    Tree T;
    buildTree(&T);
    for (int i = 0; i <= T.maxNode; i++)
        printf("%d: parent = %d, label = %c\n", i, T.P[i], T.L[i]);
    return 0;
}
