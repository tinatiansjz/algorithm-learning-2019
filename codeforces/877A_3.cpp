    //CodeForces - 877A
    //2018/10/28    20:47
    //KMP
    #define LOCAL
    #include <cstdio>
    #include <vector>
    #include <iostream>
    #include <cstring>
    #include <string>
    using namespace std;
    vector<string> s;
    bool flag;
    const int maxn = 110;
    void getknext(string p, int* knext, int* prefix){//pattern string
        knext[0] = prefix[0] = -1;
        int k = -1;
        for(int i = 0; p[i];){
            if(k == -1 || p[i] == p[k]){
                k++; i++;
                prefix[i] = k;
                if(p[i] == p[k]) knext[i] = knext[k];
                else knext[i] = k;
            }else{
                k = prefix[k];
                //k = knext[k];
            }
        }
    }
    int match(char* m, string p, int* knext){//main string, pattern string
        int len = strlen(m);
        for(int i = 0, j = 0;; j==-1?(j++, i++):j){
            if(p[j] == 0){flag = true; return i;}
            if(m[i] == 0){flag = false; return len;}
            if(p[j] == m[i]){
                i++; j++;
            }else{
                j = knext[j];
            }
        }
    }
    void disp(string p, int* knext){
        cout << "knext[]: ";
        for(int i = 0; i < p.size(); i++){
            cout << knext[i] << " ";
        }
        cout << endl;
    }
    int main(){
    #ifdef LOCAL
        freopen("cf877a_in.txt", "r", stdin);
    #endif
        s.push_back("Danil");
        s.push_back("Olya");
        s.push_back("Slava");
        s.push_back("Ann");
        s.push_back("Nikita");
        char name[maxn];
        int kv[5][maxn];
        int pv[5][maxn];
        for(int i = 0; i < 5; i++){
            getknext(s[i], kv[i], pv[i]);
    //        disp(s[i], knext);
        }
        while(cin >> name){
            int len = strlen(name);
            int ans = 0;
            for(int i = 0; i < 5; i++){
                int j = 0, pre = 0;
                do{
                    j = match(name+pre, s[i], kv[i]);
                    pre += j;
                    if(flag) {ans++;}
                    //cout << "pre:" << pre << " j:" << j << endl;
                }while(pre < len);
            }
            if(ans == 1) cout << "YES\n";
            else cout << "NO\n";
        }
        return 0;
    }
