#include <stdio.h>
#include <stdlib.h>
#include "Queue.h"

struct Node *root = NULL;

void tree(){
    struct Node *p, *t;
    int x;
    struct Queue q;
    create(&q, 100);
    
    printf("Enter root: ");
    scanf("%d", &x);
    root = (struct Node *)malloc(sizeof(struct Node));
    root->data = x;
    root->lchild = root->rchild = NULL;
    
    enqueue(&q, root);

    while(!isEmpty(q)){
        p = dequeue(&q);
        printf("Enter lchild of %d: ", p->data);
        scanf("%d", &x);

        if(x != -1){
            t = (struct Node *)malloc(sizeof(struct Node));
            t->data = x;
            t->lchild = t->rchild = NULL;
            p->lchild = t;
            enqueue(&q, t);
        }
        printf("Enter rchild of %d: ", p->data);
        scanf("%d", &x);

        if(x != -1){
            t = (struct Node *)malloc(sizeof(struct Node));
            t->data = x;
            t->lchild = t->rchild = NULL;
            p->rchild = t;
            enqueue(&q, t);
        }
    }

}

void preorder(struct Node *p){
    if(p){
        printf("%d ", p->data);
        preorder(p->lchild);
        preorder(p->rchild);
    }
}

void inorder(struct Node *p){
    if(p){
        inorder(p->lchild);
        printf("%d ", p->data);
        inorder(p->rchild);
    }
}

void postorder(struct Node *p){
    if(p){
        postorder(p->lchild);
        postorder(p->rchild);
        printf("%d ", p->data);
    }
}

void levelorder(struct Node *root){
    struct Queue q;
    create(&q, 100);

    printf("%d ", root->data);
    enqueue(&q, root);

    while(!isEmpty(q)){
        root = dequeue(&q);
        if(root->lchild){
            printf("%d ", root->lchild->data);
            enqueue(&q, root->lchild);
        }
        if(root->rchild){
            printf("%d ", root->rchild->data);
            enqueue(&q, root->rchild);
        }
    }
}

int main(){
    tree();
    levelorder(root);
    return 0;
}