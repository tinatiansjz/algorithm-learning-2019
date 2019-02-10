// 四则运算
// first convert then calculate
// convert infix expression to postfix expression
// 2018/12/22   14:55
// https://www.cnblogs.com/hantalk/p/8734511.html
#include <iostream>
#include <cstdio>
#include <stack>
#include <vector>
using namespace std;
vector<int> vcount;
vector<char> vop;
vector<int> postcount;
vector<char> postop;
vector<bool> seq;//1: num, 0: operator
stack<int> cal;
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
    stack<char> convert; // convert
    // initialize
    if(!convert.empty()){convert.pop();} convert.push('#');
    int i = 0, j = 0;//i: vcount, j: vop
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
bool calculate(){
    int i = 0, j = 0, k = 0;//i: poscount, j: posop, k: seq
    while(k < seq.size() && (i < postcount.size() || j < postop.size())){
        if(seq[k++]){//num
            cal.push(postcount[i++]);
        }else{
            int tmp2 = cal.top(); cal.pop();
            int tmp1 = cal.top(); cal.pop();
            int tmpans;
            char op = postop[j++];
            if(op == '+') tmpans = tmp1 + tmp2;
            else if(op == '-') tmpans = tmp1 - tmp2;
            else if(op == '*') tmpans = tmp1 * tmp2;
            else if(op == '/'){
                if(tmp2 == 0) return 0; // error!
                else tmpans = tmp1 / tmp2;
            }
            cal.push(tmpans);
        }
    }
    if(cal.size() == 1) return 1;
}
void init(){
    vcount.clear(); vop.clear(); seq.clear();
    postcount.clear(); postop.clear();
    if(!cal.empty()){cal.pop();} 
}
int main(){
    // freopen("in.txt", "r", stdin);
    // freopen("out.txt", "w", stdout);
    string line;
    while(getline(cin, line)){
// handle the input data
// ----------------------------------------------------------------
        init();
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
        if(isnum){vcount.push_back(num); isnum = false; num = 0;}
// ------------------------------------------------------------------
        in2post();
        if(calculate()) cout << cal.top() << endl;
        else cout << "err" << endl;
    }
    return 0;
}





// for(int i = 0; i < postop.size(); i++)
//     cout << postop[i] << " ";
// cout << endl;
// for(int i = 0; i < postcount.size(); i++)
//     cout << postcount[i] << " ";
// cout << endl;
// for(int i = 0; i < seq.size(); i++)
//     cout << seq[i] << " ";
// cout << endl;
