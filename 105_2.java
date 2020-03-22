// https://developer.aliyun.com/coding/105
// By Kangba
import java.util.*;
import java.io.*;
import java.lang.Math;

class Solution {
    long f(int l, int r, long[] a, long lp, long rp){ // [l, r]
        if(l+1 == r) return a[l]*l+a[r]*r;
        long kmin = (long)(1e18+1);
        for(int i = l+1; i < r; i++){
            long tmp = a[i];
            a[i] = 0;
            long kleft = f(l, i, a, lp, lp+rp);
            long kright = f(i, r, a, lp+rp, rp);
            kmin = Math.min(kmin, kleft + kright + tmp*(lp+rp));
            a[i] = tmp;
        }
        return kmin;
    }
    public long solution(int n, long[] nums){
        return f(0, n-1, nums, 1, 1);
    }
}