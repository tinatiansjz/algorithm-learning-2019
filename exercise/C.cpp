//C - {A} + {B} 
#include <cstdio>
#include <set>
#include <iostream>
#include <cstdlib>
using namespace std;
int main(){
    freopen("in.txt", "r", stdin);
    int n, m;
    while(scanf("%d%d", &n, &m) == 2){
        set<int> s;
        set<int>::iterator it;
        getchar();
        for(int i = 0; i < n; i++){
            int num;
            scanf("%d", &num);
            s.insert(num);
            getchar();
        }
        for(int i = 0; i < m; i++){
            int num;
            scanf("%d", &num);
            s.insert(num);
            getchar();
        }
        bool flag1 = true;
        for (it = s.begin(); it != s.end(); it++){
            if(flag1){cout << *it; flag1 = false;}
            else
                cout << " " << *it;
        }
        cout << endl;
    }
    return 0;
}
