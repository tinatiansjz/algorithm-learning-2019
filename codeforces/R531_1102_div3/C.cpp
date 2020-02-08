#include <iostream>
#include <cstdio>
#include <queue>
using namespace std;
const int maxn = 1e5+10;
priority_queue<int> pq;
int count = 0;
void debug(){
    while(!pq.empty()){
        int tmp = pq.top(); pq.pop();
        cout << tmp << " ";
    }
    cout << endl;
}
int main(){
    freopen("in.txt", "r", stdin);
    int n, x, y;
    cin >> n >> x >> y;
    if(x > y){cout << n << endl; return 0;}
    for(int i = 0; i < n; i++){
        int tmp; scanf("%d", &tmp);
        if(tmp > x) continue;
        pq.push(tmp);
    }
    // debug();
    while(!pq.empty()){
        // our side
        pq.pop(); count++;
        // cout << count << endl;
        if(pq.empty()) break;
        int a = pq.top(); pq.pop();
        // cout << "a: " << a << endl;
        if(a+y <= x) pq.push(a+y);
    }
    cout << count << endl;
    return 0;
}