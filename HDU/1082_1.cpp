//杭电acm—1082 Matrix Chain Multiplication
//https://blog.csdn.net/qq_39598086/article/details/76552129
#include <stdio.h>
#include <string.h>
int hgs[30][2];
int s[1000][2];
int main(){
    freopen("in.txt", "r", stdin);
    int n;
    char str[1000];
    scanf("%d", &n);
    for (int i = 0; i < n; i++){
        char c;
        int x, y;
        getchar();//清除输入缓冲区中scanf产生的'\n'字符
        scanf("%c%d%d", &c, &x, &y);
        hgs[c-'A'][0] = x;
        hgs[c-'A'][1] = y;
    }
    char _ = getchar();
    //printf("%d\n", _);
    int line = 0;
    while(scanf("%s", str) != EOF){
        //printf("line%d:", ++line);
        int length = strlen(str);
        int sum = 0, k = 0, flag = 0;
        if(length == 1){
            printf("0\n");
        }else{
            for (int i = 0; i < length; i++){
                if(str[i] == '('){
                    continue;
                }else if(str[i] == ')'){
                    //一旦出现')'，意味着有两个要相乘
                    if(s[k-2][1] != s[k-1][0]){//判断是否可以相乘
                        flag = 1;
                        break;
                    }
                    sum += s[k-2][0]*s[k-1][0]*s[k-1][1];
                    s[k-2][1] = s[k-1][1];//把B的列赋给A的列
                    k--;//A乘B得到A,所以k--
                }else{
                    s[k][0] = hgs[str[i]-'A'][0];
                    s[k][1] = hgs[str[i]-'A'][1];
                    k++;
                }
            }
            if(flag){
                printf("error\n");
            }else{
                printf("%d\n", sum);
            }
        }
    }
    return 0;
}
