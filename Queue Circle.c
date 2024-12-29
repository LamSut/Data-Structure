#include <stdio.h>
#include <stdlib.h>
#include<string.h>

#define MAXLENGTH 50

typedef double ElementType;

typedef struct {
    ElementType elements[MAXLENGTH];
    int front, rear;
} Queue;


int empty( Queue *pQ){
    return pQ->front==-1;
}

ElementType front(Queue *pQ){
 if(pQ->front==-1)
 return  95.27;
 return pQ->elements[pQ->front];
}

int full(Queue *pQ){
	return (pQ->rear-pQ->front+1)%MAXLENGTH==0;
}

void makeNull(Queue *pQ){
    pQ->front=-1;
    pQ->rear=-1;
}

void dequeue (Queue *pQ){
    if(pQ->front==-1){
        printf("Error: Queue is empty, cannot dequeue.\n");
    }
    if(pQ->front==pQ->rear){
     pQ->front=-1;
     pQ->rear=-1;
     }
     else {pQ->front=(pQ->front+1)%MAXLENGTH;}
}

void enqueue(ElementType x, Queue *pQ){
    if((pQ->rear-pQ->front+1)%MAXLENGTH==0){

        printf("Error: Queue is full, cannot enqueue.");
    }
    else if(pQ->rear==-1&&pQ->front==-1){
        pQ->rear=0;
        pQ->front=0;
        
        pQ->elements[pQ->rear]=x;
    }
    else{
        pQ->rear=(pQ->rear+1)%MAXLENGTH;
        pQ->elements[pQ->rear]=x;
    }
}

int main(){
Queue q;	
makeNull(&q);
int n;
scanf("%d",&n);
enqueue(n,&q);
while(empty(&q)==0){
	int m = front(&q);
	dequeue(&q);
	printf("%d\n",m);
	for(int i=2;i<=m/2;i++){
		if(m%i==0){
			enqueue(i,&q);
		}
	}
}


}
