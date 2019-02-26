#include <iostream>
using namespace std;
const int maxn = 1010;
int a[maxn];
int total = 1;
int main(){
    freopen("1509_1_in.txt", "r", stdin);
    int n;
    cin >> n;
    for(int i = 0; i < n; i++) cin >> a[i];
    int current = a[0];
    for (int i = 1; i < n; i++){
        if(a[i] == current) continue;
        current = a[i]; total++;
    }
    cout << total << endl;
    return 0;
}