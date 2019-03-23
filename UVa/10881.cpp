#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
const int maxn = 1e4+10;
struct ant{
    int id;
    int pos;
    int dir;//direction: -1:L    1:R
}a[maxn];
int b[maxn];
bool cmp(const ant x, const ant y){
    return (x.pos == y.pos)? x.id < y.id : x.pos < y.pos;
}
int readInt(){
    char x;
    while((x = getchar()) > '9' || x < '0') ;
    int u = x-'0';
    while((x = getchar()) >= '0' && x <= '9'){
        u = (u<<3)+(u<<1)+x-'0';
    }
    return u;
}
char readChar(){
    char x;
    while((x = getchar()) != 'R' && x != 'L') ;
    return x;
}
int main(){
    // freopen("in.txt", "r", stdin);
    int N; scanf("%d", &N);
    for(int j = 1; j <= N; j++){
        printf("Case #%d:\n", j);
        memset(a, 0, sizeof(a));
        memset(b, 0, sizeof(b));
        int L, T, n;
        L = readInt(); T = readInt(); n = readInt();
        for(int i = 0; i < n; i++){
            a[i].pos = readInt();
            char dirint = readChar();
            a[i].dir = (dirint == 'R') ? 1 : -1;
            a[i].id = i;
        }
        sort(a, a+n, cmp);
        for(int i = 0; i < n; i++)
            b[a[i].id] = i;
        for(int i = 0; i < n; i++){
            a[i].pos += a[i].dir*T;
        }
        sort(a, a+n, cmp);
        for(int i = 0; i < n; i++){
            int num = b[i];
            if(a[num].pos < 0 || a[num].pos > L) {printf("Fell off\n"); continue;}
            if(num > 0 && a[num].pos == a[num-1].pos){printf("%d Turning\n", a[num].pos); continue;}
            if(num < n-1 && a[num].pos == a[num+1].pos) {printf("%d Turning\n", a[num].pos); continue;}
            printf("%d ", a[num].pos);
            if(a[num].dir == 1) printf("R\n");
            else printf("L\n");
        }
        printf("\n");
    }
    return 0;
}