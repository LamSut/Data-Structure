#include <stdio.h>
#define MAXLENGTH 70
typedef double ElementType;

typedef struct {
    ElementType elements[MAXLENGTH];
    int top;
} Stack;

double top(Stack *pS){
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
    
    char s[50];
    scanf("%[^\n]",s);
    int i=0;
    float a=0,b=0, kq=0;
    
    while(s[i] != '\0'){
        switch (s[i])
   {
     case '+':
        a+= top(&S);
          pop(&S);
          kq= top(&S)+a;
          pop(&S);
          push(kq,&S);
          a=0;
           
          break;
     
     case '-':
        a+= top(&S);
          pop(&S);
          kq= top(&S)-a;
          pop(&S);
          push(kq,&S);
          a=0;
           
          break;
     
     case '*':
          a+= top(&S);
          pop(&S);
          kq= top(&S)*a;
          pop(&S);
          push(kq,&S);
           
          a=0;
          
         break;
     
     case '/': 
        a+= top(&S);
          pop(&S);
          kq= top(&S)/a;
          pop(&S);
          push(kq,&S);
          a=0;
           
          break;
     
     case ' ':
         kq+=0;
          
         break;
     
     default:
        b= (float)s[i]-48;   
         push(b,&S);
          
         break;
   }
   i++;
 }
 printf("%.2f ",kq);
        
}
