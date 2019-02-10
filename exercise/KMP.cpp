#include <iostream>
#include <cstdio>
using namespace std;
const int maxn = 100005;

int knext[maxn], prefix[maxn];
char t[maxn], s[maxn];

void getknext(){
    knext[0] = prefix[0] = -1;
    int k = -1;
    for (int i = 0; t[i];){
        if(k == -1 || t[i] == t[k]){
            k++; i++;
            prefix[i] = k;
            if(t[i] == t[k]) knext[i] = knext[k];
            else knext[i] = k;
        }else k = prefix[k];
    }
}
bool match(){
    for(int i = 0, j = 0;; j==-1?(j++, i++):j){
        if(t[j] == 0) return 1;
        if(s[i] == 0) return 0;
        if(s[i] == t[j]){
            i++; j++;
        }else{
            j = knext[j];
        }
    }
}
void disp(){
    cout << "knext[]: ";
    for(int i = 0; t[i]; i++){
        cout << knext[i] << " ";
    }
    cout << endl;
}
int main(){
    freopen("KMP_in.txt", "r", stdin);
    cin >> t;
    cout << "pattern string: " << t << endl;
    getknext();
    disp();
    while(cin >> s){
        cout << s << ": ";
        if(match()) cout << 1 << endl;
        else cout << 0 << endl;
    }
    return 0;
}
