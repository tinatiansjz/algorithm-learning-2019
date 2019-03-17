//HDU-1232 畅通工程
//并查集
#include <iostream>
#include <cstring>
#include <cstdio>
#include <cstdio>
using namespace std;
int P[1000];
void merge(int i, int j){
    P[i] = j;
}
int find(int a){return P[a] == a ? a : P[a] = find(P[a]);}
int main(){
    freopen("HDU-1232_in.txt", "r", stdin);
    int N, M;
    while(cin >> N >> M && N != 0){
        for(int i = 0; i <= N; i++) P[i] = i;
        int partition = 0;
        for (int i = 0; i < M; i++){
            int a, b;
            scanf("%d%d", &a, &b);
            a = find(a);
            b = find(b);
            merge(a, b);
        }
        for (int i = 1; i <= N; i++){
            if(P[i] == i) partition++;
        }
        cout << partition - 1 << endl;
    }
    return 0;
}
