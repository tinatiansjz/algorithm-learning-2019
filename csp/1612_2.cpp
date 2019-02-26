//enumeration method
//2018/11/10 14:17
#include <iostream>
#include <cstdio>
using namespace std;
int main(){
    int t, a, ans;
    cin >> t;
    for(int i = 0; i <= 1800; i++){//Brute Force
        int a = i*100 - 3500;
        if(a <= 0){
            ans = i*100;
        }else if(a<=1500){
            ans = a*0.97 + 3500;
        }else if(a <= 4500){
            ans = (a-1500)*0.9 + 1500*0.97 + 3500;
        }else if(a <= 9000){
            ans = (a-4500)*0.8 + 3000*0.9 + 1500*0.97 + 3500;
        }else if(a <= 35000){
            ans = (a-9000)*0.75 + 4500*0.8 + 3000*0.9 + 1500*0.97 + 3500;
        }else if(a <= 55000){
            ans = (a-35000)*0.7 + 26000*0.75 + 4500*0.8 + 3000*0.9 + 1500*0.97 + 3500;
        }else if(a <= 80000){
            ans = (a-55000)*0.65 + 20000*0.7 + 26000*0.75 + 4500*0.8 + 3000*0.9 + 1500*0.97 + 3500;
        }else{
            ans = (a-80000)*0.55 + 25000*0.65 + 20000*0.7 + 26000*0.75 + 4500*0.8 + 3000*0.9 + 1500*0.97 + 3500;
        }
        if(ans == t){
            cout << i*100 << endl;
            break;
        }
    }
    return 0;
}
