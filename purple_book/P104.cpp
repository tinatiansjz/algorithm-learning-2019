#include <cstdio>
#include <iostream>
#include <string>
#include <sstream>
#include <ctime>
using namespace std;
int main(){
    clock_t start, finish;
    double duration;
    start = clock();
    freopen("104.txt", "r", stdin);
    string line;
    while(getline(cin, line)){
        int sum = 0, x;
        stringstream ss(line);
        while(ss >> x) sum += x;
        cout << sum << endl;
    }
    finish = clock();
    duration = (double)(finish - start) / CLOCKS_PER_SEC;
    cout << "duration: " << duration << " seconds\n";
    return 0;
}
