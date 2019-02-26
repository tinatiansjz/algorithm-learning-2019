#include <iostream>
#include <cstdio>
using namespace std;
int cake[1010];
int main(){
    freopen("1703-1_in.txt", "r", stdin);
    int n, k;
    int total = 0;
    cin >> n >> k;
    for (int i = 0; i < n; i++){
        cin >> cake[i];
    }
    int cur = 0;
    for (int i = 0; i < n; i++){
        cur += cake[i];
        if(cur >= k){
            total++;
            cur = 0;
        }
    }
    if(cur != 0){
        total++;
    }
    cout << total << endl;
    return 0;
}
