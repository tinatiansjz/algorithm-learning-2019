//https://codeforces.com/contest/1092/problem/C
#include <iostream>
#include <string>
#include <vector>
#include <cstdio>
using namespace std;

int N;
string S[202];
vector<int> V[101];
int did[202];

void solve() {
    int k,l,r,x,y; string s;
    
    cin>>N;
    for(int i = 0; i < 2*N-2; i++){
        cin>>S[i];
        V[S[i].size()].push_back(i);
    }
    
    for(auto& a: V[1]){
        for(auto& b: V[N-1]) {
            for(int i = 0; i < 2; i++) {
                string T;
                if(i == 0) T = S[a]+S[b];
                else T = S[b]+S[a];
                int j = 0;
                for(j = 0; j < 2*N-2; j++) {
                    if(S[j] != T.substr(0,S[j].size()) && S[j] != T.substr(N-S[j].size()))
                        break;
                }
                if(j != 2*N-2)
                    continue;
                for(int j = 0; j < 2*N-2; j++) {
                    if(S[j]==T.substr(0,S[j].size()) && did[S[j].size()]==0) {
                        cout<<"P";
                        did[S[j].size()]=1;
                    }
                    else cout<<"S";
                }
                cout<<endl;
                return;       
            }
        }
    }
}


int main(int argc,char** argv){
    // string s;int i;
    // if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
    // FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
    // cout.tie(0);
    freopen("A_in.txt", "r", stdin);
    solve();
    return 0;
}