// 6.交叉队列 
// dynamic programming by kangba
// dp[i][j]: s1[0:i] and s2[0:j-i-1] make up s3[0:j]
// AND s3[j] is provided by s1[i].
// dp[i][j] = 1 if such condition can be satisfied
// else dp[i][j] = 0
// Transfer equation:
// dp[i][j] = 1 iff
// 1. s1[i] == s3[j]
// 2. dp[i-1][k] == 1  (i-1 <= k <= j-1)
// 3. s2[k-i+1:j-i-1] == s3[k+1:j-1] (i-1 <= k <= j-2)
#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
using namespace std;
#define maxn 105

char s1[maxn],s2[maxn],s3[maxn];
int dp[maxn],len1,len2,len3;

int read(){
    char ch = getchar();
    int id = 1,index =0;
    while(ch!=EOF&&ch!='\n'){
        if(ch==','){
            id++;
            index=0;
            ch = getchar();
            continue;
        }
        switch(id){
            case 1:
                s1[index++] = ch;
                s1[index] = 0;
                break;
            case 2:
                s2[index++] = ch;
                s2[index] = 0;
                break;
            case 3:
                s3[index++] = ch;
                s3[index] = 0;
                break;
        }
        ch = getchar();
    }
    return index;
}

void init(){
    memset(dp,0,sizeof(dp));
    dp[0] = s1[0]==s3[0];
    for(int i = 0; i < len2 && s2[i]==s3[i]; i++){
        dp[i+1] = s1[0]==s3[i+1];
    }
}

void echo(){
    for(int i = 0; i < len3; i++){
        cout<<dp[i]<<" ";
    }
    cout<<endl;
}
void solve(){
    init();
    // echo();
    for(int i = 1; i < len1; i++){
        for(int j = len3-1; j >= i; j--){
            for(int k = j-1; k >= i-1; k--){
                dp[j] = s1[i] == s3[j] && dp[k];
                if(dp[j]){
                    if(k == j-1) break;//s3[j-1] == s1[i-1]
                    if(s2[k-i+1] != s3[k+1]) {dp[j] = 0; break;}
                }
                if(dp[j]) break;
            }
        }
        for(int j = 0; j < i; j++){
            dp[j] = 0;
        }
        // echo();
    }
}

int main(){
    // freopen("in.txt","r",stdin);
    // freopen("out.txt","w",stdout);

    ios::sync_with_stdio(false);
    cin.tie(0);

    while(read()){
        len1 = strlen(s1);
        len2 = strlen(s2);
        len3 = strlen(s3);
        s1[len1++] = '$';
        s1[len1] = 0;
        s3[len3++] = '$';
        s3[len3] = 0;
        solve();
        if(dp[len3-1])
            cout<<"true"<<endl;
        else
            cout<<"false"<<endl;
    }
    return 0;
}
