#include<stdio.h>
#include<math.h>
const int N=1002;
int ans[N];

int main(){
	int n,cas=1;
	ans[0]=0;
	for(int i=1;i<N;i++)
		ans[i]=ceil(log(i)/log(2));
	while(scanf("%d",&n)&&n>=0)
		printf("Case %d:%d\n",cas++,ans[n]);
	
	return 0;
}
