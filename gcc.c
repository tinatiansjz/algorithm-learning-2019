#include <stdio.h>
int (*f(int x)) (int){   
    /* see file fptr.c */
    int g(int z){ return x + z; };
    return g;
}
int main(){
    int (*h)(int) = f(3);
    int (*j)(int) = f(4);
    printf ("%d \n" , (*h)(5));
    printf ("%d \n" , (*j)(7));
    return 0;
}
