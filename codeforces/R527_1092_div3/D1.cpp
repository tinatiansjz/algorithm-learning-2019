//https://codeforces.com/contest/1092/problem/D1
#include <iostream>
#include <cstdio>
#include <stack>
using namespace std;

int n;
int a[200005];

stack<int> S;

int main(){
    freopen("B_in.txt", "r", stdin);
    //ios::sync_with_stdio(false);
    cin >> n;
    for (int i = 1; i <= n; i++){
        cin >> a[i];
        a[i] &= 1;
    }
    for(int i = 1; i <= n; i++){
        cout << a[i] << " ";
    }
    for (int i = 1; i <= n; i++){
        if (S.empty() || S.top() != a[i])
            S.push(a[i]);
        else
            S.pop();
    }
    cout << (S.size() <= 1 ? "YES" : "NO") << endl;
    return 0;
}