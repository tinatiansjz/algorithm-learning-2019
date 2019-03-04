#include <iostream>
#include <cstdio>
#include <cmath>
using namespace std;
int main(){
    // freopen("in.txt", "r", stdin);
    double x1, y1, z1, r1; scanf("%lf%lf%lf%lf", &x1, &y1, &z1, &r1);
    double x2, y2, z2, r2; scanf("%lf%lf%lf%lf", &x2, &y2, &z2, &r2);
    double d = sqrt(pow(x1-x2, 2)+pow(y1-y2, 2)+pow(z1-z2, 2));
    // cout << d << endl;
    // cout << r1 << " " << r2 << endl;
    double ans;
    if(d >= r1+r2){
        ans = M_PI*4/3*(pow(r1, 3)+pow(r2, 3));
        // cout << M_PI << endl;
    }else if(d <= fabs(r1-r2)){
        ans = M_PI*4/3*pow(max(r1, r2), 3);
    }else{
        // r = r1, h = r1-(r1^2-r2^2+d^2)/(2*d);
        // r = r2, h = r2-(r2^2-r1^2+d^2)/(2*d);
        // 球冠体积(微积分来求): V = h^2*PI(3r-h)/3
        double h1 = r1-(pow(r1, 2)-pow(r2, 2)+pow(d, 2))/(2*d);
        double h2 = r2-(pow(r2, 2)-pow(r1, 2)+pow(d, 2))/(2*d);
        double V1 = pow(h1, 2)*M_PI*(3*r1-h1)/3;
        double V2 = pow(h2, 2)*M_PI*(3*r2-h2)/3;
        ans = M_PI*4/3*(pow(r1, 3)+pow(r2, 3)) - V1 - V2;
    }
    printf("%.7f\n", ans);
    return 0;
}