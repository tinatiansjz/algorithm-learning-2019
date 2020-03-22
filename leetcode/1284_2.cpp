// dfs
// 顺序无关性 + 翻转唯一性
#include <vector>
using namespace std;
class Solution {
private:
    static constexpr int dirs[5][2] = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}, {0, 0}};
    int ans;

public:
    Solution(): ans(1e9) {}

    void convert(vector<vector<int>>& mat, int m, int n, int i, int j) {
        for (int k = 0; k < 5; ++k) {
            int i0 = i + dirs[k][0], j0 = j + dirs[k][1];
            if (i0 >= 0 && i0 < m && j0 >= 0 && j0 < n)
                mat[i0][j0] ^= 1;
        }
    }

    void dfs(vector<vector<int>>& mat, int m, int n, int pos, int flip_cnt) {
        if (pos == m * n) {
            bool flag = true;
            for (int i = 0; i < m; ++i) 
                for (int j = 0; j < n; ++j) 
                    if (mat[i][j] != 0) 
                        flag = false;

            if (flag) ans = min(ans, flip_cnt);
            return;
        }
        int x = pos / n, y = pos % n;
        // not flip
        dfs(mat, m, n, pos + 1, flip_cnt);
        // flip
        convert(mat, m, n, x, y);
        dfs(mat, m, n, pos + 1, flip_cnt + 1);
        convert(mat, m, n, x, y);
    }

    int minFlips(vector<vector<int>>& mat) {
        int m = mat.size(), n = mat[0].size();
        dfs(mat, m, n, 0, 0);    
        return (ans != 1e9 ? ans : -1);
    }
};