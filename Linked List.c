#include <stdio.h>
#include <stdlib.h>

typedef double ElementType;

typedef struct CellTag {
    ElementType element;
    struct CellTag *next;
} Cell;

typedef Cell *Position;
typedef Position List;

Position num2Position(int n, List *L){
    Position p=*L;
    for(int i=0;i<n;i++){
        p=p->next;
    }
    return p;
}

Position makeNull(List *pL){
    (*pL) =malloc(sizeof(Cell));
    (*pL)-> element=15580;
    (*pL) ->next = NULL;
    return *pL;
}
Position previous(Position p, List *pL){
    Position q=*pL;
    while(q->next!=p){
        q=q->next;
    }
    return q;
}
Position next(Position p, List *pL){
    return p->next;
}
Position first(List *pL){
    return *pL;
}
Position end(List *pL){
    Position p = *pL;
    while(p->next!= NULL){
        p=p->next;
    }
    
    return p;
}
ElementType retrieve(Position p, List *pL){
    return p->next->element;
}
void insert(ElementType x, Position p, List *pL){
    Position q;
    q=(Cell*)malloc(sizeof(Cell));
    q->element = x;
    q->next = p->next;
    p->next = q;
}
void delete(Position p, List *pL){
    Position q;
    
    q=p->next;
    p->next=q->next;
    free(q);
}
Position locate(ElementType x, List *pL){
    while((*pL)->next!=NULL){
       if((*pL)->next->element==x){
           break;
       }
       *pL = (*pL)->next;
    }
    return *pL;
}


void readList(List *pL){
     makeNull(pL);
     Position p=*pL;
     int n;
     scanf("%d",&n);
    
     for(int i=1;i<=n;i++){
         int x;
         scanf("%d",&x);
         insert(x, p, pL);
         p=p->next;
     }
}


void printList(List *pL){
    Position p=*pL;
    if(p->next==NULL){
        printf("empty");
    }
    else{
        printf("%.0lf",p->next->element);
        p=p->next;
    while(p->next!=NULL){
        p=p->next;
        printf(", %.0lf",p->element);
    }
    
    }
    printf("\n");
}

int main(){
List L;
readList(&L);
printList(&L);
Position p = num2Position(3, &L);
insert(20, p, &L);
printList(&L);
Position q = num2Position(0, &L);
delete(q, &L);
printList(&L);
int x,a=0;
scanf("%d",&x);

Position k=L;
while(k->next!=NULL){
    if(k->next->element==x){
        a++;
    }
    k=k->next;
}
if(a>0){
    printf("%d is in L.",x);
}
else{
    printf("%d is not in L.",x);
}

}
