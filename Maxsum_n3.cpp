//calculate the max sum of a sub-sequence
//complexity: O(n^3)
//2018/11/7 09:28
#include <iostream>
#include <cstdio>
const int maxn = 100000000;
int max_ = -maxn;
using namespace std;
void MaxSubSum(int* a, int left, int right){
    for(int i = left; i < right; i++){
        for(int j = i+1; j <= right; j++){
            int sum = 0;
            for(int k = i; k <= j; k++){
                sum += a[k];
            }
            if(max_ < sum) max_ = sum;
        }
    }
}
int main(){
    int a[] = {6, -1, 5, 4, -7};
    MaxSubSum(a, 0, sizeof(a)/4-1);
    cout << max_ << endl;
    return 0;
}
