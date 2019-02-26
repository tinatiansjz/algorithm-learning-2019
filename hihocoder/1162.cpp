// 2019/02/17 19:19
// A[1] xor A[2] xor ... xor A[N] = 0 -> P-position (Bob wins)
// else N-position (Alice wins)
#include <iostream>
#include <cstdio>
using namespace std;
int main(){
    freopen("in.txt", "r", stdin);
    int N; cin >> N;
    int ans = 0, tmp;
    for(int i = 0; i < N; i++){
        scanf("%d", &tmp);
        ans ^= tmp;
    }
    if(ans == 0) cout << "Bob" << endl;
    else cout << "Alice" << endl;
    return 0;
}