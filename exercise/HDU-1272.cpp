//2018/10/26 15:03
//WA
#include <iostream>
#include <cstdio>
#include <cstring>
#include <set>
using namespace std;
const int maxn = 100010;
int ufs[maxn];
bool room[maxn];
//set<int> myset;
int num = 0;
int n = 0;
int find(int a) {return ufs[a] == a ? a :ufs[a] = find(ufs[a]);}
int main(){
    freopen("HDU-1272_in_2.txt", "r", stdin);
    int m, n;
    int region = 0;
    bool flag = true;
    memset(room, false, sizeof(room));
    for(int i = 0; i < maxn; i++) ufs[i] = i;
    while(scanf("%d%d", &m, &n) == 2){
        if(m == -1 && n == -1) break;
        else if(m == 0 && n == 0){
           // if(num == 0){cout<<"Yes"<<endl; continue;}
            for(int i = 1; i <= maxn; i++){
                if(region > 1){flag = false; break;}
                if(ufs[i] == i && room[i]) region++;
            }
            //n = myset.size();
            //if(flag && n - num == 1) cout << "Yes\n";
            if(flag) cout << "Yes\n";
            else cout << "No\n";
            //initialize
            region = 0;
            flag = true;
            memset(room, false, sizeof(room));
//            myset.clear();
            for(int i = 0; i < maxn; i++) ufs[i] = i;
        }else{
            num++;
           // myset.insert(m); myset.insert(n);
            room[m] = true; room[n] = true;
            if(flag){
                if(find(m) == find(n)){
                    flag = false;
                }else{
                    ufs[find(m)] = find(n);
                }
            }
        }
    }
    return 0;
}
