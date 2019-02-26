// 2019/2/3 12:16
// https://ac.nowcoder.com/acm/contest/332/F
// https://blog.csdn.net/w865629524/article/details/86751246?tdsourcetag=s_pctim_aiomsg
// 如果一轮比赛结束时的状态确定，那么这轮比赛开始时的状态也一定是确定的
// 开始时的状态和结束时的状态是可以一一对应下来的
// 根据题目中给出的A,B,C，我们就可以不断求出下一场的状态，如果最后能化为0, 0, 1的状态，就说明存在一种策略，否则就不存在。
// 知道最终是谁获胜，就可以反推出之前所有的比赛情况
// 0:rock  1:paper  2:scissor
// Round i      0:A     1:B     2:C
// Round i+1    0:a     1:b     2:c
// A = a+b      a = (A+C-B)/2
// B = b+c      b = (A+B-C)/2
// C = a+c      c = (B+C-A)/2
#include <iostream>
#include <cstdio>
#include <string>
using namespace std;
int judge(int a, int b, int c){
    if(a < 0 || b < 0 || c < 0) return -1;
    if(a == 0 && b == 0 && c == 0) return -1;
    if(a == 1 && b == 0 && c == 0) return 0;// rock wins!
    if(a == 0 && b == 1 && c == 0) return 1;// paper wins!
    if(a == 0 && b == 0 && c == 1) return 2;// scissor wins!
    return judge((a+c-b)>>1, (b+a-c)>>1, (c+b-a)>>1);
}
string getAns(int x, int d){
    if(d == 1){
        if(x == 0) return "RS";// rock wins
        else if(x == 1) return "PR";// paper wins
        else return "PS";//scissor wins
    }
    if(x == 0){
        string s1 = getAns(0, d>>1);
        string s2 = getAns(2, d>>1);
        if(s1.compare(s2) > 0) return s2+s1;// s2 < s1
        else return s1+s2;
    }else if(x == 1){
        string s1 = getAns(1, d>>1);
        string s2 = getAns(0, d>>1);
        if(s1.compare(s2) > 0) return s2+s1;
        else return s1+s2;
    }else{
        string s1 = getAns(1, d>>1);
        string s2 = getAns(2, d>>1);
        if(s1.compare(s2) > 0) return s2+s1;
        else return s1+s2;
    }
}
int main(){
    freopen("in.txt", "r", stdin);
    int a, b, c; cin >> a >> b >> c;
    int t = judge(a, b, c);
    if(t == -1){
        cout << "IMPOSSIBLE" << endl;
        return 0;
    }
    string s = getAns(t, (a+b+c)>>1);
    cout << s << endl;
    return 0;
}
