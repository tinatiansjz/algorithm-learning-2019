//2018/10/26    15:55
//https://blog.csdn.net/jelly97/article/details/55549764
//并查集
#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <set>
using namespace std;
const int maxn = 100005;
int p[maxn];
set<int> s;
int num = 0;
set<int>::iterator it;
int find(int x){
    if(p[x] == x) return x;
    else return p[x] = find(p[x]);
}
void unit(int x, int y){
    int fx = find(x);
    int fy = find(y);
    p[fx] = fy;
}
int main(){
    freopen("HDU-1272_in_2.txt", "r", stdin);
    int t1, t2;
    while(scanf("%d%d", &t1, &t2) == 2){
        int i, j;
        if(t1 == -1 && t2 == -1) break;
    	else if(t1 == 0 && t2 == 0){
            if(num == 0){cout << "Yes" << endl; continue;}
            int flag = -1;
            int count = 0;
            int n = s.size();
            for(it = s.begin(); it != s.end(); it++){
                if(find(*it) != flag && find(*it) != 0){
                    count++; flag = find(*it);
                }
            }
           // cout<<count<<endl;
            if(count == 1 && n-num == 1)
                cout << "Yes" << endl;
            else cout << "No" << endl;
            num = 0;
            s.clear();
            memset(p,0,sizeof(p));
        }else{
            num++;
            s.insert(t1);
            s.insert(t2);
            if(p[t1] == 0) p[t1]=t1;
            if(p[t2] == 0) p[t2]=t2;
            unit(t1,t2);
            //cout<<t1<<" "<<t2<<endl;
        }
	}
    return 0;
}
