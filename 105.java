// https://developer.aliyun.com/coding/105
package solution105;

class Solution {
    public long solution(int n, long[] nums) {
        int[] a = dfs(0, n-1, 1, 1, nums);
        long ret = 0;
        for(int i = 0; i < n; i++){
            ret += a[i]*nums[i];
        }
        return ret;
    }
    private int[] dfs(int l, int r, int x, int y, long[] nums){
        // dfs(l, r, x, y)表示左端点、右端点、左端点的贡献、右端点的贡献的区间合并成两个数的最小和
        int[] a= new int[r-l+1];//放大序列
        a[0] = x;
        a[r-l] = y;
        if(r - l == 1){
            return a;
        }
        if(r - l == 2){
            a[1] = x + y;
        }else{
            long Min = Long.MAX_VALUE;
            for(int i = l+1; i < r; i++){//从l到r枚举最后取出元素。
                int[] k1 = dfs(l, i, x, y+x, nums);//在l-i区间枚举倒数第二取出元素
                int[] k2 = dfs(i, r, x+y, y, nums);//在i-r区间枚举倒数第二取出元素
                long MM = 0;
                for(int j = l; j < i; j++){
                    MM += k1[j-l] * nums[j];
                }
                for(int j = i; j <= r; j++){
                    MM += k2[j-i] * nums[j];
                }
                if(MM < Min){//更新放大序列为最小值
                    for(int j = l; j < i; j++){
                        a[j-l] = k1[j-l];
                    }
                    for(int j = i; j <= r; j++){
                        a[j-l] = k2[j-i];
                    }
                    Min = MM;
                }
            }
        }
        return a;
    }
}
