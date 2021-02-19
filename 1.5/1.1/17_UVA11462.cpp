#include<cstdio>
#include<cstring>
int main(){
	int n,x,c[101];
	while(scanf("%d",&n)==1&&n){
		memset(c,0,sizeof(c));
		for(int i=0;i<n;i++){
			scanf("%d",&x);
			c[x]++;
		}
		int first=1;
		for(int i=1;i<=100;i++)
			for(int j=0;j<c[i];j++){
				if(!first) printf(" ");
				first=0;
				printf("%d",i);
			}
		printf("\n");
	}
	return 0;
}
