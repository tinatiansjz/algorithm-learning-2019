//calculate the max sum of a sub-sequence
//2018/11/7 10:16
//complexity: O(n^2)
#include <iostream>
#include <cstring>
#include <cstdio>
using namespace std;
const int INF = 10000000;
const int maxn = 10000;
int max_ = -INF;
int sum[maxn];
void fill_sum(int* a, int n){
    sum[0] = a[0];
    for(int i = 1; i < n; i++){
        sum[i] = a[i] + sum[i-1];
    }
}
void MaxSubSum(int* a, int left, int right){
    max_ = -INF;
    int s = 0;
    for(int i = left; i < right; i++){
        for(int j = i+1; j < right; j++){
            if(i == 0){
                s = sum[j];
            }else{
                s = sum[j] - sum[i-1];
            }
            if(s > max_) max_ = s;
        }
    }
}
int main(){
    int a[] = {6, -1, 5, 4, -7};
    memset(sum, 0, sizeof(sum));
    fill_sum(a, 6);
    MaxSubSum(a, 0, 5);
    cout << max_ << endl;
    return 0;
}
