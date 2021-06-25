#include<cstdio>
using namespace std;
int n,d,k;
int bit[70];

int get_max(){
	int later[70];
	memset(later,0,sizeof(later));
	int ans=0;
	for(int i=0;i<n;i++){
		if(!bit[i]) 
			later[i+k-1]++;
		else 
			ans=(ans<<1)+1;
		if(later[i])
			ans=ans<<1;
	}
	return ans;
}

int get_min(){
	int later[70];
	memset(later,0,sizeof(later));
	int ans=0;
	for(int i=0;i<n;i++){
		if(bit[i]) 
			later[i+k-1]++;
		else 
			ans=(ans<<1);
		if(later[i])
			ans=(ans<<1)+1;
	}
	return ans;
}

int dp[70][70];
int f0[70],f1[70];
int n0,n1;
int get_num(){
	n0=n1=0;
	
	for(int i=0;i<n;i++){
		if(bit[i])
			f1[++n1]=i;
		else
			f0[++n0]=i;
	}
	dp[0][0]=1;
	
	for(int i=0;i<=n0;i++)
		for(int j=0;j<=n1;j++){
			if(i&& f0[i]+k-1<=f1[j+1]){
				dp[i][j]+=dp[i-1][j];
			}
			if(j&&f1[j]+k-1<=f0[i+1]){
				dp[i][j]+=dp[i][j-1];
			}
			
		}
	
	return dp[n0][n1];
}

int main(){
	while(scanf("%d%d%d",&n,&d,&k)!=EOF){
		for(int i=n-1;i>=0;i--){
			if(k&(1<<n))
				bit[n-1-i]=1;
			else
				bit[n-1-i]=0;
		}
		
		
	}
	
	return 0;
}
