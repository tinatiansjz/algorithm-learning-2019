#include <set>
#include <iostream>
struct Node{
    int a;
    int b;
    Node(int a=0, int b=0):a(a), b(b) {}
};
using namespace std;
Node construct(){
    int arg1 = 1;
    int arg2 = 2;
    return Node(arg1, arg2);
}
int main(){
    set<int> s;
    s.insert(1);
    s.insert(999);
    s.insert(-10);
    for (set<int>::iterator it = s.begin(); it != s.end(); it++){
        cout << *it << endl;
    }
    Node A = construct();
    cout << A.a << '\t' << A.b << endl;
    return 0;
}
