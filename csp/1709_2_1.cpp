//https://blog.csdn.net/gl486546/article/details/78233996
//2018/11/9 16:07
#include <iostream>
#include <cstdio>
#include <algorithm>
#include <vector>
using namespace std;
struct teacher{
    int num, s, e;
    teacher(int x=0, int y=0, int z=0): num(x), s(y), e(z){}
};
vector<teacher> p, q;
const int maxn = 1010;
int keyn, tean;
int key[maxn];
bool cmpp(const teacher& a, const teacher& b){
    return a.s < b.s;
}
bool cmpq(const teacher& a, const teacher& b){
    return a.e == b.e ? a.num < b.num : a.e < b.e;
}
int searchkeypos(int keyid){
    for(int i = 1; i <= keyn; i++){
        if(keyid == key[i]) return i;
    }
    cout << "can't find key\n" << keyid << endl;
    return -1;
}
int main(){
    freopen("1709_2_in.txt", "r", stdin);
    cin >> keyn >> tean;
    for(int i = 1; i <= keyn; i++){
        key[i] = i;
    }
    for(int i = 0; i < tean; i++){
        teacher x;
        cin >> x.num >> x.s >> x.e;
        x.e += x.s;
        p.push_back(x);
        q.push_back(x);
    }
    sort(p.begin(), p.end(), cmpp);
    sort(q.begin(), q.end(), cmpq);
    int i = 0, j = 0;
    while(i < tean && j < tean){
        if(p[i].s < q[j].e){
            int pos = searchkeypos(p[i++].num);
            key[pos] = -1;
        }else if (p[i].s >= q[j].e){
            int pos = searchkeypos(-1);
            key[pos] = q[j++].num;
        }
    }
    while(j < tean){
        int pos = searchkeypos(-1);
        key[pos] = q[j++].num;
    }
    cout << key[1];
    for (int i = 2; i <= keyn; i++){
        cout << " " << key[i];
    }
    cout << endl;
    return 0;
}
