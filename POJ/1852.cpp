#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;
const int maxn = 1000000;
int a[maxn];
int m[maxn];
int main(){
    freopen("POJ-1852_in.txt", "r", stdin);
    int N;
    cin >> N;
    while(N--){
        int l, n;
        cin >> l >> n;
        for(int i = 0; i < n; i++){
            scanf("%d", &a[i]);
            if(a[i] > l/2) m[i] = l - a[i];
            else m[i] = a[i];
        }
        sort(a, a+n);
        sort(m, m+n);
        int max = (l-a[0]) > a[n-1] ? (l-a[0]) : a[n-1];
        int min = m[n-1];
        cout << min << " " << max << endl;
    }
    return 0;
}
