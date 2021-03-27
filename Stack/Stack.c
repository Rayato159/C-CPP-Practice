#include <stdio.h>
#include <stdlib.h>

struct Stack{
    int size;
    int top;
    int *s;
};

void create(struct Stack *st){
    printf("Enter size of Array: ");
    scanf("%d", &st->size);
    st->s = (int *)malloc(st->size*sizeof(st->s));
    st->top = -1;
}

void display(struct Stack st){
    int i;
    for(i=st.top; i>-1; i--){
        printf("%d ", st.s[i]);
    }printf("\n");
}

void push(struct Stack *st, int x){
    if(st->top == st->size-1){
        printf("Stack Overflow!!!\n");
    }
    else{
        st->top++;
        st->s[st->top] = x;
    }
}

int pop(struct Stack *st){
    int x = -1;
    if(st->top == -1){
        printf("Stack Underflow\n");
    }
    else{
        x = st->s[st->top--];
    }
    return x;
}

int peek(struct Stack st, int index){
    int x=-1;
    if(st.top-index+1 < 0){
        printf("Invalid Index\n");
    }
    x = st.s[st.top-index+1];
    return x;
}

int isEmpty(struct Stack *st){
    return (st->top == -1) ? 1 : -1;
}

int isFull(struct Stack *st){
    return (st->top == st->size-1) ? 1 : -1;
}

int main(){
    struct Stack st;
    int i;

    create(&st);

    for(i=0; i<st.size; i++){
        push(&st, i+1);
    }
    display(st);

    // printf("pop: %d\n", pop(&st));
    // display(st);

    printf("%d\n", peek(st, 5));

    return 0;
}