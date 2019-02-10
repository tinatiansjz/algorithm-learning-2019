#include <sstream>
#include <cstdio>
#include <iostream>
using namespace std;
int main(){
    freopen("P166_in.txt", "r", stdin);
    string s, buf;
    string name;
    while(cin >> name && name != "END"){
        while(getline(cin, s) && s != "0"){
            s[s.length()-1] = ' ';
            stringstream ss(s);
//            printf("**\n"); fflush(stdout);
            int r, c;
            ss >> r >> c;
            while(ss >> buf && buf[0] != '*'){
                //int d = dir_id(buf[0]);
                for (int i = 1; i < buf.length(); i++){
                    cout << buf << endl;
                    cout << r << '\t' << c << endl;
                    //int turn = turn_id(buf[i]);
                    //has_edge[r][c][d][turn] = true;
                }
            }
        }
    }
    return 0;
}
