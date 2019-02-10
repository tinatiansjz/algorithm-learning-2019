#include <iostream>
#include <string>
#include <cstdlib>
#include <cstring>
#include <cstdio>
using namespace std;
int main(){
    string str = "12 3 4 5 6 89";
    char *s = (char*)malloc(str.length()+1);
    strcpy(s, str.c_str());
    char* token;
    token = strtok(s, " ");
    while(token != NULL){
        cout << token << endl;
        token = strtok(NULL, " ");
    }
    cout << s << endl;
}
