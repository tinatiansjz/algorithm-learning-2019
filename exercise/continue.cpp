#include <iostream>
#include <cstdio>
using namespace std;
int main(){
    int n = 5;
    while(n--){
        if(n > 3) continue;
        cout << n << endl;
    }
    return 0;
}
