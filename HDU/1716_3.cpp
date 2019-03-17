//kangba
//2018/11/1 18:00
#include <cstdio>
#include <iostream>
#include <algorithm>
using namespace std;
int main(){
    freopen("HDU-1716_in.txt", "r", stdin);
    int A[4];
    int first = 1;
    while(cin>>A[0]>>A[1]>>A[2]>>A[3]){
        if(!A[0] && !A[1] && !A[2] && !A[3]) break;
        if(first == 1){
            first = 0;
        }else{
            cout << endl << endl;
        }
        sort(A, A+4);
        for(int i = 0; i < 4; i++){
            if(A[0] != 0) cout << A[i];
        }
        int last = A[0];
        while(next_permutation(A, A+4)){
            if(A[0] == 0) continue;
            if(A[0] == last) {cout << " ";}
            else{
                if(last != 0) cout << endl; 
                last = A[0];
            }
            for(int i = 0; i < 4; i++){
                cout << A[i];
            }
        }
    }
    cout << endl;
    return 0;
}
