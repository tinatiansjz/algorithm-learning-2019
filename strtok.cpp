#include <cstring>
#include <cstdlib>
#include <iostream>
#include <cstdio>
using namespace std;
const int maxn = 10;
int main(){
    int a[maxn], i = 0;
    char str[] = "23 434 45 6 238";
    char* pch;
    pch = strtok(str, " ");
    while(pch != NULL){
        a[i++] = atoi(pch);
        pch = strtok(NULL, " ");
    }
    for(int j = 0; j < i; j++)
        cout << a[j] << endl;
    return 0;
}
