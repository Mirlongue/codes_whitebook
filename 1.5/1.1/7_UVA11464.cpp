#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
int n;
int g[15][15];

int res;
int t[15];

int check(){
	int ans=0;
	int v[3][16];
	int tag=1;
	memset(v,0,sizeof(v));
	for(int i=1;i<=n;i++)
		v[1][i]=t[i-1];
	
	for(int i=1;i<n;i++){
		int nxt=(tag+1)%3;
		int pre=(tag+2)%3;
		
		for(int j=1;j<=n;j++)
			v[nxt][j]=(v[pre][j]+v[tag][j-1]+v[tag][j+1])%2;
		
		for(int j=1;j<=n;j++){
			if(v[nxt][j]<g[i][j-1]) return -1;
			if(v[nxt][j]>g[i][j-1]) ans++;
		}
		
		tag=nxt;
	}
	return ans;
}

void dfs(int d,int w){
	if(d==n){
/*
		for(int i=0;i<n;i++)
			printf("%d ",t[i]);
		printf("   %d\n",w);
*/
		int tmp= check();
		if(tmp!=-1){
			if(res==-1) res=tmp+w;
			else res=min(res,tmp+w);
		}
		return;
	}
	if(t[d]){
		dfs(d+1,w);
	} 
	else{
		dfs(d+1,w);
		t[d]=1;
		dfs(d+1,w+1);
		t[d]=0;
	}
	
}

int main(){
	
	while(scanf("%d",&n)&&n){
		for(int i=0;i<n;i++)
			for(int j=0;j<n;j++)
				scanf("%d",&g[i][j]);
		printf("\n");
		for(int i=0;i<n;i++)
			t[i]=g[0][i];
			
		res=-1;
		dfs(0,0);
		printf("%d\n",res);
	}
	
	return 0;
}
