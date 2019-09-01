// 注意题干说是依次完成任务
#include <iostream>
#include <cstdio>
#define ll long long
using namespace std;
const int maxn = 1000+5;
const int INF = 0x3f3f3f3f;
int a[maxn], b[maxn];
int c[maxn], d[maxn]; // 预处理后的区间
int n;
int cnt = 0;
void pre(){
	cnt = 0;
	int l = -1, r = INF;
	for(int i = 0; i < n; i++){
		if(a[i] > r || b[i] < l){
			c[cnt] = l;
			d[cnt++] = r;
			l = a[i], r = b[i];
		}else{
			l = max(l, a[i]);
			r = min(r, b[i]);			
		}
	}
	c[cnt] = l, d[cnt++] = r;
}
int main(){
	// freopen("in.txt", "r", stdin);
	int T; scanf("%d", &T);
	while(T--){
		scanf("%d", &n);
		for(int i = 0; i < n; i++) scanf("%d%d", a+i, b+i);
		pre();
		if(cnt == 1){printf("0\n"); continue;}
		int pos;
		ll ans = 0;
		if(c[1] > d[0]) pos = d[0];
		else pos = c[0];
		for(int i = 1; i < cnt; i++){
			if(c[i] > pos){
				ans += 1LL*(c[i]-pos+1)/2;
				if(d[i]-c[i] > 0 && (c[i]-pos)&1 && i < cnt-1 && c[i+1] > d[i])
					pos = c[i]+1;
				else
					pos = c[i];
			}else{// d[i] < pos
				ans += 1LL*(pos-d[i]+1)/2;
				if(d[i]-c[i] > 0 && (pos-d[i])&1 && i < cnt-1 && d[i+1] < c[i])
					pos = d[i]-1;
				else
					pos = d[i];
			}
		}
		cout << ans << endl;
	}
	return 0;
}