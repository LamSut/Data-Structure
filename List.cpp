#include <stdio.h>
#define MaxLength 50

typedef double ElementType;

typedef int Position;

typedef struct {
ElementType Elements[MaxLength];

Position Last; //gi? d? dài danh sách
} List;
Position first(List L){
return 1;
}
Position Next(Position P, List L){
return P+1;
}
void makenullList(List *L) {
(*L).Last=0;}
Position endList(List L){
return L.Last+1;
}
int emptyList(List L){
return L.Last==0;
}
ElementType retrieve(Position P, List L){
return L.Elements[P-1];
}

Position locate (ElementType x, List *pL){
    for(int i=0; i<(*pL).Last; i++){
        if((*pL).Elements[i]==x){
            return i+1;
        }
    }
    return (*pL).Last+1;
}

void insertList(ElementType X, Position P, List *L){
if ((*L).Last==MaxLength)
printf("\nDanh sach day!");
else {
for(Position i =(*L).Last; i>=P; i--)
(*L).Elements[i] = (*L).Elements[i-1];
(*L).Last++;
(*L).Elements[P-1] = X;
}
}

void deleteList(Position P, List *L){
for(int i=P; i<=(*L).Last-1; i++){
(*L).Elements[i-1] = (*L).Elements[i];}(*L).Last--;
}

void normalize(List *pL){
    List L=*pL;
    int p=0;
    int q;
    while(p!=L.Last){
        q=p+1;
        
        while(q!=L.Last){
            if(L.Elements[q]==L.Elements[p]){
             deleteList(q+1,&L);
            }
              else    {q=q+1;}
            }
    
        p=p+1;
    }
    *pL = L;
}
void printList(List *pL){
    if((*pL).Last!=0){
        
    
    for(int i=0; i<(*pL).Last-1; i++){
        printf("%.0lf, ",(*pL).Elements[i]);
    }
    printf("%.0lf ",(*pL).Elements[(*pL).Last-1]);
    }
    printf("\n");
}

int main(){
List L;
int n;
scanf("%d",&n);
L.Last = n;
for(int i=0; i<n; i++){
    scanf("%lf",&L.Elements[i]);
}
printList(&L);
insertList(20, 4, &L);
printList(&L);
deleteList(1, &L);
printList(&L);
int x;
scanf("%d",&x);

printf("%d",locate (x, &L));

}
