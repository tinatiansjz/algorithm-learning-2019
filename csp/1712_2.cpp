//201712_2
//2018/11/9
//use the queue to simulate the whole process
#include <iostream>
#include <queue>
using namespace std;
queue<int> q;
int n, k;
int main(){
    cin >> n >> k;
    for(int i = 1; i <= n; i++){
        q.push(i);
    }
    int head, num = 0;
    while(q.size() > 1){
        head = q.front();
        q.pop();
        num++;
        if(num%k != 0 && num%10 != k) q.push(head);
    }
    cout << q.front() << endl;
    return 0;
}
