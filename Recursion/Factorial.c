#include <stdio.h>

int fact(int n){
    if(n == 0){
        return 1;
    }
    else{
        return  n * fact(n-1);
    }
    return 0;
}

int main(){
    printf("%d", fact(3));
    return 0;
}

//OUTPUT: 6