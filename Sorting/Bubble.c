#include <stdio.h>

void swap();

void bubble_sort(int *A, int size){
    int i, j, flag;

    for(i=0; i<size-1; i++){
        flag = 0;
        for(j=0; j<size-1-i; j++){
            if(A[j] > A[j+1]){
                swap(&A[j], &A[j+1]);
                flag = 1;
            } 
        }
        if(flag == 0){
            break;
        }

    }
}

void swap(int *x, int *y){
    int temp = *x;
    *x = *y;
    *y = temp;
}

void display(int *A, int size){
    int i;
    for(i=0; i<size; i++){
        printf("%d ", A[i]);
    }printf("\n");
}

int main(){
    int A[] = {8,7,5,9,10};
    int size = sizeof(A)/sizeof(A[0]);

    bubble_sort(A, size);
    display(A, size);

    return 0;
}