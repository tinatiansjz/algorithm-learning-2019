//https://codeforces.com/contest/1080/problem/E
//https://codeforces.com/contest/1080/standings/page/1 (2 LinXuan)
#include <algorithm>
#include <cstdio>
#include <cstring>

typedef long long LL;

const int N = 300;

char A[N][N];
int n, m, B[N], C[N];
int p[N], c[N][26];

bool ck(int i, int j) {
    if (C[i] != C[j]) return false;
    if (i == j) return true;
    for (int k = 0; k < 26; ++k)
      if (c[i][k] != c[j][k]) return false;
    return true;
}

int get() {
    p[0] = 1;
    int mx = 1, id = 0, k = 2 * n - 1, ans = C[0] >= 0;
    for (int i = 1; i < k; ++i) {
        int i0 = i / 2, i1 = (i + 1) / 2;
        if (mx > i1) p[i] = std::min(mx - i1, p[2 * id - i]);
        else p[i] = 0;
        if (mx <= i1 || mx - i1 <= p[2 * id - i])
            while (i0 - p[i] >= 0 && i1 + p[i] < n && ck(i0 - p[i], i1 + p[i]))
                ++p[i];
        if (i1 + p[i] > mx) mx = i1 + p[i], id = i;
        if (C[i1] >= 0) ans += p[i];
    }
    return ans;
}

int main(){
    scanf("%d%d", &n, &m);
    LL ans = 0;
    for (int i = 0; i < n; ++i) scanf("%s", A[i]);
    for (int l = 0; l < m; ++l) {
        memset(B, 0, sizeof B);
        memset(c, 0, sizeof c);
        for (int r = l; r < m; ++r) {
            for (int i = 0; i < n; ++i) {
                B[i] ^= 1 << (A[i][r] - 'a');
                C[i] = B[i] & (B[i] - 1) ? -i-1 : B[i];
                ++c[i][A[i][r] - 'a'];
            }
            int k = get();
            //printf("%d %d %d\n", l, r, k);
            ans += k;
        }
    }
    printf("%I64d\n", ans);
    return 0;
}