//CodeForces - 877A
//2018/10/28    20:47
//Brute-Force
//https://blog.csdn.net/u011469138/article/details/78597084
#include <cstdio>
#include <iostream>
#include <cstring>
using namespace std;
char name[130];
int ok = 0;
char a[] = {"Danil"};
char b[] = {"Olya"};
char c[] = {"Slava"};
char d[] = {"Ann"};
char e[] = {"Nikita"};
void match(char* s){
    int n = strlen(name);
    int m = strlen(s);
    for(int i = 0; i <= n-m; i++){
        int j;
        for(j = 0; j < m; j++){
            if(name[i+j] != s[j]) break;
        }
        if(j >= m){
            ok++;
//            cout << "match:" << s << endl;
        }
    }
}
int main(){
    freopen("cf877a_in.txt", "r", stdin);
    while(cin >> name){
//        cout << name << endl;
        ok = 0;
        match(a); match(b); match(c); match(d); match(e);
       // cout << "ok=" << ok << endl;
        if(ok == 1) cout << "YES\n";
        else cout << "NO\n";
    }
    return 0;
}
