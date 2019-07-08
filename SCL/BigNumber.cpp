#include <iostream>
#include <cstdio>
#include <string>
using namespace std;
// int d[maxl]
// d[0]:当前位数
// d[i]:第i位上的数 (每4位压成一个万进制位)
// 构造函数: BigNumber(string s)
// 成员函数: string toString()
// 重载运算符: + - *  < 
// 运算过程中和结果都不能包含负数。答案最长长度为(maxl-1)*4
// 除法时余数保存在全局变量d中
const int ten[4] = {1, 10, 100, 1000};
const int maxl = 1000; // 最大位数
struct BigNumber{
    int d[maxl];
    BigNumber(string s){
        int len = s.size();
        d[0] = (len-1)/4+1;
        for(int i = 1; i < maxl; i++) d[i] = 0;
        for(int i = len-1; i >= 0; i--){
            int j = (len-i-1)/4+1;
            int k = (len-i-1)%4;
            d[j] += ten[k]*(s[i]-'0');
        }
        while(d[0] > 1 && d[d[0]] == 0) d[0]--;
    }
    BigNumber(){
        *this = BigNumber(string("0"));
    }
    string toString(){
        string s("");
        int i;
        for(i = 3; i >= 1; i--){
            if(d[d[0]] >= ten[i]) break;
        }
        tmp = d[d[0]];
        for(int j = i; j >= 0; j--){
            s = s + (char)(tmp/ten[j]+'0');
            tmp %= ten[j];
        }
        for(i = d[0]-1; i > 0; i--){
            tmp = d[i];
            for(int j = 3; j >= 0; j--){
                s = s+(char)(tmp/ten[j]+'0');
                tmp %= ten[j];
            }
        }
        return s;
    }
}zero("0"), d, tmp, mid1[15];
bool operator < (const BigNumber &a, const BigNumber &b){
    if(a.d[0] != b.d[0]) return a.d[0] < b.d[0];
    for(int i = a.d[0]; i > 0; i--)
        if(a.d[i] != b.d[i])
            return a.d[i] < b.d[i];
    return false;
}
BigNumber operator + (const BigNumber &a, const BigNumber &b){
    BigNumber c;
    c.d[0] = max(a.d[0], b.d[0]);
    int x = 0;
    for(int i = 1; i <= c.d[0]; i++){
        x = a.d[i] + b.d[i] + x;
        c.d[i] = x%10000;
        x /= 10000;
    }
    while(x != 0){
        c.d[++c.d[0]] = x%10000;
        x /= 10000;
    }
    return c;
}
BigNumber operator - (const BigNumber &a, const BigNumber &b){
    BigNumber c;
    c.d[0] = a.d[0];
    int x = 0;
    for(int i = 1; i <= c.d[0]; i++){
        x = 10000+a.d[i]-b.d[i]+x;
        c.d[i] = x%10000;
        x = x/10000-1;
    }
    while((c.d[0]>1) && (c.d[c.d[0]] == 0)) c.d[0]--;
    return c;
}
BigNumber operator * (const BigNumber &a, const BigNumber &b){
    BigNumber c;
    c.d[0] = a.d[0] = b.d[0];
    int x;
    for(int i = 1; i <= a.d[0]; i++){
        x = 0;
        for(int j = 1; j <= b.d[0]; j++){
            x = a.d[i]*b.d[j] + x + c.d[i+j-1];
            c.d[i+j-1] = x%10000;
            x /= 10000;
        }
        c.d[i+b.d[0]] = x;
    }
    while(c.d[0] > 1 && (c.d[c.d[0]] == 0)) c.d[0]--;
    return c;
}
int main(){
    return 0;
}
