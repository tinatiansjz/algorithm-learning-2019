//C++ stdc++11
//kangba
//2018/11/20 23:21
#include <iostream>
#include <algorithm>
using namespace std;
const int maxn = 1000;
int a[maxn];
int main(){
    int n, cur_int, cur_num;
    while(cin>>n){
        for(int i = 0; i < n; i++) cin >> a[i];
        cur_num = 0;
        for(int i = 0; i < n; i++){
            if(cur_num == 0){
                cur_int = a[i];
                cur_num++;
            }else{
                if(a[i] == cur_int) cur_num++;
                else cur_num--;
            }
        }
        cur_num = 0;
        for(int i = 0; i < n; i++){
            if(a[i] == cur_int) cur_num++;
        }
        if(cur_num > (n>>1)) cout << cur_int << endl;
        else cout << "Do not exist!\n";
    }
}
