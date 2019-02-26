#include <iostream>
#include <map>
#include <set>
#include <cstdio>
using namespace std;
struct ball{
    int index;
    int site;
    int direct;
    bool operator < (const ball& rhs) const {
        return site < rhs.site || (site == rhs.site && index < rhs.index);
    }
};
set<ball> s;
map<int, int> m;
int main(){
    freopen("1803-2_in.txt", "r", stdin);
    int n, L, t;
    cin >> n;//小球的个数
    cin >> L;//线段长度
    cin >> t;//总时间
    for(int i = 0; i < n; i++){
        ball q;
        cin >> q.site;
        q.direct = 1;
        q.index = i;
        s.insert(q);
    }
    while(t--){
        for(set<ball>::iterator it = s.begin(); it != s.end(); it++){
            it->site = it->site + it->direct;
            if(it->site == 0) it->direct = 1;
            else if(it->site == L) it->direct = 0;
        }
        set<ball>::iterator tail = s.begin();
        set<ball>::iterator head = s.begin();
        head++;
        for(; head != s.end(); tail++, head++){
            if(tail->site == head->site){
                tail->direct = 1 - tail->direct;
                head->direct = 1 - head->direct;
            }
        }
    }
    for (set<ball>::iterator it = s.begin(); it != s.end(); it++){
        m[it->index] = it->site;
    }
    cout << m[0];
    for(int i = 1; i < n; i++){
        cout << " " << m[i];
    }
    cout << endl;
    return 0;
}
