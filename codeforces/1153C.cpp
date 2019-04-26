#include <iostream>
#include <cstring>
#include <cstdio>
using namespace std;
const int maxn = 3e5+5;
char a[maxn];
int main(){
    // freopen("in.txt", "r", stdin);
    int l; scanf("%d", &l);
    if(l&1) {cout << ":(\n"; return 0;}
    scanf("%s", a);
    int _left = 0, _right = 0;
    int sign = 0;
    bool flag = true;
    for(int i = 0; i < l; i++){
        if(a[i] == '(') _left++;
        if(a[i] == ')') _right++;
    }
    // cout << _left << " " << _right << endl;
    for(int i = 0; i < l; i++){
        if(a[i] == '(') {sign++; continue;}
        if(a[i] == ')') {
            sign--;
            if(i < l-1 && sign <= 0){
                flag = false; break;
            }
            continue;
        }
        if(_left < l/2){a[i] = '('; _left++; sign++;}
        else{
            a[i] = ')';
            sign--;
            if(i < l-1 && sign <= 0){flag = false; break;}
        }
    }
    if(flag && !sign){printf("%s\n", a);}
    else
        printf(":(\n");
    return 0;
}