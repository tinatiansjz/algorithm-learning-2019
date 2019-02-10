//similar to the merge algorithm
//2018/11/10 15:34
#include <iostream>
#include <cstdio>
using namespace std;
const int maxn = 2010;
int hb[maxn], he[maxn], wb[maxn], we[maxn];
int main(){
    freopen("1809_2_in.txt", "r", stdin);
    int n;
    cin >> n;
    for(int i = 0; i < n; i++){
        scanf("%d%d", &hb[i], &he[i]);
    }
    for(int i = 0; i < n; i++){
        scanf("%d%d", &wb[i], &we[i]);
    }
    int i = 0, j = 0;
    int ans = 0;
    while(i<n && j<n){
        int a = hb[i], b = he[i], c = wb[j], d = we[j];
        if(a <= c){
            if(b >= d){ans += d-c; j++; continue;}//注意这里是j++
            else ans += b<c ? 0:(b-c);
            i++;
        }else{
            if(b <= d){ans += b-a; i++; continue;}//注意这里是i++
            else ans += d<a?0:(d-a);
            j++;
        }
    }
    cout << ans << endl;
    return 0;
}
