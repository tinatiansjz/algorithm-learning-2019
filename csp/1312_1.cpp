#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;
const int maxn = 10010;
int a[maxn];
int t[maxn];
int main(){
    freopen("1312_1_in.txt", "r", stdin);
    int n;
    cin >> n;
    memset(t, 0, sizeof(t));
    for(int i = 0; i < n; i++){
        scanf("%d", &a[i]);
        t[a[i]]++;
    }
    int m = 0, c = 0;
    for(int i = 1; i < maxn; i++){
        if(t[i] > m) {m = t[i]; c = i;}
    }
    cout << c << endl;
    return 0;
}
