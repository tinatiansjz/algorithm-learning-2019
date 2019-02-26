#include <iostream>
#include <vector>
using namespace std;
int main(){
    vector<int> myv;
    myv.push_back(1);
    myv.push_back(2);
    myv.push_back(3);
    vector<int>::iterator it;
    vector<int>::reverse_iterator rit;
    for (it=myv.begin(); it != myv.end(); it++){
        cout << *it;
    }
    cout << endl;
    for (rit=myv.rbegin(); rit != myv.rend(); ++rit){
        cout << *rit;
    }
    cout << endl;
    return 0;
}
