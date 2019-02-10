// convert infix expression to postfix expression
// 2018/12/22   14:55
// https://www.cnblogs.com/hantalk/p/8734511.html
#include <iostream>
#include <cstdio>
#include <stack>
using namespace std;
vector<int> vcount;
vector<char> vop;
vector<int> postcount;
vector<char> postop;
vector<bool> seq;//1: num, 0: operator
stack<int> convert;
bool isOperator(char c){
    if(c == '+' | c == '-' | c == '*' | c == '/')
        return true;
    else return false;
}
int getPriority(char c){
    switch(c){
        case '+': case '-': return 1;
        case '*': case '/': return 2;
        default: return 0;
    }
}
bool priority(char c1, char c2){
    return getPriority(c1) <= getPriority(c2);
}
void in2post(){
    // initialize
    postcount.clear(); postop.clear();
    if(!convert.empty()){convert.pop();} convert.push('#');
    int i = 0, j = 0;//i: vcount, j: vop, k: seq
    while(i < vcount.size() && j < vop.size()){
        postcount.push_back(vcount[i++]); seq.push_back(true);
        while(priority(vop[j], convert.top())){
            char tmp = convert.top(); convert.pop();
            postop.push_back(tmp); seq.push_back(false);
        }
        convert.push(vop[j++]);
    }
    postcount.push_back(vcount[i]);//i = vcount.size()-1
    seq.push_back(true);
    while(convert.top() != '#'){
        char tmp = convert.top(); convert.pop(); 
        postop.push_back(tmp); seq.push_back(false);
    }
}
int main(){
    freopen("in.txt", "r", stdin);
    string line;
    while(getline(cin, line)){
        cout << line << endl;
        count.empty(); op.empty();
        int i = 0, j, num = 0;
        bool isnum = false;
        while(line[i]){
            if(isdigit(line[i])){
                num = 10*num + line[i]-'0';
                isnum = true;
                i++;
            }else{
                if(isnum){vcount.push_back(num); isnum = false; num = 0;}
                while(line[i] == ' ') {i++;}
                if(isOperator(line[i])) {vop.push_back(line[i]); i++;}
            }
        }
        in2post();
        while(!postop.empty()){
            cout << postop.top() << " "; postop.pop();
        }
        cout << endl;
    }
    return 0;
}
