// http://hihocoder.com/contest/hiho41/problem/1
// 斐波那契数列，一个新的递推公式，没有看懂，蛮神奇
// 备忘录方法，值得借鉴:
// map<int, int> m;
// if(m.count(x)) return m[x];
// 计算m[x]
#include <cstdio>
#include <map>
#include <iostream>
using namespace std;

map<int, int> m;
const int md = 19999997;
long long f(const int x) {
    if(x <= 2) return x ? 1 : 0;
    if(m.count(x)) return m[x];
    const int k = x >> 1;
    const long long a = f(k);
    const long long b = f(k + 1);
    if(x & 1) return m[x] = (a * a + b * b) % md;
    else return m[x] = a * (b + b - a + md) % md;
}

int main() {
    freopen("in.txt", "r", stdin);
    int n;
    scanf("%d", &n);
    int ans = (int)f(n+1);
    cout << "ans: " << ans << endl;
    return 0;
}
