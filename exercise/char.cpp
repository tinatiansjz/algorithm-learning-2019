#include <iostream>
#include <cstdio>
using namespace std;
const int maxn = 110;
int main(){
    char name[maxn];
    while(cin >> name){
        cout << name << endl;
        for(int i = 0; i < 10; i++)
            printf("%d ", name[i]);
        cout << endl;
    }
    return 0;
}
