#include<string.h>
#include<stdio.h>

int main(){
    freopen("P229_in.txt", "r", stdin);	
	int m,n;
	char str[101][20000];
	str[1][0]='1';
	for(int i=2; i<=100; i++){
		int k=1;
	 	int l=strlen(str[i-1]);
		for(int j=0; j<l; j++){
			int s;
			s = str[i-1][j]-'0';
			int b = s*4 + k;
			str[i][j] = b%10+'0';
			k = b/10;
		}
		while(k > 0){
			str[i][l++]=k%10+'0';
			k /= 10;
		}
	}
	scanf("%d", &m);
	while(m--){
		scanf("%d", &n);
		for(int i = strlen(str[n])-1; i>=0; i--){
			printf("%c", str[n][i]);
		}
		printf("\n");
	}
	return 0;
} 
