//purple book   P187
//2018/11/1 17:30
#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;
int main(){
    int n, p[10];
    scanf("%d", &n);
    for(int i = 0; i < n; i++) cin >> p[i];
    sort(p, p+n);
    do{
        for(int i = 0; i < n; i++) cout << p[i];
        cout << endl;
    }while(next_permutation(p, p+n));
    return 0;
}
