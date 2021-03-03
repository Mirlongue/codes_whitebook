#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
const int INF=0x3f3f3f3f;
const int maxn=111;
int book[maxn];
int d[2][maxn][1<<8][11];
/*
int set[maxn];
int typ_n;
int ID(int x){
	for(int i=0;i<typ_n;i++)
		if(set[i]==x) return i;
	set[typ_n++]=x;
	return typ_n-1;
}
*/

int bitcount(int x){
	return x==0?0:bitcount(x>>1)+x&1;
}

int main(){
	int n,k;
	while(~scanf("%d%d",&n,&k)&&(n+k)){
/*		
		typ_n=0;
		for(int i=0;i<n;i++){
			int x;
			scanf("%d",&x);
			book[i]=ID(x);
		}
		
*/	
		int S=0;
		int h_max=0;
		for(int i=1;i<=n;i++){
			scanf("%d",&book[i]);
			book[i]-=25;
			S=S|(1<<book[i]);
			h_max=max(h_max,book[i]);
		}
		h_max++;
		memset(d[0],0x3f,sizeof(d[0]));
		d[0][0][(1<<book[1])][book[1]]=1;
		d[0][1][0][h_max]=0;
		int cur=0,pre=0;
		for(int i=1;i<n;i++){
			cur=pre^1;
			memset(d[cur],0x3f,sizeof(d[cur]));
			for(int j=0;j<=k;j++){
				for(int s=0;s<=S;s++)
					for(int last=0;last<=h_max;last++){
						if(d[pre][j][s][last]==INF)continue;
						d[cur][j][s|1<<book[i+1]][book[i+1]]=min(d[cur][j][s|1<<book[i+1]][book[i+1]],d[pre][j][s][last]+(book[i+1]==last?0:1));
						d[cur][j+1][s][last]=min(d[cur][j+1][s][last],d[pre][j][s][last]);
						
					}
			}
			pre=cur;
		}	
		int ans=INF;
		for(int j=0;j<=k;j++)
			for(int s=0;s<=S;s++)
				for(int last=0;last<h_max;last++){
					 if(d[cur][j][s][last]==INF)continue;
					 int take=S^s;
					 ans=min(ans,d[cur][j][s][last]+bitcount(take));
				}
		printf("Case %d: %d\n\n",++cas,ans);
	}
	return 0;
}
