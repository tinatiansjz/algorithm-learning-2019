#include <iostream>
using namespace std;
int add(int, int);
int main(){
    int a = 1, b = 2;
    cout << add(a, b) << endl;
    return 0;
}
int add(int a, int b){
    return a+b;
}
