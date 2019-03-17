//HDU-1232 畅通工程
//并查集
#include <iostream>
#include <cstring>
#include <cstdio>
#include <cstdio>
using namespace std;
int P[1000];
int has_search[1000];
void merge(int i, int j){
    P[i] = j;
}
int main(){
    freopen("HDU-1232_in.txt", "r", stdin);
    int N, M;
    while(cin >> N >> M && N != 0){
        memset(has_search, 0, sizeof(has_search));
        memset(P, 0, sizeof(P));
        int partition = 0;
        for (int i = 0; i < M; i++){
            int a, b;
            scanf("%d%d", &a, &b);
            int lhs = (a < b)? a : b;
            int rhs = (a < b)? b : a;
            merge(lhs, rhs);
            //for (int i = 0; i < N; i++){
            //   cout << P[i+1] << "\t";
            //}
            //cout << endl;
        }
        int i = 1, parent;
        while(i < N+1){
           // if(!has_search[i]){
           //     if(P[i] != 0) has_search[i] = 1;
           //     int parent = i;
           //     while(P[parent] != 0){
           //         has_search[parent] = 1;
           //         parent = P[parent];
           //     }
           //     if(!has_search[parent]){
           //         has_search[parent] = 1;
           //         partition++;
           //     }
           // }
           // i++;
           parent = i;
           if(P[parent] != 0){
               parent = P[parent];
           } 
           if(!has_search[parent]){
               has_search[parent] = 1;
               partition++;
           }
           i++;
        }
        cout << partition - 1 << endl;
    }
    return 0;
}
