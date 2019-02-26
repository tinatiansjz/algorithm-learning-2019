#include <iostream>
#include <cstdio>
#include <set>
using namespace std;
struct Candidate{
    int a, g;
    Candidate(int a, int g): a(a), g(g) {}
    bool operator < (const Candidate& rhs) const {
        return a < rhs.a || (a == rhs.a && g < rhs.g);
    }
};
int main(){
    set<Candidate> s;
    s.clear();
    s.insert(Candidate(3, 4));
    s.insert(Candidate(4, 4));
    s.insert(Candidate(5, 4));
    for(set<Candidate>::iterator it = s.begin(); it != s.end(); it++){
        cout << it->a << " " << it->g << endl;
    }
    s.erase(Candidate(3,3));
    cout << endl;
    for(set<Candidate>::iterator it = s.begin(); it != s.end(); it++){
        cout << it->a << " " << it->g << endl;
    }
    return 0;
}
