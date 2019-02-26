#include <iostream>
#include <cstdio>
using namespace std;
int main(){
    freopen("scanf_in.txt", "r", stdin);
    int a;
    while(scanf("%d", &a) && a != -1){
        cout << "a = " << a << endl;
        int b;
        scanf("%d", &b);
        cout << "b = " << b << endl;
    }
    return 0;
}
