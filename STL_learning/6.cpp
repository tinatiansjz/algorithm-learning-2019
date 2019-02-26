#include <cstdio>
#include <string.h>
#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <set>
#include <map>
#include <string>
#include <cmath>
#include <cstdlib>
#include <time.h>
using namespace std;

int main(){
    //freopen("in.txt","r",stdin);
    //freopen("out.txt","w",stdout);
    int a[] = {2, 5, 4, 1, 3};
    sort(a, a+5);
    for (int i = 0; i < 5; i++){
        cout << a[i] << " ";
    }
    cout << endl;
    return 0;
}
