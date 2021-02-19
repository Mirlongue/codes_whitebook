#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
const int maxn=100000+10;
int n;
int r[maxn];

bool check(int x){
	int tag,tmp;
	tag=r[0];
	for(int i=1;i<n-1;i++){
		if(i&1){
			tmp=x-r[i]+1;
			if(tmp<=tag) return false;
			tag=tmp;
		}else{
			tmp=r[i];
			if(tmp>=tag) return false;
			tag=tmp;
		}
	}
	if(r[0]+x-tag+1+r[n-1]>x) return false;
	return true;
}

int main(){
	while(scanf("%d",&n)){
		for(int i=0;i<n;i++) scanf("%d",&r[i]);
		
		int L=0;
		for(int i=0;i<n;i++)
			L=max(L,r[i]+r[(i+1)%n]);
		if(!n&1){
			printf("%d\n",L);
			continue;
		}
		int R=0;
		for(int i=0;i<n;i++)
			R=max(R,r[i]+r[(i+1)%n]+r[(i+2)%n]);
		
		int M;
		while(L<=R){
			M=L+R>>1;
			if(check(M)) R=M-1;
			else L=M+1;
		}
		printf("%d\n",L);
	}	
	return 0;
}
