#include <stdio.h>
#include <stdlib.h>

struct Node{
    char data;
    struct Node *next;
}*top = NULL;

void push(char x){
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

char pop(){
    struct Node *t;
    char x = -1;
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

int isBalance(char *exp){
    int i;
    for(i=0; exp[i]!='\0'; i++){

        if(exp[i] == '(')
            push(exp[i]);

        else if (exp[i] == ')'){
            if(top == NULL) 
                return -1;
            pop();
        }
    }
    return (top == NULL) ? 1 : -1;
}

int main(){
    char *exp = "((a+b)*(a+b))";
    printf("%d", isBalance(exp));
    return 0;
}