#include <iostream>
#include <cstdio>
using namespace std;
struct BigInteger{
    int a, b, c;
    BigInteger(long long num = 0){*this = num;}
    BigInteger operator = (long long num){
        this->a = num / 100;
        this->b = (num / 10) % 10;
        this->c = num % 10;
        return *this;
    }
    void say(){
        printf("%d %d %d", a, b, c);
    }
};
int main(){
    BigInteger A(515);
    A.say();
    return 0;
}