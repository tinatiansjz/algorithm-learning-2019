// losephus problem 约瑟夫环
// https://blog.csdn.net/u011500062/article/details/72855826
// https://blog.csdn.net/byn12345/article/details/79487253
// f(N,M)=(f(N−1,M)+M)%N
// f(N,M)表示，N个人报数，每报到M时杀掉那个人，最终胜利者的编号
// 新环是由  (旧环中编号-最大报数值)%旧总人数
// 逆推时可以由 ( 新环中的数字 + 最大报数值 )% 旧总人数 取得。即 old_number = ( new_number + value ) % old_sum.
#include <iostream>
#include <cstdio>
using namespace std;
int losephus(int n, int round){
    if(n == 1) return 0;
    else return (losephus(n-1, round+1)+round)%n;
}
int main(){
    // freopen("in.txt", "r", stdin);
    int T; cin >> T;
    while(T--){
        int n; scanf("%d", &n);
        cout << losephus(n, 1)+1 << endl;
    }
    return 0;
}