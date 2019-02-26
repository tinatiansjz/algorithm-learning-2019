//calculate the max sum of a sub-sequence
//2018/11/7 12:06
//Divide and conquer (partition)
//complexity: O(nlogn)
#include <iostream>
#include <cstring>
#include <cstdio>
using namespace std;
int MaxSubSum(int* a, int left, int right){
    int sum = 0;
    if(left == right){
        sum = a[left];
    }else{
        int center = (left+right)/2;
        int leftsum = MaxSubSum(a, left, center);
        int rightsum = MaxSubSum(a, center+1, right);

        //find the maximum sum of the rightmost element in the left half
        int s1 = 0;
        int lefts = 0;
        for(int i = center; i >= left; i--){
            lefts += a[i];
            if(lefts > s1) s1 = lefts;
        }

        //find the maximum sum of the leftmost element in the right half
        int s2 = 0;
        int rights = 0;
        for(int i = center+1; i <= right; i++){
            rights += a[i];
            if(rights > s2) s2 = rights;
        }

        //find the max of three elements
        sum = s1 + s2;
        if(sum < leftsum) sum = leftsum;
        if(sum < rightsum) sum = rightsum;
    }
    return sum;
}
int main(){
    int a[] = {6, -1, 5, 4, -7};
    int max_ = MaxSubSum(a, 0, 4);
    cout << max_ << endl;
    return 0;
}
