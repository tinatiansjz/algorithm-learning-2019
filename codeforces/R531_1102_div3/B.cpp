#include <iostream>
#include <map>
#include <vector>
#include <cstdio>
#include <cstring>
using namespace std;
const int maxn = 5010;
vector<int> v;
map<int, int> cnt;
int color[maxn];
int K = 0;
void init(){
    v.clear();
    memset(color, 0, sizeof(color));
}
int main(){
    // freopen("in.txt", "r", stdin);
    init();
    int n, k; cin >> n >> k;
    for(int i = 1; i <= n; i++){
        int tmp; scanf("%d", &tmp);
        v.push_back(tmp);
        cnt[tmp]++;
    }
    int max_ = 0;
    for(int i = 1; i <= n; i++){
        int count = cnt[v[i]];
        if(count > max_) max_ = count;
    }
    if(k < max_) cout << "NO\n";
    else if(k > n) cout << "NO\n";
    else{
        for(map<int, int>::iterator it = cnt.begin(); it != cnt.end(); it++){

            if(it->second > 1){
                // cout << "it->first: " << it->first << endl;
                for(int i = 1; i <= n; i++){
                    if(v[i-1] == it->first){
                        color[i] = K+1;
                        // cout << "color[" << i << "]: " << color[i] << endl;
                        K = (K+1)%k;
                    }
                }
            }
        }
        for(int i = 1; i <= n; i++)
            if(color[i] == 0){
                color[i] = K+1; K = (K+1)%k;
            }
        cout << "YES" << endl << color[1];
        for(int i = 2; i <= n; i++)
            cout << " " << color[i];
        cout << endl;
    }
    return 0;
}