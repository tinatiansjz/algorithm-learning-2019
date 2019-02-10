#include <set>
#include <iostream>
using namespace std;
struct test{
    int a;
    int b;
    bool operator < (const test& rhs) const {
        return a < rhs.a || (a == rhs.a && b < rhs.b);
    }
};
set<test> s;
int main(){
    test e1, e2;
    e1.a = 1; e1.b = 2;
    e2.a = 1; e2.b = 3;
    s.insert(e2); s.insert(e1);
    for(set<test>::iterator it = s.begin(); it != s.end(); it++){
        cout << it->a << '\t' << it->b << endl;
    }
    return 0;
}
