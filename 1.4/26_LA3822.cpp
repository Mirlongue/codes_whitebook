//Ô¼Éª·ò»· f(1)=0,f(n)=(f(n-1)+k)%n;
#include<cstdio>
using namespace std;
int n,k,m;
int main(){
	while(scanf("%d%d%d",&n,&k,&m)!=EOF){
		if(n==0) break;
		int f=0;
		for(int i=2;i<n;i++)
			f=(f+k)%i;
		f=(f+m)%n;
		printf("%d\n",f+1);
	}
} 
