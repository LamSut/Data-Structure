#include <stdio.h>
#include <math.h>
#define MAXLENGTH 100
typedef struct {
    double c; //coefficients
    int e;    //exponents
} ElementType;
typedef int Position;

typedef struct {
    ElementType elements[MAXLENGTH];
    Position last;
} Polynomial;

Position makeNull(Polynomial *pL) {
    pL->last = 0;
    return pL->last + 1;
}

Position end(Polynomial *pL) {
    return pL->last + 1;
}

void sort(Polynomial *pL){
    for(int p=0; p<pL->last; p++){
        for(int q=p+1; q<pL->last; q++){
            if(pL->elements[p].e<pL->elements[q].e)
            {
                int Tempe = pL->elements[p].e;
                int Tempc = pL->elements[p].c;
                pL->elements[p].e = pL->elements[q].e;
                pL->elements[p].c = pL->elements[q].c;
                pL->elements[q].e = Tempe;
                pL->elements[q].c = Tempc;
            }
        }

    }
}

void insert(double C, int e, Polynomial *pL){
	pL->elements[pL->last].c=C;
	pL->elements[pL->last].e=e;
    pL->last+=1;
    sort(pL);
}


void deleteL(int e, Polynomial *pL){
    int k=0;
    for(int i=0;i<pL->last;i++){
        if(pL->elements[i].e==e){
            for(int j=i; j<=pL->last-1; j++){
            pL->elements[j] = pL->elements[j+1];
            }
            pL->last--;
            k++;
			}
		}
    if(k==0) {
        printf("The exponent does not appear.\n");
    }
}

//coefficient
double coefficient(int e, Polynomial *pL){
    for (int i=0;i<pL->last;i++){
        if(pL->elements[i].e==e){
        return pL->elements[i].c;}
    }
        return 0;
}

//evaluate
double evaluate(double val,Polynomial  *pL){
    double sum;
    for(int i=0; i<pL->last;i++){
        sum+=pow(val,pL->elements[i].e)*pL->elements[i].c;
    }
    return sum;
}

//differentiate
Polynomial differentiate(Polynomial *pL){
	Polynomial p=*pL;
	for(int i=0; i<p.last; i++){
		p.elements[i].c=p.elements[i].e*p.elements[i].c;
		p.elements[i].e=p.elements[i].e-1;	
	}

}

//print
void printPolynomial(Polynomial *pL){
    if(pL->last==0){
        printf("\n");
    }
    else{
        printf("(%.2lf)x^%d ",pL->elements[0].c, pL->elements[0].e);
        for(int i=1;i<pL->last;i++){
        printf("+ (%.2lf)x^%d ",pL->elements[i].c, pL->elements[i].e);
        }
        printf("\n");
    }
}


int main(){
Polynomial L;
makeNull(&L);
insert(5, 3, &L);
insert(4, 4, &L);
insert(-3, 2, &L);
Polynomial dL= differentiate(&L);
printPolynomial(&L);
printPolynomial(&dL);
}
	
