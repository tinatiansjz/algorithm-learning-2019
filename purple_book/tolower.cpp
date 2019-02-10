#include <cstdio>
#include <iostream>
using namespace std;
int main(){
    int i = 0;
    char str[] = "Testing String.\n";
    char c;
    while(str[i]){
        c = str[i];
        putchar(toupper(c));
        i++;
    }
    return 0;
}
