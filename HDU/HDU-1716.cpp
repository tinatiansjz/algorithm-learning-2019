//HDU-1716 全排列
//2018/11/1 15:46
#include <iostream>
#include <cstdio>
#include <set>
#include <string>
using namespace std;
set<string> myset;
void swap(string& s, int a, int b){
    char tmp = s[a];
    s[a] = s[b];
    s[b] = tmp;
}
void permutation(string& s, int k, int m){
    if(k == m){
        string tmp(s.substr(0, m+1));
        //cout << "tmp:" << tmp << endl;;
        myset.insert(tmp);
    }else{
        for(int i = k; i <= m; i++){
            swap(s, k, i);
            //cout << "swap:" << s << endl;
            permutation(s, k+1, m);
            swap(s, k, i);
        }
    }
}
int main(){
    freopen("HDU-1716_in.txt", "r", stdin);
    string a, b, c, d;
    bool first = true;
    while(cin>>a>>b>>c>>d && ((a[0]!='0')||(b[0]!='0')||(c[0]!='0')\
                ||(d[0]!='0'))){
        if(first){first = false;}
        else{cout << endl;}
        string in = a+b+c+d;
        myset.clear();
        permutation(in, 0, 3);
        set<string>::iterator it = myset.begin();
        char c = (*it)[0]; 
        for(; it != myset.end(); it++){
            c = (*it)[0];
            if(c != '0') break;
        }
        cout << (*it);
        it++;
        for(; it != myset.end(); it++){
            string tmp = *it;
            if(tmp[0] != '0'){
                if(tmp[0] != c){cout << endl << tmp; c = tmp[0];}
                else{
                    cout << " " << tmp;
                }
            }
        }
        cout << endl;
    }
    return 0;
}
