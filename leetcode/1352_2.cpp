// 题目数据保证：任何时候，任一连续数字序列的乘积都在 32-bit 整数范围内，不会溢出，
// 这其实说明如果只乘大于 1 的数话，数字序列长度最多不会超过 32
// 如果忽略 0 和 1，在查询的时候暴力乘复杂度就能得到保证。
// vec[i]：存加入的数字 vec[i]vec[i]
// cnt[i]：前 i 数里 0 的个数和，即 0 个数的前缀和
// pre[i]：[0...i-1] 最后一个非 0 和非 1 的位置
#include <bits/stdc++.h>
using namespace std;
class ProductOfNumbers {
public:
    vector<int>vec,zero,pre;
    int n;
    ProductOfNumbers() {
        vec.clear();
        zero.clear();
        pre.clear();
        n=0;
    }
    
    void add(int num) {
        n++;
        vec.push_back(num);
        pre.push_back(-1);
        if (n>1){
            if (vec[n-2]!=1 && vec[n-2]!=0) pre[n-1]=n-2;
            else pre[n-1]=pre[n-2];
        }
        zero.push_back(num==0?1:0);
        if (n>1) zero[n-1]+=zero[n-2];
    }
    
    int getProduct(int k) {
        int tot=zero[n-1];
        if (n-k>=1) tot-=zero[n-1-k];
        if (tot>0) return 0;
        int ans=1;
        for (int i=n-1;i>=n-k;){
            ans*=vec[i];
            i=pre[i];
        }
        return ans;
    }
};