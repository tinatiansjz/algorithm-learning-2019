#include <cstdio>
#include <iostream>
#include <vector>
#include <cassert>
#include <ctime>
#include <cstdlib>
using namespace std;
const int cnt = 100;
struct Node{
    int x;
    int y;
    int l;
    Node(int x=0, int y=0, int l=0):x(x),y(y),l(l){}
};
void fill_random(vector<Node>& v){
    v.clear();
    for (int i = 0; i < cnt; i++){
        int l = rand();
        int x = rand() % l;
        int y = rand() % l;
        v.push_back(Node(x, y, l));
    }
}
void test_sort(vector<Node>& v){
    for(int i = 0; i < v.size(); i++){
        int lhs = (v[i].y - v[i].x + v[i].l) % v[i].l;
        int rhs = ((v[i].y - v[i].x) % v[i].l + v[i].l) % v[i].l;
        printf("%d %d %d\n", v[i].x, v[i].y, v[i].l);
        assert(lhs == rhs);
    }
}
int main(){
    srand(time(NULL));
    vector<Node> v;
    fill_random(v);
    test_sort(v);
    printf("Hello\n");
    return 0;
}
