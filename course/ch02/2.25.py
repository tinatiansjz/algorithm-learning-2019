#-*- coding:utf-8 -*-
#2.25 bisection method
def getval(x):
    return pow(0.5, x)+pow(0.75, x)
l = 1
r = 2
e = 0.0000000000001
while (r-l)>e:
    mid = (l+r)/2
    if getval(mid)>1:
        l = mid;
    else:
        r = mid;
    print(l)
