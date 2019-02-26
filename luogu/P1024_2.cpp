//https://www.luogu.org/problemnew/solution/P1024
#include <cstdio>
using namespace std;
double a, b, c, d;
double value(double x){
    return a*x*x*x + b*x*x + c*x + d;
}
int main(){
    freopen("in.txt", "r", stdin);
    double l, r, m, x1, x2;
    int s = 0, i;
    scanf("%lf%lf%lf%lf", &a, &b, &c, &d);
    for(int i = -100; i < 100; i++){
        l = i; r = i+1;
        x1 = value(l); x2 = value(r);
        if(!x1){//判断左端点，是零点直接输出
            printf("%.2f ", l);
            s++;
        }//不能判断右端点，会重复
        if(x1*x2 < 0){
            while(r-l >= 0.001){
                m = (r+l)/2;
                if(value(m)*value(r) <= 0) l = m;
                else r = m;
            }
            printf("%.2lf ", l); s++;//输出右端点(左右均可）
        }
        if(s == 3) break;
    }
    return 0;
}
