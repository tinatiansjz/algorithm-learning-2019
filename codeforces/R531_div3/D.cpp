// https://codeforces.com/contest/1102/standings
// 2019/1/11    10:27
#include <iostream>
#include <cstdio>
#include <vector>
#include <deque>
using namespace std;
int main(){
    // freopen("in.txt", "r", stdin);
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    int n; cin >> n;
    string s; cin >> s;
    //定义一个初始大小为3的vector，vector存的类型为deque<int>
    vector<deque<int> > pos(3);
    for(int i = 0; i < n; i++){
        pos[s[i]-'0'].push_back(i);
    }
    for(int i = 0; i < 3; i++){
        if(pos[i].size() > n/3){
            vector<int> ord = {0, 1, 2};
            if(i == 0){
                ord = {2, 1};
            }
            for(int j : ord){
                while(pos[i].size() > n/3 && pos[j].size() < n/3){
                    if(i > j){
                        int x = pos[i].front();
                        s[x] = char(j+'0');
                        pos[i].pop_front();
                        pos[j].push_back(x);
                    }else{
                        int x = pos[i].back();
                        s[x] = char(j+'0');
                        pos[i].pop_back();
                        pos[j].push_back(x);
                    }
                }
            }
        }
    }
    cout << s << "\n";
    return 0;
}
