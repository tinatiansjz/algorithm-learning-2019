//E-排序
//2018/10/14    10:51
#include <set>
#include <cstdio>
#include <iostream>
#include <sstream>
using namespace std;

multiset<int> dict;//string集合

int main(){
    freopen("E_in.txt", "r", stdin);
    string s;
    int buf;
    while(cin >> s){
        dict.clear();
        for (int i = 0; i < s.length(); i++){
            if(s[i] == '5') s[i] = ' ';
        }

        stringstream ss(s);
        while(ss >> buf){
            dict.insert(buf);
        }
        multiset<int>::iterator it = dict.begin();
        cout << *it++;
        for(; it != dict.end(); it++){
            cout << " " << *it;
        }
        printf("\n");
    }
    return 0;
}
