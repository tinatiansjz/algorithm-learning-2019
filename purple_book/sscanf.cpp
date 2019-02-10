#include <cstdio>
#include <cstring>
#include <iostream>
using namespace std;
const int maxn = 10000;
char s[maxn];
int main(){
    freopen("P151_in.txt", "r", stdin);
    for(;;){
        if(scanf("%s", s) != 1) break;
        if(!strcmp(s, "()")) break;
        int v;
        printf("s=%s\n", s);
        cout << "s[1]=" << s[1] << endl;
        sscanf(&s[1], "%d", &v);
        printf("v=%d\n", v);
    }
    return 0;
}
