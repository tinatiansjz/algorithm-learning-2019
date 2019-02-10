//HDU-1231 Max Sum
//dynamic programming: calculate the max sum of a sub-sequence
//2018/11/7 16:36
#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;
const int maxn = 100010;
//sum[i] records the largest sequence of sub-sequences with a[i] at the end
//left_[i] records the starting element of the largest sequence of sub-sequences with a[i] at the end
int a[maxn];
int sum[maxn];
int left_[maxn];
void MaxSum(int* a, int n, int& l, int& r, int& maxsum){
    sum[0] = a[0]; left_[0] = a[0];
    for(int i = 1; i < n; i++){
        if(sum[i-1] >= 0){
            sum[i] = sum[i-1] + a[i];
            left_[i] = left_[i-1];
        }else{
            sum[i] = a[i];
            left_[i] = a[i];
        }
    }
    l = a[0]; r = a[0]; maxsum = sum[0];
    for(int i = 1; i < n; i++){
        if(sum[i] > maxsum){
            maxsum = sum[i];
            l = left_[i];
            r = a[i];
        }
    }
}
int main(){
    freopen("HDU-1231_in.txt", "r", stdin);
    int N;
    while(scanf("%d", &N) && N){
        memset(a, 0, sizeof(a));
        memset(sum, 0, sizeof(sum));
        memset(left_, 0, sizeof(left_));
        for(int i = 0; i < N; i++){
            scanf("%d", &a[i]);
        }
        int l, r, maxsum;
        MaxSum(a, N, l, r, maxsum);
        printf("%d %d %d\n", maxsum, l, r);
    }
    return 0;
}
