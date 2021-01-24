#include<cstdio>
#include<algorithm>
#include<cstring>
using namespace std;
const int maxn=20;
int n;
int d[1<<16];
int s[maxn];

int covers(int x){
	int tmp=0;
	for(int i=0;i<n;i++)
		if(x&(1<<i)){
			tmp=tmp|s[i];
		}
	if(tmp==(1<<n)-1) return 1;
	else return 0;
}

int main(){
	while(scanf("%d",&n)&&n){
		for(int i=0;i<n;i++){
			int m;s[i]=0;
			scanf("%d",&m);
			for(int j=0;j<m;j++){
				int x;
				scanf("%d",&x);
				s[i]+=1<<x;				
			}
		}
		memset(d,0,sizeof(d));
		
		for(int i=1;i<(1<<n);i++){
			for(int j=i;j;j=(j-1)&i){
				if(covers(j))
					d[i]=max(d[i],d[i-j]+1);
				else
					d[i]=max(d[i],d[i-j]);
			}
		}
		
		printf("%d\n",d[(1<<n)-1]);
		
		}
		return 0;
	}

