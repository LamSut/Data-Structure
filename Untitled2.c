#include<stdio.h>
#include <stdlib.h>

typedef struct Node{
int Element;
struct Node* Next;
}Node;

typedef struct Node* Position;
typedef Position List;

void makenullList(List *pL){
    *pL=(struct Node*)malloc(sizeof(struct Node));
    (*pL)->Next=NULL;
}


void insertList(int x, Position p, List *pL){
    Position q;
    q=(struct Node*)malloc(sizeof(struct Node)); 
    q->Element=x;
    q->Next=p->Next;
    p->Next=q;
}

void readList(List *pL){
     makenullList(pL);
     Position p=*pL;
     int n;
     scanf("%d",&n);
    
     for(int i=1;i<=n;i++){
         int x;
         scanf("%d",&x);
         insertList(x, p, pL);
         p=p->Next;
     }
}

void printList(List *pL){
    Position p=*pL;
    while(p->Next!=NULL)
{
printf("%d ",p->Next->Element);    
p=p->Next;
}
printf("\n");
}

int main(){
    List L1;

    readList(&L1);
  
  
    printList(&L1);


}
