// bfs
// https://leetcode-cn.com/problems/minimum-number-of-flips-to-convert-binary-matrix-to-zero-matrix/solution/zhuan-hua-wei-quan-ling-ju-zhen-de-zui-shao-fan-zh/
// The idea of decode() & encode() is very clever
#include <vector>
#include <unordered_set>
#include <queue>
using namespace std;
class Solution {
private:
    static constexpr int dirs[5][2] = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}, {0, 0}};

public:
    int encode(const vector<vector<int>>& mat, int m, int n) {
        int x = 0;
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                x = x * 2 + mat[i][j];
            }
        }
        return x;
    }

    vector<vector<int>> decode(int x, int m, int n) {
        vector<vector<int>> mat(m, vector<int>(n));
        for (int i = m - 1; i >= 0; --i) {
            for (int j = n - 1; j >= 0; --j) {
                mat[i][j] = x & 1;
                x >>= 1;
            }
        }
        return mat;
    }

    void convert(vector<vector<int>>& mat, int m, int n, int i, int j) {
        for (int k = 0; k < 5; ++k) {
            int i0 = i + dirs[k][0], j0 = j + dirs[k][1];
            if (i0 >= 0 && i0 < m && j0 >= 0 && j0 < n) {
                mat[i0][j0] ^= 1;
            }
        }
    }

    int minFlips(vector<vector<int>>& mat) {
        int m = mat.size(), n = mat[0].size();
        int x_start = encode(mat, m, n), step = 0;
        if (x_start == 0) {
            return step;
        }

        unordered_set<int> visited;
        queue<int> q;
        visited.insert(x_start);
        q.push(x_start);

        while (!q.empty()) {
            ++step;
            int k = q.size();
            for (int _ = 0; _ < k; ++_) {
                vector<vector<int>> status = decode(q.front(), m, n);
                q.pop();
                for (int i = 0; i < m; ++i) {
                    for (int j = 0; j < n; ++j) {
                        convert(status, m, n, i, j);
                        int x_cur = encode(status, m, n);
                        if (x_cur == 0) {
                            return step;
                        }
                        if (!visited.count(x_cur)) {
                            visited.insert(x_cur);
                            q.push(x_cur);
                        }
                        convert(status, m, n, i, j);
                    }
                }
            }
        }

        return -1;
    }
};