// 遇到 0 的时候直接清空 pre 数组，那么询问末尾 k 个数的乘积，
// 如果 pre 数组的长度小于 kk，说明末尾 kk 个数里肯定有 0, 直接输出 0 即可，否则输出 pre[n]/pre[n-k]
// clever！
class ProductOfNumbers {
public:
    static const int maxn = 4e4+5;
    int pre[maxn];
    int len;
    ProductOfNumbers() {
        pre[0] = 1;
        len = 0;
    }
    
    void add(int num) {
        if(num == 0){
            len = 0;
        }else{
            pre[++len] = num;
            pre[len] *= pre[len-1];
        }
    }

    int getProduct(int k) {
        if(k > len) return 0;
        return pre[len]/pre[len-k];
    }
};