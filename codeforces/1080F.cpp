//https://codeforces.com/contest/1080/problem/F
//https://codeforces.com/contest/1080/standings/page/1 (2 LinXuan)
#include <algorithm>
#include <cstdio>
#include <cstring>

const int N = 300050;
const int NN = N * 20;
const int INF = 2000000000;

int root[N], maxv[NN], lc[NN], rc[NN], cnt = 1;

void insert(int &o, int l, int r, int p, int y) {
    maxv[cnt] = maxv[o];
    lc[cnt] = lc[o];
    rc[cnt] = rc[o];
    o = cnt++;
    if (l == r) maxv[o] = std::min(maxv[o], y);
    else {
        int mid = (l + r) / 2;
        if (p <= mid) insert(lc[o], l, mid, p, y);
        else insert(rc[o], mid + 1, r, p, y);
        maxv[o] = std::max(maxv[lc[o]], maxv[rc[o]]);
    }
}

int query(int o, int l, int r, int L, int R) {
    if (l > R || L > r) return 0;
    if (!o) return INF;
    if (L <= l && r <= R) return maxv[o];
    int mid = (l + r) / 2;
    return std::max(query(lc[o], l, mid, L, R), query(rc[o], mid + 1, r, L, R));
}

struct Interval {
    int l, r, p;
    friend bool operator<(const Interval &a, const Interval &b) {
        return a.l > b.l;
    }
} I[N];

int n, m, k;

int main(){
    maxv[0] = INF;
    lc[0] = rc[0] = 0;
    scanf("%d%d%d", &n, &m, &k);
    for (int i = 0; i < k; ++i)
        scanf("%d%d%d", &I[i].l, &I[i].r, &I[i].p);
    std::sort(I, I + k);
    root[0] = 0;
    for (int i = 0; i < k; ++i) {
        //printf("  %d %d %d %d\n", i, I[i].l, I[i].r, I[i].p);
        insert(root[i + 1] = root[i], 1, n, I[i].p, I[i].r);
    }
    while (m--) {
        int a, b, x, y;
        scanf("%d%d%d%d", &a, &b, &x, &y);
        Interval t;
        t.l = x;
        int i = std::upper_bound(I, I + k, t) - I;
        //printf("  %d ", i);
        puts(query(root[i], 1, n, a, b) <= y ? "yes" : "no");
        fflush(stdout);
    }
    return 0;
}