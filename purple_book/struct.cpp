#include <cstdio>
#include <set>
#include <iostream>
using namespace std;
struct Int{
    int a;
    bool operator < (const Int& rhs) const{
        return a > rhs.a;
    }
};
set<Int> s;
int main(){
    Int x, y, z;
    x.a = 3;
    y.a = 999;
    z.a = -1;
    s.insert(x);
    s.insert(y);
    s.insert(z);
    for(set<Int>::iterator it = s.begin(); it != s.end(); it++){
        cout << it->a << endl;
    }
    return 0;
}
