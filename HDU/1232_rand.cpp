#include <cassert>
#include <iostream>
#include <ctime>
#include <cstdio>
#include <cstdlib>
using namespace std;
int main(){
    freopen("HDU-1232_in.txt", "w", stdout);
    srand(time(NULL));
    int n = 10;
    while(n--){
        int N = rand() % 10 + 2;
        int M = rand() % 10 + 1;
        cout << N << " " << M << endl;
        for (int i = 0; i < M; i++){
            int rhs = rand() % N + 1;
            int lhs;
            do{lhs = rand() % N + 1;}while(rhs == lhs);
            printf("%d %d\n", rhs, lhs);
        }
    }
    cout << "0" << endl;
    return 0;
}
