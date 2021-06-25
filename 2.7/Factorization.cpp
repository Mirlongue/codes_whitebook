#include<cstdio>
#include<cmath>
using namespace std;

int ans[1000];
int k;

void get(int n){
	k=0;
	for(int i=2;i<=(sqrt(n+0.5));i++){
		printf("%d:%d ",i,n);
		if(n%i==0){
			ans[k++]=i;
			while(n%i==0) n=n/i;
		}
		printf("%d\n",n);
	}
	if(n>1) ans[k++]=n;
	for(int i=0;i<k;i++)
		printf("%d ",ans[i]);
	printf("\n");
}

int main(){
	
	int x;
	while(scanf("%d",&x)!=EOF){
		get(x);
	}
	
	return 0;
}
