/*
#include<cstdio>
#include<cstring>
#include<cmath>
#include<algorithm>
using namespace std;
const int maxn=4000+10;
int n,m;
int A[maxn],B[maxn];
int dp[maxn][maxn];

int dis(int x,int y){
	return abs(A[y]-B[x]);
}

int main(){
	while(scanf("%d",&n)&&n){
		A[0]=0;
		for(int i=1;i<=n;i++)
			scanf("%d",&A[i]);
		scanf("%d",&m);
		B[0]=0;
		for(int i=1;i<=m;i++)
			scanf("%d",&B[i]);
		sort(A+1,A+n+1);
		sort(B+1,B+m+1);
		memset(dp,0x3f,sizeof(dp));
		dp[0][0]=0;
		for(int i=1;i<=m;i++){
			dp[i][i]=dp[i-1][i-1]+dis(i,i);
			for(int j=i+1;j<=n;j++){
				dp[i][j]=min(dp[i][j-1],dp[i-1][j-1])+dis(i,j);
			}
		}
		printf("%d\n",d[m][n]);
	}
	return 0;
}
*/

#include <math.h>
#include <vector>
#include <stdio.h>
#include <string.h>
#include <iostream>
#include <algorithm>
using namespace std;
const long long INF=0x3f3f3f3f;
struct node{
	int d,id,cp;
}a[4005],b[4005];
bool cmp1(node x,node y){
	return x.d<y.d;
}
bool cmp2(node x,node y){
	return x.id<y.id;
}

long long dp[4005];
int path[4005][4005];
void print(int x,int y){
	if(x)
		print(x-1,path[x][y]);
	a[x].cp=b[y].id;
}
 //dp[i][j]=min(dp[i-1][j],dp[i-1][j-1])+abs(a[i].d-b[j].d)
int main(){
	int n,m,i,j;
	while(scanf("%d",&n)!=EOF){
		for(i=0;i<n;i++){
			scanf("%d",&a[i].d);
			a[i].id=i;
		}
		scanf("%d",&m);
		for(i=0;i<m;i++){
			scanf("%d",&b[i].d);
			b[i].id=i;
		}
		sort(a,a+n,cmp1);
		sort(b,b+m,cmp1);
		memset(dp,INF,sizeof(dp));
		dp[0]=abs(a[0].d-b[0].d);
		for(i=1;i<n;i++){
			for(j=min(i,m-1);j>=0;j--){
				if(j>0&&dp[j-1]<dp[j]){
					path[i][j]=j-1;
					dp[j]=dp[j-1]+abs(a[i].d-b[j].d);
				}else{
					path[i][j]=j;
					dp[j]=dp[j]+abs(a[i].d-b[j].d);
				}
			}
		}
		printf("%lld\n",dp[m-1]);
		print(n-1,m-1);
		sort(a,a+n,cmp2);
		for(i=0;i<n;i++)
			printf("%d ",a[i].cp+1);
		printf("\n");
	}
}

