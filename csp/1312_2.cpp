#include <iostream>
#include <cstdio>
#include <string>
using namespace std;
int main(){
    freopen("1312_2_in.txt", "r", stdin);
    string isbn;
    int num[10];
    int iden = 0;
    char cden;
    cin >> isbn;
    int j = 0;
    for(int i = 0; i < isbn.length(); i++){
        if(i==1 || i==5 || i==11){continue;}
        num[j++] = isbn[i] - '0';
    }
    for(int i = 0; i < 9; i++){
        iden = (iden + num[i]*(i+1))%11;
    }
    if(iden == 10) cden = 'X';
    else cden = '0' + iden;
    if(cden == isbn[12]) printf("Right\n");
    else{
        for(int i = 0; i < isbn.length()-1; i++){
            cout << isbn[i];
        }
        cout << cden << endl;
    }
    return 0;
}
