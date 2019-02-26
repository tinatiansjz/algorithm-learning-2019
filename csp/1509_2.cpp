#include <iostream>
#include <cstdio>
using namespace std;
int a[12] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
int b[12] = {31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};//more = true
int main(){
    freopen("1509_2_in.txt", "r", stdin);
    int y, d;
    cin >> y >> d;
    bool more = false;
    if((y%4 == 0 && y%100 != 0) || (y%400 == 0)) more = true;
    if(!more){
        int day = 0, i;
        for(i = 0; i < 12; i++){
            if(day+a[i] < d){day += a[i];}
            else break;
        }
        cout << (i+1) << endl << (d - day) << endl;
    }else{
        int day = 0, i;
        for(i = 0; i < 12; i++){
            if(day+b[i] < d){day += b[i];}
            else break;
        }
        cout << (i+1) << endl << (d - day) << endl;
    }
    return 0;
}