#include <cstdio>
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
void test_sort(vector<int> v){
    sort(v.begin(), v.end());
}
int main(){
    vector<int> v;
    v.push_back(5);
    v.push_back(3);
    v.push_back(6);
    test_sort(v);
    for(vector<int>::iterator it = v.begin(); it != v.end(); it++){
        cout << *it << '\t';
    }
    return 0;
}
