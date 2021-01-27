#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
const int maxn=100000+10;
int c,n;
int x[maxn],y[maxn],w[maxn];
int d[maxn];
int table[maxn];
int head,tail;
int sum;

int dist(int a,int b){
	return abs(x[a]-x[b])+abs(y[a]-y[b]);
}

int main(){
	
	while(scanf("%d",&c)!=EOF){
		scanf("%d",&n);
		x[0]=y[0]=0;
		for(int i=1;i<=n;i++)
			scanf("%d%d%d",&x[i],&y[i],&w[i]);
		
		memset(table,0,sizeof(table));
		sum=0;
		head=1;
		memset(d,0x3f,sizeof(d));
		d[0]=0;
		for(int i=1;i<=n;i++){
			
			sum+=w[i];
			while(sum>c){
				sum=sum-w[head];
				head++;
			}
			for(int j=head;j<i;j++){
				table[j]+=dist(i-1,i);
			}
			for(int j=head;j<=i;j++)
				d[i]=min(d[i],table[j]+dist(0,j)+d[j-1]);
			
			d[i]=d[i]+dist(0,i);
//			printf("%d ",sum);
//			printf("%d\n",d[i]);
		}
		printf("%d\n",d[n]); 
	}
	return 0;
}
