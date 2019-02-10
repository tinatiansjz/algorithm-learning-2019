//UVa 679
//2018/10/27    10:20
//二叉树编号
#include <cstdio>
#include <cstring>
using namespace std;
const int maxd = 20;
int s[1 << maxd];
int main(){
    freopen("P149_in.txt", "r", stdin);
    int D, I;
    while(scanf("%d%d", &D, &I) == 2){
        memset(s, 0, sizeof(s));
        int k, n = (1 << D) - 1;//n is the largest num of the nodes
        for(int i = 0; i < I; i++){
            k = 1;
            for(;;){
                k = s[k] ? k*2+1 : k*2;
                s[k/2] = !s[k/2];
                if(k > n) break;//the ball has fell out of range
            }
        }
        printf("%d\n", k/2);
    }
    return 0;
}
