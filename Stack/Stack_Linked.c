#include <stdio.h>
#include <stdlib.h>

struct Node{
    int data;
    struct Node *next;
}*top = NULL;

void push(int x){
    struct Node *t;
    t = (struct Node*)malloc(sizeof(struct Node));
    if(t==NULL){
        printf("Stack Overflow!!!\n");
    }
    else{
        t->data = x;
        t->next = top;
        top = t;
    }
}

int pop(){
    struct Node *t;
    int x = -1;
    if(top == NULL){
        printf("Stack Underflow!!!\n");
    }
    else{
        t = top;
        top = top->next;
        x = t->data;
        free(t);
    }
    return x;
}

int isEmpty(struct Node *p){
    return top == NULL ? 1 : 0;
}

int isFull(struct Node *p){
    return top != NULL ? 1 : 0;
}

void display(){
    struct Node *p;
    p = top;
    while(p != NULL){
        printf("%d ", p->data);
        p = p->next;
    }printf("\n");
}

int main(){
    printf("%d\n", isEmpty(top));

    push(57);
    push(84);
    push(39);

    display(top);

    pop();
    display(top);

    return 0;
}