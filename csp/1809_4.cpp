#include <iostream>
#include <cstdio>
#include <cstring>
#include <queue>

using namespace std;
int main(){
    freopen("in.txt", "r", stdin);
    memset(head, -1, sizeof(head));
    cin >> n;
    for(int i = 1; i <= n; i++) scanf("%d", &a[i]);
    for(int i = 0; i < n-2; i++) {
        addedge(i+3, i, -(a[i+2]*3+2));
        addedge(i, i+3, a[i+2]*3);
    }
    addedge(2, 0, -(a[1]*2+1));
    return 0;
}
