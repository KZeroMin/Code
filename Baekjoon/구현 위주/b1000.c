#include <stdio.h>

int main(){
    int a;
    int b;
    int result;
    scanf("%d %d", &a, &b);
    if(a>0 && b<10){

        result = a + b;
        printf("%d", result);
    }
    
    return 0;
}