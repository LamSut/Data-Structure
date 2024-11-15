#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef double ElementType;

typedef struct{
	char name[100];
	int mark;
} in4;

typedef struct CellTag {
    in4 element;
    struct CellTag *next;
} Cell;

typedef Cell *Position;
typedef Position List;

Position makeNull(List *pL){
    (*pL) =(Cell*)malloc(sizeof(Cell));
    
    (*pL) ->next = NULL;
    return *pL;
}

Position num2Position(int n, List *L){
    Position p=*L;
    for(int i=0;i<n;i++){
        p=p->next;
    }
    return p;
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

void insert(in4 x, Position p, List *pL){
    Position q;
    q=(Cell*)malloc(sizeof(Cell));
    q->element = x;
    q->next = p->next;
    p->next = q;
}
void deleteList(Position p, List *pL){
    Position q;
    
    q=p->next;
    p->next=q->next;
    free(q);
}







int main(){
List L;
	makeNull(&L);
	Position p=L;
	in4 A ={{"Harry Potter"},10};
	insert(A, p, &L);	
	p=p->next;
	in4 B ={{"Hermione Granger"},8};
	insert(B, p, &L);	
	p=p->next;
	in4 C ={{"Draco Malfoy"},7};
	insert(C, p, &L);	
	p=p->next;
	in4 D ={{"Luna Lovegood"},8};
	insert(D, p, &L);	
	p=p->next;
	in4 E ={{"Ron Weasley"},9};
	insert(E, p, &L);	

	


Position q=L;
while(q->next!=NULL){
	printf("%s: %d\n",q->next->element.name,q->next->element.mark);
	q=q->next;
}
printf("---END---\n");
q=L;

in4 X= {"Gini Weasley",6};

Position k = num2Position(1, &L);
insert( X , k, &L);

while(q->next!=NULL){
	printf("%s: %d\n",q->next->element.name,q->next->element.mark);
	q=q->next;
}
printf("---END---\n");
q=L;

Position j =
num2Position(2, &L);
deleteList(j, &L);
while(q->next!=NULL){
	printf("%s: %d\n",q->next->element.name,q->next->element.mark);
	q=q->next;
}
printf("---END---\n");
q=L;

char s[40];
scanf("%[^\n]",s);


while(q->next!=NULL){
	if(strcmp(s,q->next->element.name)==0){
		printf("%d",q->next->element.mark);
	}
	q=q->next;
}

    
}



