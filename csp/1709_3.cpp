//unaccomplished
#include <iostream>
#include <cstdio>
#include <string>
#include <sstream>
#include <stack>
using namespace std;
int main(){
    freopen("1709_3_in.txt", "r", stdin);
    int n, m;
    cin >> n >> m;
    string line, totalline;
    for(int i = 0; i < n+1; i++){
        getline(cin, line);
        totalline += line;
    }
    // cout << totalline << endl;
    while(m--){
        string test;
        cin >> test;
        // cout << test << endl;
        for(int i = 0; test[i]; i++){
            if(test[i] == '\\') {test.insert(i, "/"); i++;}
            if(test[i] == '"') {test.insert(i, "/"); i++;}
        }
        int found = totalline.find(test);
        found += test.length();
        for(int i = found+3; i < totalline.length(); i++){
            if(totalline[i] == '{') ;
        }
    }
    return 0;
}
