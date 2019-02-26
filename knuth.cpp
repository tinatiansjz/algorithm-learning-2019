// 下面程序可以从0...n-1中随机等概率地输出m个不重复的数 (假设n>>m)
#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <ctime>
using namespace std;
void knuth(int n, int m){
    srand((unsigned int)time(0));
    for(int i = 0; i < n; i++){
        if(rand()%(n-i) < m){
            cout << i << endl;
            m--;
        }
    }
}
int main(){
    knuth(100, 5);
    return 0;
}
