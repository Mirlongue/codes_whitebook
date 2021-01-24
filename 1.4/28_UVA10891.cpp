/*
#include<cstdio>
#include<algorithm>
#include<cstring>
using namespace std;
const int maxn=100+10;
const int INF=0x3f3f3f3f;
int n;
int s[maxn];
int dp[maxn][maxn];
int flag[maxn][maxn];


void dfs(int a,int b){
	if(flag[a][b]) return;
	flag[a][b]=1;
	
	if(a==b){
		dp[a][b]=0;
		return;
	}
	if(a==b-1){
		if(a)dp[a][b]=s[b-1]-s[a-1];
		else dp[a][b]=s[b-1];
		return;
	}
	int tmp=-INF;
	int sum;
	if(a) sum=s[b-1]-s[a-1];
	else sum=s[b-1];
	for(int i=a+1;i<=b;i++){
		dfs(i,b);
		tmp=max(tmp,sum-dp[i][b]);
	}
	
	for(int i=b-1;i>a;i--){
		dfs(a,i);
		tmp=max(tmp,sum-dp[a][i]);
	}
	dp[a][b]=tmp;
}

int main(){
	while(scanf("%d",&n)&&n){
		for(int i=0;i<n;i++){
			int tmp;
			scanf("%d",&tmp);
			if(i) s[i]=s[i-1]+tmp;
			else s[i]=tmp;
		}
		
		memset(flag,0,sizeof(flag));
		dfs(0,n);
		printf("%d\n",2*dp[0][n]-s[n-1]);
	}
	

	
	
	return 0;
}
*/

#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
const int maxn=100+10;
int S[maxn];
int vis[maxn][maxn],d[maxn][maxn];
int f[maxn][maxn],g[maxn][maxn];
int n;

int dp(int i,int j){
	if(vis[i][j]) return d[i][j];
	vis[i][j]=1;
	int m=0;
	for(int k=i+1;k<=j;k++) m=min(m,dp(k,j));
	for(int k=j-1;k>=i;k--) m=min(m,dp(i,k));
	return d[i][j]=S[j]-S[i-1]-m;
}

int main(){
	while(scanf("%d",&n)&&n){
		S[0]=0;
		for(int i=1;i<=n;i++){
			scanf("%d",&S[i]);
			S[i]=S[i]+S[i-1];
		}
		/*
		memset(vis,0,sizeof(vis));
		printf("%d\n",2*dp(1,n)-S[n]);
		*/
		for(int i=1;i<=n;i++) d[i][i]=f[i][i]=g[i][i]=S[i]-S[i-1];
		for(int l=1;l<n;l++)
			for(int i=1;i+l<=n;i++){
				int m=0;
				m=min(m,f[i+1][i+l]);
				m=min(m,g[i][i+l-1]);
				d[i][i+l]=S[i+l]-S[i-1]-m;
				f[i][i+l]=min(f[i+1][i+l],d[i][i+l]);
				g[i][i+l]=min(g[i][i+l-1],d[i][i+l]);
			}
		printf("%d\n",2*d[1][n]-S[n]);
	}
	return 0;
}


