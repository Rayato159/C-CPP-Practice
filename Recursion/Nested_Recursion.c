#include <stdio.h>

int func(int x){
    if(x > 100)
        return x-10;
    else
        return func(func(x+11));
}

int main(){
    printf("%d", func(95));
    return 0;
}

//OUTPUT: 91