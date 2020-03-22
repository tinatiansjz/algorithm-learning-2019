/*
后缀数组教科书般的例题。
后缀数组是后缀树的一种变种，能够节省空间。构造的方法有「倍增算法」，「DC3算法」。
主要思想：
设字符串为S(1-n)由n个字符组成。则字符串有n个相同后缀的子串。分别为s(1-n),s(2-n),…,s(n,n)。
然后构建一个SA数组，每个数组存储这些后缀的子串，存储后进行字典序排序。
最后构造出一个height数组，表示SA数组每个元素和前一个元素相同前缀的字符个数。
那么，最长重复子串的长度就是height数组的最大值。
因为最长重复子串一定是两个不同后缀的公共前缀，而且这两个不同后缀的字典序排列后一定是相连的。否则一定有比他更长的。
所以height的最大值能够找到那两个后缀，然后提取公共前缀就找到答案。
From: https://leetcode-cn.com/problems/longest-duplicate-substring/comments/
*/
// 2 <= S.length <= 10^5
// 超出内存限制，但思想不错
#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    string longestDupSubstring(string s) {
        vector<string> SA;
        for(int i = 0; i < s.size(); i++)
            SA.push_back(s.substr(i));
        sort(SA.begin(), SA.end());
        int _max = 0;
        string ans;
        for(int i = 0, tmp; i < SA.size()-1; i++){
            // int lpre = SA[i].size()
            for(int j = 0; j < min(SA[i].size(), SA[i+1].size()); j++){
                if(SA[i][j] != SA[i+1][j]) {
                    if(j > _max){
                        _max = j;
                        ans = SA[i].substr(0, j);
                    }
                    break;
                }else if(j == min(SA[i].size(), SA[i+1].size())-1){
                    if(j > _max){
                        _max = j;
                        ans = SA[i].substr(0, j+1);
                    }
                }
            }
        }
        return ans;
    }
};