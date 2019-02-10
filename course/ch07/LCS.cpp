//Longest Common Subsequence: the longest shared sequence of not necessarily consecutive characters
//2018/11/21 11:53
//Dynamic Programming
#include <iostream>
#include <cstring>
#include <cstdio>
#include <algorithm>
using namespace std;
const int maxn = 1005;
int DP[maxn][maxn];
void LCS(){
    string a, b;
    while(cin >> a >> b){
        int l1 = a.size();
        int l2 = a.size();
        memset(DP, 0, sizeof(DP));
        for(int i = 1; i <= l1; i++){
            for(int j = 1; j <= l2; j++){
                if(a[i-1] == b[j-1])//string a, b下标从0开始
                    DP[i][j] = DP[i-1][j-1]+1;
                else
                    DP[i][j] = max(DP[i][j-1], DP[i-1][j]);
            }
        }
        printf("%d\n", DP[l1][l2]);
    }
}
int main(){
    freopen("LCS_in.txt", "r", stdin);
    LCS();
    for(int i = 0; i < 8; i++){
        for(int j = 0; j < 8; j++){
            cout << DP[i][j] << "\t";
        }
        cout << endl;
    }
    return 0;
}
