#include <stdio.h>

void funcA(int x){
    if(x > 0){
        printf("%d ", x);
        funcB(x - 1);
    }
}

void funcB(int x){
    if(x > 1){
        printf("%d ", x);
        funcA(x/2);
    }
}

int main(){
    funcA(20);
    return 0;
}

//OUTPUT: 20 19 9 8 4 3 1