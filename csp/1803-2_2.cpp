#include <cstdio>
#include <set>
#include <map>
#include <iostream>
using namespace std;
map<int, int> axis_begin;
multiset<int> loc;
int end[110];
int main(){
    freopen("1803-2_in.txt", "r", stdin);
    int n, L, t;
    cin >> n;//小球的个数
    cin >> L;//线段长度
    cin >> t;//总时间
    for(int i = 1; i <= n; i++){
        int site;
        cin >> site;
        axis_begin[site] = i;
        site = (site + t) % (2*L);
        site = (site <= L)? site : (2*L - site);
        loc.insert(site);

    }
    multiset<int>::iterator it = loc.begin();
    for(int i = 0; it != loc.end(), i <= 1010; i++){
        if(axis_begin[i] != 0){
            int j = axis_begin[i];
            end[j] = *it;
            it++;
        }
    }
    cout << end[1];
    for(int i = 2; i < n+1; i++){
        cout << " " << end[i];
    }
    cout << endl;
    return 0;
}
