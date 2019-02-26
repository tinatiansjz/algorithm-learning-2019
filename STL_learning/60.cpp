#include <queue>
#include <iostream>
using namespace std;
int main(){
    priority_queue<int> qu;
    qu.push(3); qu.push(1); qu.push(2);
    cout << "队头元素:" << qu.top() << endl;
    cout << "出队顺序:";
    while(!qu.empty()){
        cout << qu.top();
        qu.pop();
    }
    cout << endl;
    return 0;
}
