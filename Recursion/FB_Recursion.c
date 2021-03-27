#include <stdio.h>

void forward(int x){
    if(x > 0){
        printf("%d ", x);
        forward(x - 1);
    }
}

void reverse(int x){
    if(x > 0){
        reverse(x - 1);
        printf("%d ", x);
    }
}

int main(){
    int x=10;

    forward(x);
    printf("\n");
    reverse(x);
    
    return 0;
}

//OUTPUT:
/*10 9 8 7 6 5 4 3 2 1
1 2 3 4 5 6 7 8 9 10*/