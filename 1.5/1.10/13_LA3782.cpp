#include<cstdio>
#include<string>
#include<cstring>
#include<algorithm>
using namespace std;
int cnum[10]={6,2,5,5,4,5,6,3,7,6};
int dp[105][3010];
int pre[105][3010];
int n,m;
int max_len;

int main(){
	while(scanf("%d%d",&n,&m)!=EOF){
		max_len=0;
		memset(dp,-1,sizeof(dp));
		memset(pre,-1,sizeof(pre));
		dp[0][0]=0;
		for(int i=1;i<10;i++)
			dp[cnum[i]][i%m]=1;
		
		for(int i=1;i<n;i++)
			for(int j=0;j<m;j++) if(dp[i][j]!=-1){
				int newi,newj;
				for(int k=0;k<10;k++){
					newi=i+cnum[k];
					if(newi>n) continue;
					newj=(j*10+k)%m;
					if(dp[newi][newj]==-1){
						dp[newi][newj]=dp[i][j]+1;
						max_len=max(max_len,dp[i][j]+1);
					}else if(dp[i][j]+1>=dp[newi][newj]){
						dp[newi][newj]=dp[i][j]+1;
						max_len=max(max_len,dp[i][j]+1);
					}
				}
			}
		for(int i=n-1;i>=0;i--)
			for(int j=0;j<m;j++) if(dp[i][j]!=-1){
				int newi,newj;
				for(int k=9;k>=0;k--){
					newi=i+cnum[k];
					newj=(j*10+k)%m;
					if(newi>n) continue;
					if(pre[newi][newj]!=-1||(dp[newi][newj]==max_len&&newj==0)){
						pre[i][j]=k;
						break;
					}
				}
			}
		
		int _i=0,_j=0;
		int ans=0;
		while(pre[_i][_j]!=-1){
			int k=pre[_i][_j];
			ans=ans*10+k;
			_i=_i+cnum[k];
			_j=(_j*10+k)%m;
		}
			
		printf("%d\n",ans);	
		
	}
	return 0;
}
/*

#include<algorithm>
#include<cstdio>
#include<cstring>
using namespace std;
#define maxn 110
#define maxm 3010
int dp[maxn][maxm], path[maxn][maxm], n, m, MAX, mark = 1;	
int num[10] = {6,2,5,5,4,5,6,3,7,6};
 
void init() {
	scanf("%d",&m);
	memset(dp,-1,sizeof(dp));
	dp[0][0] = 0, MAX = 0;
}
 
void solve() {
	for(int i = 0; i < n; i++)
		for(int j = 0; j < m; j++)
			if(dp[i][j] >= 0)
				for(int k = 9; k >= 0; k--) 
					if(num[k] + i <= n) {
						int newi = i + num[k], newj = (j * 10 + k) % m;
						if(dp[i][j] + 1 > dp[newi][newj]) {
							dp[newi][newj] = dp[i][j] + 1;
							if(dp[newi][newj] > MAX && newj == 0) 
								MAX = dp[newi][newj];
						}	
					}
}
 
void find_path() {
 
	memset(path,-1,sizeof(path));
	for(int i = n; i >= 0; i--)
		for(int j = 0; j < m; j++)
			if(dp[i][j] >= 0) {
				if(dp[i][j] == MAX && j == 0) {
					path[i][j] = 10;
					continue;
				}
				for(int k = 9; k >= 0; k--) 
					if(i + num[k] <= n) {
						int newi = i + num[k], newj = (j * 10 + k) % m;
						if(dp[newi][newj] == dp[i][j] + 1 && path[newi][newj] >= 0) {
							path[i][j] = k;
							break;
						}
					}
			}
}
 
void print() {
 
	printf("Case %d: ", mark++);
	int i, j, k, l;
 
	if(MAX > 0) {
		i = 0, j = 0;
		while(path[i][j] != 10) {
			k = i + num[path[i][j]];
			l = (j * 10 + path[i][j]) % m;
			printf("%d",path[i][j]);
			i = k, j = l;	
		}
		printf("\n");	
	}
	else if(n >= num[0])
		printf("0\n");
	else
		printf("-1\n");
}
 
int main() {
	while(scanf("%d", &n) == 1 && n) {
		init();
		solve();
		find_path();
		print();
	}
	return 0;
}
————————————————
版权声明：本文为CSDN博主「暗金色」的原创文章，遵循CC 4.0 BY-SA版权协议，转载请附上原文出处链接及本声明。
原文链接：https://blog.csdn.net/L123012013048/article/details/44179837

*/
