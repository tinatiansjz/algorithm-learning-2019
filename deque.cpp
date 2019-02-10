#include <iostream>
#include <cstdio>
#include <deque>
using namespace std;
deque<int> dq;
int main(){
    dq.push_back(1);
    dq.push_back(2);
    dq.push_back(3);
    dq.push_back(4);
    dq.push_back(5);
    dq.push_back(6);
    for(int i = 0; i < dq.size(); i++){
        cout << dq[i] << " ";
    }
    cout << endl;
    dq.pop_front();
    for(int i = 0; i < dq.size(); i++){
        cout << dq[i] << " ";
    }
    cout << endl;
    return 0;
}
