#include<stdio.h>
#include<string.h>
#include<vector>
#include<map>
using namespace std;
const int N=35;
int n,m,p[N],pn,vis[N];
vector<int> g[N];
map<int,double> dp[N];

int dfs(int u){
	int ans=1;
	vis[u]=1;
	for(int i=0;i<g[u].size();i++){
		int v=g[u][i];
		if(!vis[v]) ans+=dfs(v);
	}
	
	return ans;
}

double DP(int u,int s){
	if(dp[u].count(s)) return dp[u][s];
	int have=0,i;
	for(i=0;i<pn;i++){
		if(s&(1<<i))
			have+=p[i];
	}
	if(s==(1<<pn)-1) return dp[u][s]=0;
	dp[u][s]=(n-1)*1.0/(n-have);
	for(i=0;i<pn;i++){
		if(s&(1<<i)) continue;
		dp[u][s]+=DP(i,s|(1<<i))*p[i]/(n-have);
	}
	return dp[u][s];
}

int main(){
	int cas=0;
	scanf("%d",&t);
	while(t--){
		pn=0;
		memset(vis,0,sizeof(vis));
		scanf("%d%d",&n,&m);
		for(int i=1;i<=n;i++) g[i].clear();
		int u,v;
		while(m--){
			scanf("%d%d",&u,&v);
			g[u].push_back(v);
			g[v].push_back(u);
		}
		for(int i=1;i<=n;i++){
			if(vis[i]) continue;
			p[pn++]=dfs(i);
		}
		printf("Case %d: %.6lf\n",++cas,DP(0,1));
	}
	return 0;
}

