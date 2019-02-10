// pay attention: the priority of ! is higher than the priority of %
#include <iostream>
#include <cstdio>
using namespace std;
long long s;
int main(){
    // freopen("in.txt", "r", stdin);
    long long n; cin >> n;
    s = n * (n+1) / 2;
    // cout << "s: " << s << endl; 
    // cout << "s%2: " << s%2 << endl;
    // cout << !s%2 << endl;
    if(!(s%2))
        cout << "0" << endl;
    else 
        cout << "1" << endl;
    return 0;
}