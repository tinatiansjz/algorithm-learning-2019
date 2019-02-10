#include <stdio.h>
struct tina{
    int a;
    int b;
};
int main(){
    struct tina t1, t2, tmp;
    t1.a = 1; t1.b = -1;
    t2.a = 2; t2.b = -2;
    tmp = t1;
    t1 = t2;
    t2 = tmp;
    printf("t2.a = %d\n", t2.a);
    return 0;
}
