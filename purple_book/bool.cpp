#include <cstring>
#include <iostream>
#include <cstdio>
using namespace std;
int main(){
    bool has_edge[4][3][2];
    bool a;
    cout << sizeof(a) << endl;
    cout << sizeof(has_edge) << endl;
    a = true;
    printf("true = %d\n", a);
    a = false;
    printf("false = %d\n", a);
    memset(has_edge, false, sizeof(has_edge));
    cout << has_edge[3][2][1];
    return 0;
}
