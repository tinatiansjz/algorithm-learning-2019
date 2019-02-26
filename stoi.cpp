#include <iostream>
#include <string>
#include <cstdio>
using namespace std;
int main(){
    string a = "1111";
    int b = stoi(a, &a, 2);
    cout << b << endl;
    return 0;
}
