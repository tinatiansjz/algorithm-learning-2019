#include <vector>
#include <iostream>
#include <string>
using namespace std;
string Manacher(string s){
    //Insert '#'
    string t = "$#";
    for(int i = 0; i < s.size(); i++){
        //t += s[i];
        //t += "#";
        t = t+s[i]+"#";
    }
    // Process t
    vector<int> p(t.size(), 0);
    int mx = 0;// 回文子串能延伸到的最右端的位置
    int id = 0;// 能延伸到最右端的位置的那个回文子串的中心位置
    int resLen = 0, resCenter = 0;
    for(int i = 1; i < t.size(); i++){
        p[i] = mx > i? min(p[2*id - i], mx-i) : 1;
        while(t[i+p[i]] == t[i-p[i]]) p[i]++;
        if(mx < i+p[i]){
            mx = i+p[i];
            id = i;
        }
        if(resLen < p[i]){
            resLen = p[i];
            resCenter = i;
        }
    }
    return s.substr((resCenter - resLen)/2, resLen-1);
}
int main(){
    string s1 = "12212";
    cout << Manacher(s1) << endl;
    string s2 = "122122";
    cout << Manacher(s2) << endl;
    return 0;
}
