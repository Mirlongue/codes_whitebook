#include<cstdio>
#include<algorithm>
#include<vector>
#include<cstring>
using namespace std;
vector<int> adj[1010]; 
int vis[1010][2],d[1010][2];
int n,m,res;

int dp(int u,int k,int f){
	if(vis[u][k]) return d[u][k];
	vis[u][k]=1;
	
	int ans;
	if(k) ans=2000;
	else ans=0;
	
	for(int i=0;i<adj[u].size();i++)if(adj[u][i]!=f){
		if(k) ans=ans+min(dp(adj[u][i],1,u),dp(adj[u][i],0,u)+1);
		else ans=ans+dp(adj[u][i],1,u)+1;
	}
	d[u][k]=ans;
	printf("(%d %d %d) %d\n",u,k,f,ans);
	return ans;
}

int main(){
	int T,a,b;
	scanf("%d",&T);
	while(T--){
		scanf("%d%d",&n,&m);
		for(int i=0;i<n;i++) adj[i].clear();
		memset(vis,0,sizeof(vis));
		for(int i=0;i<m;i++){
			scanf("%d%d",&a,&b);
			adj[a].push_back(b);
			adj[b].push_back(a);
		}
	/*	
		for(int i=0;i<n;i++){
			printf("%d:",i);
			for(int j=0;j<adj[i].size();j++){
				printf("%d ",adj[i][j]);
			}
			printf("\n");
		}
	*/	
		int res=0;
		for(int i=0;i<n;i++){
			if(!vis[i][0]&&!vis[i][1])
				res=res+min(dp(0,0,-1),dp(0,1,-1));
		}
		printf("%d %d %d \n",res/2000,m-res%2000,res%2000);
	}
	return 0;
}
