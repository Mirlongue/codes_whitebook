#include<cstdio>
#include<map>
#include<algorithm>
#include<cstring>
using namespace std;
map<int,int> Map;

const int maxn=250*250+10;
const int INF=0x3f3f3f3f;
int n,p,q;
int s[maxn];
int dp[maxn];

int main(){
	int T;
	scanf("%d",&T);
	for(int kase=1;kase<=T;kase++){
		Map.clear();
		scanf("%d%d%d",&n,&p,&q);
		for(int i=0;i<p;i++){
			int tmp;
			scanf("%d",&tmp);
			Map[tmp]=i;
		}
		int res=0;
		for(int i=0;i<q;i++){
			int tmp;
			scanf("%d",&tmp);
			if(Map.count(tmp)){
				s[res++]=Map[tmp];
			}
		}
		for(int i=0;i<res;i++) printf("%d ",s[i]);
		printf("\n");
		
		
		
		memset(dp,0x3f,sizeof(dp));
		dp[0]=s[0];
		int pos=1;
		for(int i=1;i<res;i++){
			if(s[i]>dp[pos-1]) dp[pos++]=s[i];
			else{
				int tmp=lower_bound(dp,dp+pos,s[i])-dp;
				dp[tmp]=s[i];
			}
		}
		printf("%d\n",pos);
		
	}
	return 0;
}
