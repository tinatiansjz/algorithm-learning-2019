//POJ-2299 逆序对-归并排序
//2018/11/1 14:48
#include <iostream>
#include <cstdio>
using namespace std;
const int INF = 1e9;
const int maxn = 500010;
long long t;//s[]序列逆序数
int s[maxn];
void compute_t(int* s, int top, int mid, int end){
    //left:     s[top]...s[mid]
    //right:    s[mid+1]...s[end]
    int len_L = mid-top+1;
    int len_R = end-mid;
    int* left = new int[len_L+1];
    int* right = new int[len_R+1];
    for(int i = 0; i < len_L; i++){
        left[i] = s[top+i];
    }
    left[len_L] = INF;//设置无穷上界，避免比较大小时越界
    for(int i = 0; i < len_R; i++){
        right[i] = s[mid+i+1];
    }
    right[len_R] = INF;
    int i = 0, j = 0;
    for(int k = top; k <= end;){
        if(left[i] <= right[j]){
            s[k++] = left[i++];
        }else{
            s[k++] = right[j++];
            t += len_L -i;
        }
    }
    delete left;
    delete right;
    return;
}
void mergesort(int* s, int top, int end){
    if(top < end){
        int mid = (top+end)/2;
        mergesort(s, top, mid);
        mergesort(s, mid+1, end);
        compute_t(s, top, mid, end);
    }
    return;
}
int main(){
    freopen("POJ-2299_in.txt", "r", stdin);
    int n;
    while(cin >> n){
        if(!n) break;
        int* s = new int[n];
        for(int i = 0; i < n; i++){
            cin >> s[i];
        }
        //initialize
        t = 0;
        mergesort(s, 0, n-1);
        cout << t << endl;
        delete s;
    }
    return 0;
}
