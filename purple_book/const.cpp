#include <iostream>
#include <cstdio>
using namespace std;
const int dr[] = {-1, 0, 1, 2};
int main(){
    cout << sizeof(dr) << endl;
    for(int i = 0; i < sizeof(dr)/sizeof(int); i++){
        printf("%d ", dr[i]);
    }
    return 0;
}
