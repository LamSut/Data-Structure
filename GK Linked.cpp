#include <stdio.h>
#include <math.h>
#include <stdlib.h>
typedef struct CellTag {
    double c; //coefficients
    int e;    //exponents
    struct CellTag *next;
} Cell;

typedef Cell *Position;
typedef Position Polynomial;

Position makeNull(Polynomial *pL) {
    Position header = (Position)malloc(sizeof(Cell));
    header->next = NULL;
    *pL = header;
    return *pL;
}

void sort(Polynomial *pL){
    Position p=*pL,q=p->next;
    while(p->next!=NULL){
        while(q->next!=NULL){
            if(p->next->e<q->next->e)
            {
                int Tempe = p->next->e;
                int Tempc = p->next->c;
                p->next->e = q->next->e;
                p->next->c = q->next->c;
                q->next->e = Tempe;
                q->next->c = Tempc;
            }
            q=q->next;
        }
        p=p->next;
        q=p->next;
    }
}
//insert***
void insert(double C, int e, Polynomial *pL){
	Position p=*pL;
	Position q;
	q=(Cell*)malloc(sizeof(Cell));
    q->c = C;
    q->e = e;
    q->next = p->next;
    p->next = q;
    sort(pL);

}

//delete***
void deleteL(int e, Polynomial *pL){
    Position p;
	int k=0;
    while(p->next!=NULL){
        if(p->next->e==e){
                Position q=p->next;
    			p->next=q->next;
    			free(q);
            	k++;
			}
		p=p->next;	
		}
    if(k==0) {
        printf("The exponent does not appear.\n");
    }
}

//coefficient
double coefficient(int e, Polynomial *pL){
    Position p=*pL;
    while(p->next!=NULL){
        if(p->next->e==e){
        return p->next->c;}
        p=p->next;
    }
        return 0;
}

//evaluate
double evaluate(double val,Polynomial  *pL){
    Position p=*pL;
	double sum;
    while(p->next!=NULL){
        sum+=pow(val,p->next->e)*p->next->c;
        p=p->next;
    }
    return sum;
}

//differentiate
Polynomial differentiate(Polynomial *pL){
	Polynomial p=*pL;
	Polynomial q;
	makeNull(&q);

	while(p->next!=NULL){
		if(p->next->e>0)
		insert(p->next->c*p->next->e,p->next->e-1,&q);
		p=p->next;
	}
	
		return q;
}

//print
void  printPolynomial(Polynomial *pL){
    Position p=*pL;
        printf("(%.2lf)x^%d ",p->next->c, p->next->e);
        p=p->next;
		while(p->next!=NULL){
        printf("+ (%.2lf)x^%d ",p->next->c, p->next->e);
        p=p->next;
        }        
        printf("\n");
}

int main(){
Polynomial L;
makeNull(&L);
insert(5, 3, &L);
insert(4, 4, &L);
insert(-3, 0, &L);
Polynomial dL= differentiate(&L);
printPolynomial(&L);
printPolynomial(&dL);
}
	
