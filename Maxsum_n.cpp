//calculate the max sum of a sub-sequence
//2018/11/7 15:40
//dynamic programming
//state transition equation: sum[i]=max{sum[i-1]+a[i], a[i]}
//(sum[i] records the largest sequence of sub-sequences with a[i] as the end)
//complexity: O(n)
#include <iostream>
#include <cstring>
#include <cstdio>
using namespace std;
const int maxn = 10000;
int sumArray[maxn];
int MaxSubSum1(int* a, int n){
    int sum = 0, b = 0;
    for(int i = 0; i < n; i++){
        if(b > 0) b += a[i];
        else b = a[i];
        if(b > sum) sum = b;
    }
    return sum;
}

int MaxSubSum(int* a, int n){
    sumArray[0] = a[0];
    for(int i = 0; i < n; i++){
        sumArray[i] = max(sumArray[i-1]+a[i], a[i]);
    }
    int max_ = sumArray[0];
    for(int i = 0; i < n; i++){
        if(sumArray[i] > max_) max_ = sumArray[i];
    }
    return max_;
}
int main(){
    int a[] = {6, -1, 5, 4, -7};
    int max_ = MaxSubSum(a, 5);
    cout << "sumArray: ";
    for(int i = 0; i < 5; i++){
        cout << sumArray[i] << " ";
    }
    cout << endl;
    cout << max_ << endl;
    return 0;
}
