#include<cstdio>
using namespace std;

#define N 505
#define ll long long
ll dp[2][N][N];
int fa[N],n,m;

int first[N],k;
struct Edge{
	int y,nxt,d;
	Edge(){}
	Edge(int y,int nxt,int d):y(y),nxt(nxt),d(d){}
}e[N<<1];
void add_edge(int x,int y,int d){
	e[k]=Edge(y,first[x],d);
	first[x]=k++;
}
/*
int dfs(int u){
	dp[0][u][1]=0;
	int num1=1;
	for(int i=first[u];i!=-1;i=e[i].nxt){
		int v=e[i].y;
		int num2=dfs(v);
		for(int j=num1;j>=1;j--){
			if(d[0][u][j]!=-1){
				for(int k=1;k<=num2;k++){
					if(d[0][v][k]!=-1){
						if(d[0][u][j+k]==-1||d[0][u][j+k]>d[0][u][j]+d[0][u][j+k]+e[i].d*2)
							d[0][u][j+k]=d[0][u][j]+d[0][u][j+k]+e[i].d*2;
						if(d[1][u][j+k]==-1||d[1][u][j+k]>d[0][u][j]+d[0][u][j+k]+e[i].d)
							d[1][u][j+k]=d[0][u][j]+d[0][u][j+k]+e[i].d;					
					}
					if(d[1][v][k]!=-1){
						if(d[1][u][j+k]==-1||d[1][u][j+k]>d[0][u][j]+d[1][v][k]+e[i].d)
							d[1][u][j+k]=d[0][u][j]+d[1][v][k]+e[i].d;
					}
				}	
			}
			if(d[1][u][j]!=-1){
				for(int k=1;k<=num2;k++){
					if(d[0][v][k]!=-1){
						if(d[1][u][j+k]==-1||d[1][u][j+k]>d[1][u][j]+d[0][v][k]+2*e[i].d)
							d[1][u][j+k]=d[1][u][j]+d[0][v][k]+2*e[i].d;
					}
				}
			}
		}
		num1+=num2;
	}
	return num1;
}
*/

void dfs(int u){
	dp[0][u][1]=0;
	for(int i=first[u];i!=-1;i=e[i].nxt){
		int v=e[i].y;
		dfs(v);
		for(int k=n;k>=1;k--){
			if(d[0][u][k]<0)continue;
			for(int j=1;j<n;j++){
				if(dp[0][v][j]<0) continue;
				if(dp[0][u][k+j]<0||dp[0][u][k+j]>dp[0][v][j]+dp[0][u][k]+2*e[i].d)
					dp[0][u][k+j]=dp[0][v][j]+dp[0][u][k]+2*e[i].d;
				if(dp[1][u][k+j]<0||dp[1][u][k+j]>dp[0][v][j]+dp[0][u][k]+e[i].d)
					dp[1][u][k+j]=dp[0][v][j]+dp[0][u][k]+e[i].d;
				if(dp[1][v][j]<0) continue;
				if(dp[1][u][k+j]<0||dp[1][u][k+j]>dp[1][v][j]+dp[0][u][k]+e[i].d)
					dp[1][u][k+j]=dp[1][v][j]+dp[0][u][k]+e[i].d;	
			}
			if(dp[1][u][k]<0) continue;
			for(int j=1;j<=n;j++){
				if(dp[0][v][j]<0) continue;
				if(dp[1][u][k+j]<0||dp[1][u][k+j]>dp[0][v][j]+dp[1][u][k]+2*e[i].d)
					dp[1][u][k+j]=dp[0][v][j]+dp[1][u][k]+2*e[i].d;
			}
		}
	}
}

int main(){
	int cas=0;
	while(scanf("%d",&n),n){
		printf("Case %d:\n",++cas);
		memset(first,-1,sizeof(first));
		k=0;
		for(int i=0;i<=n;i++) fa[i]=i;
		for(int i=1;i<n;i++){
			int u,v,d;
			scanf("%d%d%d",&u,&v,&d);
			u++,v++;
			add_edge(v,u,d);
			fa[u]=v;
		}
		int st;
		for(int i=1;i<=n;i++)
			if(fa[i]==i) st=i;
		
		memset(dp,-1,sizeof(dp));
		dfs(st);
		scanf("%d",&m);
		for(int i=0;i<m;i++){
			int x;
			scanf("%d",&x);
			int ret=0;
			for(int t=1;t<=n;t++){
				if((dp[0][st][t]<=x&&dp[0][st][t]>=0)||(dp[1][st][t]<=x&&dp[1][st][t]>=0))
					ret=max(ret,t);
			}
			printf("%d\n",ret);
		}
		
	}
	return 0;
}
