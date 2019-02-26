#include <list>
#include <iostream>
#include <cstdio>
using namespace std;
void disp(list<int> &lst){
    list<int>::iterator it;
    for(it = lst.begin(); it != lst.end(); it++){
        printf("%d ", *it);
    }
    printf("\n");
}
int main(){
    list<int> lst;
    list<int>::iterator it, start, end;
    lst.push_back(5);
    lst.push_back(2); lst.push_back(4);
    lst.push_back(1); lst.push_back(3);
    printf("initial lst:"); disp(lst);
    it = lst.begin();
    start = ++lst.begin();
    end = --lst.end();
    lst.insert(it, start, end);
    printf("executed list.insert(it, start, end)\n");
    printf("after:");disp(lst);
    return 0;
}
