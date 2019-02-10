//C - {A} + {B} 
//kangbai
#include <cstdio>
#include <set>
#include <iostream>
#include <cstdlib>
#include <algorithm>
using namespace std;

set<int> myset;

int main(){
    freopen("in.txt", "r", stdin);
    int a, b;
    while(cin >> a >> b){
        myset.clear();
        for (int i = 0; i < (a+b); i++){
            int v;
            cin >> v;
            myset.insert(v);
        }
        for (set<int>::iterator kit = myset.begin(); \
                kit != myset.end(); kit++){
            if(kit != myset.begin()) cout << " ";
            cout << *kit;
        }
        cout << endl;
    }
    return 0;
}
