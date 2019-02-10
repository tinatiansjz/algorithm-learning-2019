#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
bool cmp(const int& a, const int& b){
    return a > b;
}
int main(){
    vector<int> myv;
    myv.push_back(5);
    myv.push_back(6);
    myv.push_back(-1);
    sort(myv.begin(), myv.end(), cmp);
    for(vector<int>::iterator it = myv.begin(); it != myv.end(); it++){
        cout << *it << endl;
    }
    return 0;
}
