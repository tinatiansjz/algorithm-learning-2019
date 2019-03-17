//HDU-1003 Max Sum
//dynamic programming: calculate the max sum of a sub-sequence
//2018/11/7 16:10
#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;
const int maxn = 100010;
//sum[i] records the largest sequence of sub-sequences with a[i] at the end
//left_[i] records the starting position of the largest sequence of sub-sequences with a[i] at the end
int a[maxn];
int sum[maxn];
int left_[maxn];
void MaxSum(int* a, int n, int& l, int& r, int& maxsum){
    sum[0] = a[0];
    for(int i = 1; i < n; i++){
        if(sum[i-1] >= 0){
            sum[i] = sum[i-1] + a[i];
            left_[i] = left_[i-1];
        }else{
            sum[i] = a[i];
            left_[i] = i;
        }
    }
    l = 0; r = 0; maxsum = sum[0];
    for(int i = 1; i < n; i++){
        if(sum[i] > maxsum){
            maxsum = sum[i];
            l = left_[i];
            r = i;
        }
    }
}
int main(){
    freopen("HDU-1003_in.txt", "r", stdin);
    int N;
    cin >> N;
    bool flag = true;
    int c = 0;
    while(N--){
        c++;
        if(flag){flag = false;}
        else cout << endl;
        memset(a, 0, sizeof(a));
        memset(sum, 0, sizeof(sum));
        memset(left_, 0, sizeof(left_));
        int n;
        cin >> n;
        for(int i = 0; i < n; i++){
            scanf("%d", &a[i]);
        }
        int l, r, maxsum;
        MaxSum(a, n, l, r, maxsum);
        printf("Case %d:\n%d %d %d\n", c, maxsum, l+1, r+1);
    }
    return 0;
}
