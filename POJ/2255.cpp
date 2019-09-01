// tree: preorder inorder postorder
// recursive
#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;
const int maxn = 30;
char pre[maxn];
char in[maxn];
void cal(int pre1, int pre2, int in1, int in2){
	// preorder: [pre1, pre2], inorder: [in1, in2]
	if(pre1 > pre2 || in1 > in2) return;
	if(pre1 == pre2){
		printf("%c", pre[pre1]);
		return;
	}
	char top = pre[pre1];
	int lchild = 0;
	while((in1+lchild) <= in2 && in[in1+lchild] != top) lchild++;
	cal(pre1+1, pre1+lchild, in1, in1+lchild-1);
	cal(pre1+lchild+1, pre2, in1+lchild+1, in2);
	printf("%c", top);
}
int main(){
	// freopen("in.txt", "r", stdin);
	while(scanf("%s%s", pre, in) != EOF){
		int len1 = strlen(pre);
		int len2 = strlen(in);
		cal(0, len1-1, 0, len2-1);
		printf("\n");
	}
	return 0;
}