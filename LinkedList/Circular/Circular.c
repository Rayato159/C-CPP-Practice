#include <stdio.h>
#include <stdlib.h>

struct Node{
    int data;
    struct Node *next;
}*Head;

void create(int *A, int n){
    int i;
    struct Node *t, *last;
    Head = (struct Node*)malloc(sizeof(struct Node));
    Head->data = A[0];
    Head->next = Head;
    last = Head;

    for(i=1; i<n; i++){
        t=(struct Node*)malloc(sizeof(struct Node));
        t->data = A[i];
        t->next = last->next;
        last->next = t;
        last = t;
    }
}

void display(struct Node *p){
    do{
        printf("%d ", p->data);
        p = p->next;
    }while(p!=Head);
}

int main(){
    int A[] = {1,2,3,4,5};
    int n = sizeof(A)/sizeof(A[0]);
    create(A, n);
    display(Head);
    return 0;
}