//https://blog.csdn.net/qq_16234613/article/details/73135771
//2018/11/9 16:40
#include <iostream>
#include <cstdio>
#include <vector>
using namespace std;
vector<int> v;
int main(){
    freopen("1703_2_in.txt", "r", stdin);
    int n, m;
    cin >> n >> m;
    v.clear();
    for(int i = 0; i < n; i++){
        int tmp = i+1;
        v.push_back(tmp);
    }
    while(m--){
        int a, b, pos;
        cin >> a >> b;
        for(int i = 0; i < n; i++){
            if(v[i] == a){
                pos = i;
                break;
            }
        }
        if(b > 0) b++;
        v.insert(v.begin()+pos+b, a);
        if(b < 0) pos++;
        v.erase(v.begin()+pos);
    }
    cout << v[0];
    for(int i = 1; i < n; i++){
        cout << " " << v[i];
    }
    cout << endl;
    return 0;
}
