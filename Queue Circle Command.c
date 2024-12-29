#include <stdio.h>
#include <stdlib.h>
#include<string.h>

#define MAXLENGTH 50

typedef struct {
    char data[50];
} ElementType;

typedef struct {
    ElementType elements[MAXLENGTH];
    int front, rear;
} Queue;


int empty( Queue *pQ){
    return pQ->front==-1;
}

ElementType front(Queue *pQ){

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
int i=0;
char str[20];

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
				printf("Print %s\n",q.elements[q.front].data);
				dequeue(&q);
			}
	 	}	
		else if(strcmp(str, "CANCEL") == 0){
		
			if(empty(&q)==1){
				printf("Queue is empty, cannot cancel.\n");
			}	
			else{
				printf("Delete %s\n",q.elements[q.front].data);
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


