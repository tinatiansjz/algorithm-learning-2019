//深度优先搜索实现全排列
//https://blog.csdn.net/u011479875/article/details/47263211
//2018/11/1 16:30
#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;
int a[15], s[10000], visit[100];
void DFS(int x, int sum){
    if(x > 4){
        if(s[sum] == 0)
            s[sum] = 1;
        return;
    }
    for(int i = 1; i <= 4; i++){
        if(visit[i] == 0){
            visit[i] = 1;
            DFS(x+1, sum*10+a[i]);
            visit[i] = 0;
        }
    }
}
int main(){
    int k, sign, t = 0;
    freopen("HDU-1716_in.txt", "r", stdin);
    while(cin >> a[1]){
        cin >> a[2] >> a[3] >> a[4];
        if(!a[1] && !a[2] && !a[3] && !a[4]) break;
        if(t != 0) printf("\n");
        t = 1;
        memset(s, 0, sizeof(s));
        memset(visit, 0, sizeof(visit));
        DFS(1, 0);
        k = 0; sign = 0;
        for(int i = 1000; i < 10000; i++){
            if(s[i] == 1){
                sign++;
                if(sign==1){
                    k = i/1000;
                    cout << i;
                }else{
                    if(i/1000 != k){
                        k = i/1000;
                        cout << endl;
                    }else{
                        cout << " ";
                    }
                    cout << i;
                }
            }
        }
        cout << endl;
    }
    return 0;
}
