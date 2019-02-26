#include <stdlib.h>
#include <stdio.h>
/* see file closure.c and closure1.c */
struct Closure {
    int (*fptr)();
    int *env;
};
int g(int *env, int y) { return y + env[0]; }
struct Closure *f(int x){
	struct Closure *new_closure =
    (struct Closure *) malloc(sizeof(struct Closure));
    int *new_env = (int *) malloc(sizeof(int));
    *new_env = x;
    new_closure -> env = new_env;
    new_closure -> fptr = g;
    return new_closure;
}
int main(){
	struct Closure clos1;
    struct Closure clos2;
	clos1 = *f(3);
	clos2 = *f(4);
	printf("f(4)(5) = %d\n", (clos2.fptr)(clos2.env, 5));
	printf("f(3)(4) = %d\n", (clos1.fptr)(clos1.env, 4));
	return 0;
}
