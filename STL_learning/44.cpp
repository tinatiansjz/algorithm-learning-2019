#include <set>
#include <cstdio>
#include <iostream>
using namespace std;
int main(){
    set<int> s;
    set<int>::iterator it;
    s.insert(4);
    s.insert(3);
    s.insert(2);
    s.insert(1);
    s.insert(5);
    for (it = s.begin(); it != s.end(); it++){
        cout << *it << "\t";
    }
    return 0;
}
