#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;
void swap(int* s, int i, int j){
    int tmp = s[i]; s[i] = s[j]; s[j] = tmp;
}
void permutation(int* s, int k, int m){
    if(k == m){
        for(int i = 0; i <= m; i++){
            cout << s[i];
        }
        cout << endl;
    }else{
        for(int i = k; i <= m; i++){
            //从固定的数后第一个依次交换
            swap(s, k, i);
            permutation(s, k+1, m);
            //这组递归完成后需要交换回来
            swap(s, k, i);
        }
    }
}
int main(){
    int s[] = {1, 2, 3, 4};
    permutation(s, 0, 3);
    cout << "s[]:" << endl;
    for(int i = 0; i < 4; i++){
        cout << s[i];
    }
    cout << endl;
    return 0;
}
