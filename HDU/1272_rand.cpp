#include <cstdio>
#include <ctime>
#include <iostream>
#include <cstdlib>
#include <set>
using namespace std;
int maxn = 20;
set<int> coord;
set< set<int> > myset;
int main(){
    freopen("HDU-1272_in_2.txt", "w", stdout);
    srand(time(NULL));
    int N = 10;
    while(N--){
        myset.clear();
        while(myset.size() != 10){
            int n = rand() % maxn + 1;
            int m;
            do{m = rand() % maxn + 1;}while(m == n);
            coord.clear();
            coord.insert(n);
            coord.insert(m);
            myset.insert(coord);
        }
        for(set< set<int> >::iterator it = myset.begin(); it != myset.end(); it++){
            set<int> get =  *it;
            for(set<int>::iterator it2 = get.begin(); it2 != get.end(); it2++)
                printf("%d ", *it2);
            printf(" ");
        }
        printf("0 0\n");
    }
    printf("-1 -1\n");
}
