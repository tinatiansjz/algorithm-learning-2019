//CodeForces - 877A
//2018/10/28    20:28
//https://blog.csdn.net/yuedongdehuoyan/article/details/81407961
#include <vector>
#include <cstdio>
#include <iostream>
#include <string>
#include <map>
using namespace std;
typedef long long ll;
vector<string> s;
int main(){
    freopen("cf877a_in.txt", "r", stdin);
    s.push_back("Danil");
    s.push_back("Olya");
    s.push_back("Slava");
    s.push_back("Ann");
    s.push_back("Nikita");
    string a;
    while(cin >> a){
        int ans = 0;
        for(int i = 0; i < 5; i++){
            //std::string::npos = -1
            if(a.find(s[i]) != a.npos){
                ans++;
                //rfind: find last occurrance of content in string
                if(a.rfind(s[i]) != a.find(s[i])){
                    ans++;
                }
            }
        }
        if(ans == 1) cout << "YES" << endl;
        else cout << "NO" << endl;
    }
    return 0;
}
