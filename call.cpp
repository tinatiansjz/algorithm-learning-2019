#include <iostream>
#include <cstdio>
using namespace std;
void g2();
void h4();
void h5(){printf("h5\n");}
void h4(){printf("h4\n");}
void h3(){printf("h3\n");}
void h2(){printf("h2\n");}
void h1(){printf("h1\n");h4();}
void g3(){printf("g3:\n");}
void g2(){printf("g2:\n");h4();h5();}
void g1(){printf("g1:\n");h1();h2();h3();}
void f(){
    printf("f:\n");
    g1();
    g2();
    g3();
}
int main(){
    f();
    return 0;
}
