#include <iostream>
#include <string>
using namespace std;
int main(){
    string a;
    cout << sizeof(size_t) << endl;
    cout << a.npos << endl;
    cout << sizeof(long long) << endl;
    long long npos = string::npos;
    cout << npos << endl;
    return 0;
}
