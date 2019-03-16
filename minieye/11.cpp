// 2019/03/16   11:37
// 题干中没有说是哪两个对角，以什么顺序给出，所以在读入数据之后要统一为
// leftdown righttop
#include <algorithm>
#include <cstdio>
#include <iostream>
#include <algorithm>
using namespace std;
int main(){
    // freopen("in.txt", "r", stdin);
    int x1, y1, x2, y2;
    int a1, b1, a2, b2;
    int m1, n1, m2, n2;
    scanf("%d%d%d%d", &m1, &n1, &m2, &n2);
    x1 = min(m1, m2); x2 = max(m1, m2);
    y1 = min(n1, n2); y2 = max(n1, n2);
    scanf("%d%d%d%d", &m1, &n1, &m2, &n2);
    a1 = min(m1, m2); a2 = max(m1, m2);
    b1 = min(n1, n2); b2 = max(n1, n2);
    
    m1 = max(x1, a1); n1 = max(y1, b1);
    m2 = min(x2, a2); n2 = min(y2, b2);
    if(m2 >= m1 && n2 >= n1){
        int w = m2-m1, h = n2-n1;
        cout << w*h << endl;
    }else{
        cout << 0 << endl;
    }
    return 0;
}
