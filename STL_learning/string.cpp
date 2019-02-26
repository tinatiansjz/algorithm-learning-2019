#include <iostream>
#include <algorithm>
#include <string>
using namespace std;
int main(){
    char cstr[] = "China! Great Wall";
    string s1(cstr);
    string s2(s1);
    string s3(cstr, 7, 11);
    string s4(cstr, 6);
    string s5(5, 'A');
    cout << "s1:" << s1 << endl;
    cout << "s2:" << s2 << endl;
    cout << "s3:" << s3 << endl;
    cout << "s4:" << s4 << endl;
    cout << "s5:" << s5 << endl;
    return 0;
}
