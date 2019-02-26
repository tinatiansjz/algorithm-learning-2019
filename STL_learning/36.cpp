#include <deque>
#include <iostream>
#include <cstdio>
using namespace std;
void disp(deque<int> &dq){
    deque<int>::iterator iter;
    for (iter=dq.begin(); iter != dq.end(); iter++){
        printf("%d ", *iter);
    }
    printf("\n");
}

int main(){
    deque<int> dq;
    dq.push_front(1);
    dq.push_back(2);
    dq.push_front(3);
    dq.push_back(4);
    printf("dq: "); disp(dq);
    cout << "front: " << dq.front() << endl;
    cout << "back: " << dq.back() << endl;
    dq.pop_front();
    dq.pop_back();
    printf("dp: "); disp(dq);
    return 0;
}
