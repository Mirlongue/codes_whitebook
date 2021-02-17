#include<cstdio>
#include<vector>
#include<cstring>
#include<algorithm>
using namespace std;
const int maxn=1000+10;
vector<int> gr[maxn],nodes[maxn];
int n,s,k,fa[maxn];
bool covered[maxn];
void dfs(int u,int f,int d){
	fa[u]=f;
	int nc=gr[u].size();
	if(nc==1&&d>k) nodes[d].push_back(u);
	for(int i=0;i<nc;i++){
		int v=gr[u][i];
		if(v!=f) dfs(v,u,d+1);
	}
}
void dfs2(int u,int f,int d){
	covered[u]=true;
	int nc=gr[u].size();
	for(int i=0;i<nc;i++){
		int v=gr[u][i];
		if(v!=f&&d<k) dfs2(v,u,d+1);
	}
}
int solve(){
	int ans=0;
	memset(covered,0,sizeof(covered));
	for(int d=n-1;d>k;d--){
		for(int i=0;i<nodes[d].size();i++){
			int u=nodes[d][i];
			if(covered[u]) continue;
			
			int v=u;
			for(int j=0;j<k;j++) v=fa[v];
			dfs2(v,-1,0);
			ans++;
		}
		return ans;
	}
}

int main(){
	int T;
	scanf("%d",&T);
	while(T--){
		scanf("%d%d%d",&n,&s,&k);
		for(int i=1;i<=n;i++) gr[i].clear(),nodes[i].clear();
		for(int i=0;i<n-1;i++){
			int a,b;
			scanf("%d%d",&a,&b);
			gr[a].push_back(b);
			gr[b].push_back(a);
		}
		dfs(s,-1,0);
		printf("%d\n",solve());
	}
	return 0;
}
