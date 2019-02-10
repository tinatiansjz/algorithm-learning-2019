//kangba
#include <iostream>
#include <cstdio>
#include <cmath>
using namespace std;
int brute_force(char* s, char* t, int tn){
    int i = 0, j = 0, k = 0;
    while(s[i] != 0 && j < tn){
        if(s[i] == t[j]){
            i++;j++;
        }else{
            i = i-j+1;
            j = 0;
        }
        if(j == tn){
            k++; j = 0;
        }
    }
    return k;
}
int main(){
    freopen("cf877a_in.txt", "r", stdin);
    char str[200];
    char str1[] = "Danil"; int tn1 = 5;
    char str2[] = "Olya"; int tn2 = 4;
    char str3[] = "Ann"; int tn3 = 3;
    char str4[] = "Nikita"; int tn4 = 6;
    char str5[] = "Slava"; int tn5 = 5;
    while(cin >> str){
        int sum;
        sum = brute_force(str, str1, tn1);
        sum += brute_force(str, str2, tn2);
        sum += brute_force(str, str3, tn3);
        sum += brute_force(str, str4, tn4);
        sum += brute_force(str, str5, tn5);
        if(sum == 1) cout << "YES\n" << endl;
        else cout << "NO\n" << endl;
    }
    return 0;
}
