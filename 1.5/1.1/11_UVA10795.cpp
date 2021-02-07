#include<cstdio>
using namespace std;
const int maxn=60+10;
int n,start[maxn],finish[maxn];

int f(int array[],int n,int pos){
	if(!n) return 0;
	while(array[n]==pos)n--;
	if(!n) return 0;
	return f(array,n-1,6-pos-array[n])+(1<<(n-1))+1;
}

int main(){
	while(scanf("%d",&n)==1&&n){
		for(int i=1;i<=n;i++) scanf("%d",&start[i]);
		for(int i=1;i<=n;i++) scanf("%d",&finish[i]);
		
		int ans=0;
		while(start[n]==finish[n]) n--;
		int other=6-start[n]-finish[n];
		ans=f(start,n-1,other)+f(finish,n-1,other)+1;
	}
	return 0;
}
