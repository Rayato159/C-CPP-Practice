#include <stdio.h>

void tree(int x){
    if(x > 0){
        printf("%d ", x);
        tree(x-1);
        tree(x-1);
    }
}

int main(){
    tree(3);
    return 0;
}

//Output: 3 2 1 1 2 1 1