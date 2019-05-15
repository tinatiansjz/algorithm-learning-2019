// https://ac.nowcoder.com/acm/contest/700/C
// 华科现场赛 C题
// 枚举L，将位置符合要求的l的前缀和离散化并插入树状数组，统计答案即可。
// 预处理:
// Step1. 求前缀和pre[i], 并对其排序(maxsum->1, minsum->N) (离散化处理)
// Step2. 树状数组保存当前窗口内q∈[L, R]的前缀和pre[q]的排名 (q为右端点, 所选线段为[1, q])
// 正式计算:
// 固定左端点，左端点p∈[1, N-L], 则合法的右端点q∈[p+L-1, p+R-1]
// 可以计算出sum=pre[p-1]+S, 则通过二分可以确定若想 pre[k]>=sum 至少具备的名次g，
// 通过树状数组即可计算出名次<=g的和 [前缀和，getSum(g)]
// 左端点移动时(滑窗滑动)，对相应的名次±1.(滑进来的前缀和对应的名次+1, 滑出去的前缀和对应的名次-1)
// 有点小绕，但是很巧妙，加油
#include <iostream>
#include <cstdio>
#include <algorithm>
#define ll long long
using namespace std;
const int maxn = 1e6+5;
struct node{
    int id;
    int rank;
    ll presum;
}A[maxn];
ll cur[maxn];
ll B[maxn]; // sort the prefix sum
bool cmp1(node a, node b){// 按pre[i]前缀和由大到小排列
    return (a.presum == b.presum) ? (a.id < b.id) : (a.presum > b.presum);
}
bool cmp2(node a, node b){
    return a.id < b.id;
}
ll pre[maxn], C[maxn];
ll N, L, R, S;
inline ll lowbits(ll x){return x&(-x);}
ll getSum(ll x){
    int ans = 0;
    for(ll i = x; i; i -= lowbits(i)){
        ans += C[i];
    }
    return ans;
}
void update(ll x, int val){
    for(ll i = x; i <= N; i += lowbits(i))
        C[i] += val;
}
void preprocess(){
    sort(B+1, B+N+1, greater<ll>());
    sort(A+1, A+N+1, cmp1);
    for(int i = 1; i <= N; i++) // 按排名离散化前缀和
        A[i].rank = i;
    sort(A+1, A+N+1, cmp2);// 按id排序，便于随机读取pre[i]对应的排名
    for(int i = L; i <= R; i++){
        update(A[i].rank, 1);
        cur[A[i].rank]++;   
    }
}
int main(){
    // freopen("02.in", "r", stdin);
    cin.tie(0);
    ios_base::sync_with_stdio(false);
    cin >> N >> L >> R >> S;
    A[0].presum = 0;
    for(int i = 1; i <= N; i++){
        cin >> A[i].presum;
        A[i].presum += A[i-1].presum;
        A[i].id = i;
        B[i] = A[i].presum;
    }
    preprocess();
    ll ans = 0;
    for(int i = L; i <= N; i++){
        ll threshold = A[i-L].presum + S;
        int cnt = upper_bound(B+1, B+N+1, threshold, greater<ll>())-(B+1);
        ans += getSum(cnt);
        // slide
        cur[A[i].rank]--;
        update(A[i].rank, -1);// 从树状数组中移除A[i]对应的排名
        if(i-L+R+1 <= N){
            update(A[i-L+R+1].rank, 1);
            cur[A[i-L+R+1].rank]++;
        }
    }
    cout << ans << endl;
    return 0;
}