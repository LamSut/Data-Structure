#include <stdio.h>
#include <stdlib.h>
#include<string.h>

#define MaxLength 50

typedef int Position;

typedef struct{
	char name[100];
	int mark;
} ElementType;

typedef struct {
ElementType Elements[MaxLength];
Position Last; 
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
List L = {{{"Harry Potter",10},{"Hermione Granger",8},{"Draco Malfoy",7},{"Luna Lovegood",8},{"Ron Weasley",9}}, 5};
L.Last = 5;

for(int i=0; i<L.Last; i++){
    printf("%s: %d\n",L.Elements[i].name,L.Elements[i].mark);
}
printf("---END---\n");
ElementType X= {"Gini Weasley",6};
insertList( X , 2, &L);
for(int i=0; i<L.Last; i++){
    printf("%s: %d\n",L.Elements[i].name,L.Elements[i].mark);
}

printf("---END---\n");
deleteList(3, &L);
for(int i=0; i<L.Last; i++){
    printf("%s: %d\n",L.Elements[i].name,L.Elements[i].mark);
}
printf("---END---\n");
char s[40];
scanf("%[^\n]",s);

for(int i=0; i<L.Last; i++){
	if(strcmp(s,L.Elements[i].name)==0){
		printf("%d",L.Elements[i].mark);
	}
    
}


}
