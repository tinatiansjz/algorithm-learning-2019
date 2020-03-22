// SA 后缀数组 ？？？ (坑待填)

#include <bits/stdc++.h>
using namespace std;

const int MAXN = 1e5+5;

class Solution {
public:
    int s[MAXN], n;
    int sa[MAXN], t[MAXN*2], t2[MAXN*2], c[MAXN];
    int Rank[MAXN], Height[MAXN];
    int pos = -1, ans = 0;
    void build_sa(int m) {
        int i, *x = t, *y = t2;
        for(int i = 0 ; i < m ; i++) c[i] = 0;
        for(int i = 0 ; i < n ; i++) c[x[i] = s[i]]++;
        for(int i = 1 ; i < m ; i++) c[i] += c[i-1];
        for(int i = n-1; i >=0 ; i--) sa[--c[x[i]]] = i;
        for(int k = 1 ; k <= n ; k <<= 1) {
            int p = 0;
            for(int i = n-k; i < n ; i++) y[p++] = i;
            for(int i = 0 ; i < n ; i++) if(sa[i] >= k ) y[p++] = sa[i] - k;
            for(int i = 0 ; i < m ; i++) c[i] = 0;
            for(int i = 0 ; i < n ; i++) c[x[y[i]]]++;
            for(int i = 1 ; i < m ; i++) c[i] += c[i-1];
            for(int i = n-1; i >= 0 ; i--) sa[--c[x[y[i]]]] = y[i];
            swap(x,y);
            p = 1; x[sa[0]] = 0;
            for(int i = 1; i < n ; i++) {
                x[sa[i]] = y[sa[i-1]] == y[sa[i]] && y[sa[i-1]+k] == y[sa[i]+k] ? p-1 : p++;
            }
            if(p >= n) break;
            m = p;
        }
    }

    void getHeight() {
        int i, j, k = 0;
        for(int i = 0 ; i < n ; i++) Rank[sa[i]] = i;
        for(int i = 0 ; i < n ; i++) {
            if(k) k--;
            int j;
            if(Rank[i]-1<0) continue;
            j = sa[Rank[i] - 1];
            while(i+k < n && j+k < n && s[i+k] == s[j+k]) k++;
            Height[Rank[i]] = k;
       //    cout << i << ' ' << Height[Rank[i]] << endl;
            //cout << ans << endl;
            if(Height[Rank[i]] > ans) {
                ans = Height[Rank[i]];
                pos = i;
            }
        }
    }
    string longestDupSubstring(string S) {
        n = S.length();
        for(int i = 0 ; i < n ; i++) {
            s[i] = S[i] - 'a';
        }
        build_sa(26);
        getHeight();
        if(pos==-1) return "";
        else {
            return S.substr(pos,ans);
        }
    }
};