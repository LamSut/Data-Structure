#include <stdio.h>
#define MAXLENGTH 100
#define NULL_NODE -1

typedef int Node;
typedef char LabelType;

typedef struct {
    Node      P[MAXLENGTH];
    LabelType L[MAXLENGTH];
    int maxNode;
} Tree;

void makeNull(Tree *pT){
    pT->maxNode=-1;
}

int empty(Tree *pT){
    if(pT->maxNode==-1){
        return 1;
    }
    return 0;
}

Node parent(Node n, Tree *pT){
    if(n<0||n>pT->maxNode||pT->maxNode==-1){
        return NULL_NODE;
    }
    return pT->P[n];
}

LabelType label(Node n, Tree *pT){
    if(n==pT->maxNode+1){
        return 'a';
    }
    else if(n<0||n>pT->maxNode||pT->maxNode==-1){
        return 's';
    }
    return pT->L[n];
}

Node root(Tree *pT){
    if(pT->maxNode==-1){
        return NULL_NODE;
    }
    return 0;
}

Node leftMostChild(Node n, Tree* pT){
    if(n<0)
    return NULL_NODE;
    Node i=n+1;
    while(i<=pT->maxNode){
        if(pT->P[i]==n){
            return i;
        }
        else{
            i++;
        }
    }
    return NULL_NODE;  
}

Node rightSibling(Node n, Tree* pT){
    if(n<0)
    return NULL_NODE;
    Node i=n+1;
    while(i<=pT->maxNode){
        if(pT->P[i]==pT->P[n]){
            return i;
        }
        else{
            i++;
        }
    }
    return NULL_NODE;
}

void preorder(Node n, Tree *pT){
    if(pT->maxNode==-1){
        return;
    }
    else{
        printf("%c ",label(n,pT));
        Node i= leftMostChild(n,pT);
        while(i!=NULL_NODE){
            preorder(i,pT);
            i=rightSibling(i,pT);
        }
    }
}

void inorder(Node n, Tree *pT){
    if(pT->maxNode==-1){
        return;
    }
    else{
        Node i= leftMostChild(n,pT);
        if(i!=NULL_NODE){
            inorder(i,pT);
        }
        printf("%c ",label(n,pT));
        i=rightSibling(i,pT);
        while(i!=NULL_NODE){
            inorder(i,pT);
            i=rightSibling(i,pT);
        }
    }
}

void postorder(Node n, Tree *pT){
    if(pT->maxNode==-1){
        return;
    }
    else{
        Node i= leftMostChild(n,pT);
        while(i!=NULL_NODE){
            postorder(i,pT);
            i=rightSibling(i,pT);
        }
        printf("%c ",label(n,pT));
    }
}
 
int main(){
	
Tree T = { {-1, 0, 0, 2, 1},
           {'A', 'B', 'C', 'D', 'E'}, 4};
printf("Postorder traversal of T:\n");
postorder(0, &T);
}
