#include <stdio.h>
#include <stdlib.h>

typedef double ElementType;

typedef struct CellTag {
    ElementType element;
    struct CellTag *next;
} Cell;

typedef Cell *Position;

typedef struct {
    Position front, rear;
} Queue;

void makeNull(Queue *pQ){
    
    Position p =(Cell*)malloc(sizeof(Cell));
    p->next=NULL;
    pQ->front=p;
    pQ->rear=p;
}

int empty( Queue *pQ){
    if(pQ->front==pQ->rear)
    return 1;
    return 0;
}

ElementType front (Queue *pQ){
    if(pQ->front==pQ->rear){
        return 90.83;
    }
    return pQ->front->next->element;
    
}

void dequeue(Queue *pQ){
    if(pQ->front==pQ->rear){
        printf("Error: Queue is empty, cannot dequeue.\n");
    }
    else{
        Position p=pQ->front;
        pQ->front=pQ->front->next;
        free(p);
    }
}

void enqueue(ElementType x, Queue *pQ){
    pQ->rear->next=(Cell*)malloc(sizeof(Cell));
    pQ->rear=pQ->rear->next;
    pQ->rear->element=x;
    pQ->rear->next=NULL;
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
