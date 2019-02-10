//201809_1
//2018/11/9 15:30
#include <iostream>
#include <cstdio>
using namespace std;
const int maxn = 1010;
int a[maxn];
int b[maxn];
int main(){
    int n;
    cin >> n;
    for(int i = 0; i < n; i++){
        scanf("%d", &a[i]);
    }
    b[0] = (a[0] + a[1])/2;
    b[n-1] = (a[n-2]+a[n-1])/2;
    for(int i = 1; i < n-1; i++){
        b[i] = (a[i-1]+a[i]+a[i+1])/3;
    }
    bool first = true;
    for(int i = 0; i < n; i++){
        if(first){first = false;}
        else {cout << " ";}
        printf("%d", b[i]);
    }
    cout << endl;
    return 0;
}
