#include <iostream>
#include <string>
#include <cstdio>
using namespace std;
int main(){
    string a;
    while(cin >> a){
        cout << a.size() << endl;
        for(int i = 0; i <= a.size() + 2; i++){
            printf("%d ", a[i]);
        }
        cout << endl;
    }
    return 0;
}
