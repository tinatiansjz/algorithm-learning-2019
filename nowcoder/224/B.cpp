//https://ac.nowcoder.com/acm/contest/224/B
//2018/11/2 08:21
#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;
long long A[3000];
char str[20];
void read(int& x, char& ch){
    x = 0; ch = getchar();
    while(ch < '0' || ch > '9') ch = getchar();
    while(ch >= '0' && ch <= '9'){
        x = x*10+ch-'0';
        ch = getchar();
    }
}
int main(){
    freopen("A_in.txt", "r", stdin);
    int n, m;
    cin >> n >> m;
    for(int i = 0; i < n; i++){
        scanf("%lld", &A[i]);
    }
    int head = 0;
    for(int i = 0; i < m; i++){
        int num;
        char op;
        read(num, op);
        if(op == 'a'){
            num %= n;
            head = (head-num+n)%n;
        }else{
            num %= 3;
            int p = (head+1)%n;
            int q = (head+2)%n;
            if(num == 1){
                long long tmp = A[q];
                A[q] = A[p];
                A[p] = A[head];
                A[head] = tmp;
            }else if(num == 2){
                long long tmp = A[q];
                A[q] = A[head];
                A[head] = A[p];
                A[p] = tmp;
            }
        }
    }
    printf("%lld", A[head]);
    for(int i = head+1; i < n; i++){
        printf(" %lld", A[i]);
    }
    for(int i = 0; i < head; i++){
        printf(" %lld", A[i]);
    }
    cout << endl;
    return 0;
}
