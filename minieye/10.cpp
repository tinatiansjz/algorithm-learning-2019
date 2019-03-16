// Minieye-10
// 2019/03/16   16:56
// 26.0/31.0    WA
#include <iostream>
#include <cstdio>
#include <cmath>
using namespace std;
const double eps = 1e-8;
const double pi = acos(-1.0);
inline double Sqrt(double a){return a*a;}
struct Point{
    double x, y, z;
    Point() {}
    Point(double x, double y, double z): x(x), y(y), z(z) {};
    double Length() const{
        return Sqrt(Sqrt(x) + Sqrt(y) + Sqrt(z));
    }
};
void debug(Point p){
    printf("%lf %lf %lf\n", p.x, p.y, p.z);
}
Point operator + (const Point& a, const Point& b){
    return Point(a.x+b.x, a.y+b.y, a.z+b.z);
}
Point operator - (const Point& a, const Point& b){
    return Point(a.x-b.x, a.y-b.y, a.z-b.z);
}
Point operator * (const Point& a, double b){
    return Point(a.x*b, a.y*b, a.z*b);
}
// cross product
Point det(Point a, Point b){
    return Point(a.y*b.z - a.z*b.y, a.z*b.x-a.x*b.z, a.x*b.y-a.y*b.x);
}
double dot(Point a, Point b){
    return a.x*b.x+a.y*b.y+a.z*b.z;
}
struct Line{
    Point a, b;
    Line(){}
    Line(Point a, Point b): a(a), b(b) {}
};
struct Plane{
    Point a, b, c;
    Plane(){}
    Plane(Point a, Point b, Point c): a(a), b(b), c(c) {}
};
// Plane's normal vector
Point pvec(Point s1, Point s2, Point s3){return det((s1-s2), (s2-s3));}
Point pvec(Plane pl){return det((pl.a-pl.b), (pl.b-pl.c));}
// the length of vector
double vlen(Point P){return P.Length();}
// check whether the value of double type is zero
bool zero(double x){return fabs(x) < eps;}
// check whether the two planes are parallel
bool parallel(Plane u, Plane v){return vlen(det(pvec(u), pvec(v))) < eps;}
// check whether a plane and a line is parallel
bool parallel(Line l, Plane s){return zero(dot(l.a-l.b, pvec(s)));}
// Find the intersection of a line and a plane
Point intersection(Line l, Plane s){
    Point ret = pvec(s);
    // debug(ret);
    double t = (ret.x*(s.a.x-l.a.x) + ret.y*(s.a.y-l.a.y) + ret.z*(s.a.z-l.a.z)) / 
        (ret.x*(l.b.x)+ret.y*(l.b.y)+ret.z*(l.b.z));
    ret = l.a + (l.b-l.a)*t;
    return ret;
}
// Find the intersection of two planes
bool intersection(Plane pl1, Plane pl2, Line &li){
    if(parallel(pl1, pl2)) return false;
    li.a = parallel(Line(pl2.a, pl2.b), pl1) ? intersection(Line(pl2.b, pl2.c), pl1) : intersection(Line(pl2.a, pl2.b), pl1);
    Point fa; fa = det(pvec(pl1), pvec(pl2));
    li.b = li.a+fa;
    return true;
}
int main(){
    // freopen("in.txt", "r", stdin);
    double m, n, k; scanf("%lf%lf%lf", &m, &n, &k);
    double x1, y1, z1, x2, y2, z2; scanf("%lf%lf%lf%lf%lf%lf", &x1, &y1, &z1, &x2, &y2, &z2);
    double a1, b1, c1, a2, b2, c2; scanf("%lf%lf%lf%lf%lf%lf", &a1, &b1, &c1, &a2, &b2, &c2);
    Point A = Point(x1, y1, z1), B = Point(x2, y2, z2);
    Point M = Point(a1, b1, c1), N = Point(a2, b2, c2);
    Point O = Point(m, n, k);
    Line l1 = Line(A, B), l2 = Line(M, N);
    Plane p1 = Plane(A, B, O), p2 = Plane(M, N, O);
    if(parallel(l1, p2)) {cout << "false" << endl; return 0;}
    if(parallel(l2, p1)) {cout << "false" << endl; return 0;}
    Point tmp1 = intersection(l1, p2);
    Point tmp2 = intersection(l2, p1);
    if(tmp1.x < min(x1, x2) || tmp1.x > max(x1, x2) || tmp1.y < min(y1, y2) || tmp1.y > max(y1, y2) || tmp1.z < min(z1, z2) || tmp1.z > max(z1, z2) ||\
        tmp2.x < min(a1, a2) || tmp2.x > max(a1, a2) || tmp2.y < min(b1, b2) || tmp2.y > max(b1, b2) || tmp2.z < min(c1, c2) || tmp2.z > max(c1, c2)){
        cout << "false" << endl; return 0;
    }
    if(dot(tmp1-O, tmp2-O) < 0){cout << "false" << endl; return 0;}
    cout << "true";
    return 0;
}