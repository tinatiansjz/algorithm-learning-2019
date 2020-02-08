//A - Matrix Chain Multiplication
#include <cstdio>
#include <map>
#include <iostream>
#include <cstdlib>
using namespace std;
typedef struct{
    int first;
    int last;
}T;
int main(){
    map<char, T*> mymap;
    int n;
    char capi;
    cin >> n;
    T* pt = (T*)malloc(sizeof(T));
    for(int i = 0; i < n; i++){
        cin >> capi >> pt->first >> pt->last;
        mymap.insert(pair<char, T*>(capi, pt));
    }
    while()
    return 0;
}
