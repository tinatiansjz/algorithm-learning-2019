// POJ 2823
// 单调队列
#include <iostream>
#include <cstdio>
#include <vector>
using namespace std;
const int maxn = 1e6+5;
int a[maxn], low[maxn], high[maxn];
int n, k;
struct Candidate{
    int index;
    int value;
    Candidate(int index, int value):index(index),value(value) {}
    Candidate(){}
};
vector<Candidate> Slide(maxn);
int bound_min(int x, int y, int v){ // [x, y)
    // find the first position with the value greater than v
    while(x < y){
        int m = x+(y-x)/2;
        if(Slide[m].value > v)  y = m;
        else x = m+1;
    }

    return x;
}
int bound_max(int x, int y, int v){
    // find the first position with the value less than v
    while(x < y){
        int m = x+(y-x)/2;
        if(Slide[m].value < v) y = m;
        else x = m+1;
    }
    return x;
}
void getmin(){
    int front = 0, rear = 0;//[front, rear)
    for(int i = 0; i < k; i++){

        int tmp = bound_min(front, rear, a[i]);
        Slide[tmp] = Candidate(i, a[i]);
        rear = ++tmp;
    }
    printf("%d", Slide[front].value);
    for(int i = k; i < n; i++){
        if(front < rear && Slide[front].index == i-k) front++;
        int tmp = bound_min(front, rear, a[i]);
        Slide[tmp] = Candidate(i, a[i]); rear = ++tmp;
        printf(" %d", Slide[front].value);
    }
    printf("\n");
}
void getmax(){
    int front = 0, rear = 0;//[front, rear)
    for(int i = 0; i < k; i++){
        int tmp = bound_max(front, rear, a[i]);
        Slide[tmp] = Candidate(i, a[i]);
        rear = ++tmp;
    }
    printf("%d", Slide[front].value);
    for(int i = k; i < n; i++){
        if(front < rear && Slide[front].index == i-k) front++;
        int tmp = bound_max(front, rear, a[i]);
        Slide[tmp] = Candidate(i, a[i]); rear = ++tmp;
        printf(" %d", Slide[front].value);
    }
    printf("\n");
}
int main(){
    // freopen("in.txt", "r", stdin);
    cin >> n >> k;
    for(int i = 0; i < n; i++) scanf("%d", &a[i]);
    getmin();
    getmax();
    return 0;
}
