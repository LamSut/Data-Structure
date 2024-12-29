#include <stdio.h>
#define MAXLENGTH 70
typedef double ElementType;

typedef struct {
    ElementType elements[MAXLENGTH];
    int top;
} Stack;

int top(Stack *pS){
    if((*pS).top==MAXLENGTH){
        return -96.96;
    }
    return (*pS).elements[(*pS).top];
}
int empty(Stack *pS){
       if((*pS).top==MAXLENGTH){
        return 1;
    }
    return 0;
}
void push ( ElementType x, Stack *pS){
        if((*pS).top==0){
        printf("Error: stack is full\n");
    }
    else  { (*pS).top--;
    (*pS).elements[(*pS).top] = x; }
}
void makeNull(Stack *pS){
    (*pS).top= MAXLENGTH;
}
void pop( Stack *pS){
         if((*pS).top==MAXLENGTH){
        printf("Error: stack is empty.\n");
    }
    (*pS).top++;
 }
 
int main(){
    Stack S;
    makeNull(&S);
    int n;
    scanf("%d",&n);
    
    while(n!=0){
        push(n%2,&S);
        n/=2;
    }
    while (!empty(&S)){
        printf("%d", top(&S));
        pop(&S); 
        
    }
}
