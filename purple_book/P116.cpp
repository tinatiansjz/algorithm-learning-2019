//the SetStack Computer, UVa12096
//2018/10/13    16:16
#include <algorithm>
#include <set>
#include <stack>
#include <map>
#include <vector>
#include <iostream>
#include <cstdio>
#define ALL(x) x.begin(), x.end()
#define INS(x) inserter(x, x.begin())
using namespace std;

typedef set<int> Set;
map<Set, int> IDcache;//把集合映射成ID
vector<Set> Setcache;//根据ID取集合

//查找给定集合x的ID。如果找不到，分配一个新ID
int ID(Set x){
    if (IDcache.count(x))
        return IDcache[x];
    Setcache.push_back(x); //添加新集合
    return IDcache[x] = Setcache.size() - 1;//分配新ID
}

int main(){
    freopen("P116_in.txt", "r", stdin);
    int c;
    cin >> c;
    for (int i = 0; i < c; i++){
        stack<int> s;
        int n;
        cin >> n;
        for (int i = 0; i < n; i++){
            string op;
            cin >> op;
            if(op[0] == 'P') s.push(ID(Set()));
            else if (op[0] == 'D') s.push(s.top());
            else{
                Set x1 = Setcache[s.top()];
                s.pop();
                Set x2 = Setcache[s.top()];
                s.pop();
                Set x;
                if(op[0] == 'U') 
                    set_union (ALL(x1), ALL(x2), INS(x));
                if(op[0] == 'I') 
                    set_intersection (ALL(x1), ALL(x2), INS(x));
                if(op[0] == 'A') {
                    x = x2;
                    x.insert(ID(x1));
                }
                s.push(ID(x));
            }
            cout << Setcache[s.top()].size() << endl;
        }
        printf("***\n");
    }
    return 0;
}
