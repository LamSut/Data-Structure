#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    char data[50];
} ElementType;

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
int i=0;
char str[10];
while(i<50){
	scanf("%s ",str);
		if(strcmp(str, "ADD") == 0){
			ElementType s;
			scanf("%s",s.data);
			enqueue(s,&q);

			}
		else if(strcmp(str, "PRINT") == 0){
		
			if(empty(&q)==1){
				printf("Queue is empty, cannot print.\n");
			}	
			else{
				printf("Print %s\n",q.front->next->element.data);
				dequeue(&q);
			}
	 	}	
		else if(strcmp(str, "CANCEL") == 0){
		
			if(empty(&q)==1){
				printf("Queue is empty, cannot cancel.\n");
			}	
			else{
				printf("Delete %s\n",q.front->next->element.data);
				dequeue(&q);
			}
		}
		else if(strcmp(str, "DONE") == 0){
			exit(1);
		}
		else {
			break;
		}
	i++;					
	}
return 0;
}


