#include <cstdio>
#include <iostream>
#include <cstdlib>
using namespace std;

struct try_{
    int a;
    int b;
    try_(int a = 0, int b = 0):a(a+1), b(b+1) {}
};

int main(){
    struct try_ try1(3, 4);
    cout << try1.a << endl;
    cout << try1.b << endl;
    return 0;
}
