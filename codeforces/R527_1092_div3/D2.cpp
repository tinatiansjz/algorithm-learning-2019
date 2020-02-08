//https://codeforces.com/contest/1092/problem/D2
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>
#include <iostream>
#include <algorithm>
#include <stack>

using namespace std;

int n;
int a[200005];

stack<int> S;

void doit(){
    while (!S.empty()) //S.clear()
        S.pop();
    for (int i = 1;i <= n;i++){
        if (S.empty() || S.top(‘!= a[i]){
            if (!S.empty() && a[i] > S.top()){
                cout << "NO" << endl;
                exit(0);
            }
            S.push(a[i]);
        }
        else
            S.pop();
    }
    if (S.size() > 1){
        cout << "NO" << endl;
        exit(0);
    }
}

int main(){
    ios::sync_with_stdio(false);
    cin >> n;
    for (int i = 1;i <= n;i++)
        cin >> a[i];
    doit();
    reverse(a + 1,a + n + 1);
    doit();
    cout << "YES" << endl;
    return 0;
}