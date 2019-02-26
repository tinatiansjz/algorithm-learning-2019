//C - {A} + {B} 
//using STL set
#include <cstdio>
#include <set>
#include <iostream>
#include <cstdlib>
using namespace std;
int n, m;
int a[10001], b[10001];

struct cmp{
    bool operator()(const int &a, const int &b){
        if(a != b) return a<b;
        else return a>b;
    }
};

int main(){
    freopen("in.txt", "r", stdin);
    while(scanf("%d%d", &n, &m) == 2){
        //定义元素类型位int型的集合对象s,采用的比较函数是cmp
        set<int, cmp> s;
        for (int i = 0; i < n; i++){
            scanf("%d", &a[i]);
            s.insert(a[i]);
        }
        for (int i = 0; i < m; i++){
            scanf("%d", &b[i]);
            s.insert(b[i]);
        }
        set<int, cmp>::iterator it;//定义前向迭代器
        it = s.begin();
        cout << *it++;
        for(; it != s.end(); it++){
            cout << " "<< *it;
        }
        cout << endl;
    }
    return 0;
}
