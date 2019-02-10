//Team Queue, UVa 540
//2018/10/14    08:57
#include <cstdio>
#include <queue>
#include <map>
using namespace std;

//本题有两个队列：每个团体有一个队列，二团队整体又形成一个队列

const int maxt = 1000 + 10;

int main(){
    freopen("P118_in.txt","r",stdin);
    int t, kase = 0;
    while(scanf("%d", &t) == 1 && t){
        printf("Scenario #%d\n", ++kase);
        //记录所有人的团体编号
        map<int, int> team;//team[x]表示编号为x的人所在的团队编号
        for(int i = 0; i < t; i++){
            int n, x;
            scanf("%d", &n);
            while(n--){
                scanf("%d", &x);
                team[x] = i;
            }
        }
        //模拟
        queue<int> q, q2[maxt];
        for(;;){
            int x;
            char cmd[10];
            scanf("%s", cmd);
            if(cmd[0] == 'S') break;
            else if(cmd[0] == 'D'){
                int t = q.front();
                printf("%d\n", q2[t].front());
                q2[t].pop();
                if(q2[t].empty())
                    q.pop();//团体t全体出队列
            }
            else if(cmd[0] == 'E'){
                scanf("%d", &x);
                int t = team[x];
                if(q2[t].empty()) q.push(t);
                q2[t].push(x);
            }
        }
        printf("\n");
    }
    return 0;
}
