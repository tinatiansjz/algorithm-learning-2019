#include <iostream>
#include <cstdlib>
#include <cstdio>
#include <ctime>
using namespace std;
int main(){
    srand(time(NULL));
    int N = 5;
    while(N--){
        int ran = rand() % 10 + 1;
        cout << ran << endl;
    }
    cout << "Hello world!" << endl;
    return 0;
}
