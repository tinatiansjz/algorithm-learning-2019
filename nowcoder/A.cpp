#include <iostream>
#include <cstdio>
using namespace std;
int main(){
    // freopen("in.txt", "r", stdin);
    int T; scanf("%d", &T);
    while(T--){
        int n, m; scanf("%d%d", &n, &m);
        if(n == m) {cout << "Yes\n"; continue;}
        cout << "No" << endl;
    }
    return 0;
}