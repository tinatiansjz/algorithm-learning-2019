//Andy's First Dictionary, UVa 10815
//2018/10/13    10:23
#include <cstdio>
#include <iostream>
#include <string>
#include <set>
#include <sstream>
using namespace std;

set<string> dict;//string集合
int main(){
    freopen("P112_in.txt", "r", stdin);
    string s, buf;
    //while(cin >> s){
    while(getline(cin, s)){
        for (int i = 0; i < s.length(); i++){
            if(isalpha(s[i]))
                s[i] = tolower(s[i]);
            else
                s[i] = ' ';//把所有非字母的字符变成空格
        }
        stringstream ss(s);//用stringstream得到各单词
        while(ss >> buf)
            dict.insert(buf);
    }
    for (set<string>::iterator it = dict.begin(); it != dict.end(); it++){
        cout << *it << endl;
    }
    return 0;
}
