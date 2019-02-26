#include <iostream>
#include <algorithm>
#include <cstdio>
using namespace std;
int arr[1010];
int main(){
    freopen("1612-1_in.txt", "r", stdin);
    int n;
    cin >> n;
    for (int i = 1; i < n+1; i++){
        cin >> arr[i];
    }
    sort(arr+1, arr+n+1);
    int mid_id = (n+1) / 2;
    int mid = arr[mid_id];
    int l = 0, r = 0;
    for (int i = 1; i < mid_id; i++){
        if(arr[i] < mid) l++;
    }
    for (int i = mid_id+1; i < n+1; i++){
        if(arr[i] > mid) r++;
    }
    if(l == r){
        cout << mid << endl;
    }else{
        cout << "-1" << endl;
    }
    return 0;
}
