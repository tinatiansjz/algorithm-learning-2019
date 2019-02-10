mem = {}
def f(n):
    global mem
    if n<4: return 4;
    if n in mem: return mem[n];
    mem[int(n/2)] = f(int(n/2))
    mem[int(3*n/4)] = f(int(3*n/4))
    mem[n] = mem[int(n/2)] + mem[int(3*n/4)]
    return mem[n];

def getval(n):
    return pow(n, 1.5)

for i in range(100):
    val = pow(10, i)
    fn = f(val)
    gn = getval(val)
    print(i, abs(gn-fn)/fn, fn, gn);
