// https://www.luogu.org/problemnew/show/P1024
#include <iostream>
#include <cstdio>
using namespace std;
double a, b, c, d;
double value(double x){
    return a*x*x*x + b*x*x + c*x +d;
}
bool samesign(double x, double y){
    return (value(x) > 0 && value(y) > 0) || (value(x) < 0 && value(y) < 0);
}
int main(){
    freopen("in.txt", "r", stdin);
    cin >> a >> b >> c >> d;
    for(int i = -100; i <= 100; i++){
        double low = i, high = i+1;
        double x1 = value(low), x2 = value(high);
        if(x1 == 0){//Only judge whether the left endpoint is zero (Prevent duplication)
            printf("%.2lf ", low); continue;
        }
        if(x1*x2 < 0){
            double mid = (low+high)/2;
            while(high-low >= 0.001){
                double x3 = value(mid);
                if(x3*x2 <= 0) low = mid;
                else high = mid;
            }
            printf("%.2lf ", low);
        }
    }
    return 0;
}