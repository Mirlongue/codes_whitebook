/*
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
*/
#include<cstdio>
#include<algorithm>
using namespace std;
const int maxn=100000+10;

int x[maxn],y[maxn];
int total_dist[maxn],total_weight[maxn],dist2origin[maxn];
int q[maxn],d[maxn];

int func(int i){
	return d[i]-total_dist[i+1]+dist2origin[i+1];
}

int main(){
	int T,c,n,w,front,rear;
	scanf("%d",&T);
	while(T--){
		scanf("%d%d",&c,&n);
		total_dist[0]=total_weight[0]=x[0]=y[0]=0;
		for(int i=1;i<=n;i++){
			scanf("%d%d%d",&x[i],&y[i],&w);
			dist2origin[i]=abs(x[i])+abs(y[i]);
			total_dist[i]=total_dist[i-1]+abs(x[i]-x[i-1])+abs(y[i]-y[i-1]);
			total_weight[i]=total_weight[i-1]+w;
		}
		front=rear=1;
		for(int i=1;i<=n;i++){
			while(front<=rear&&total_weight[i]-total_weight[q[front]]>c)
				front++;
			d[i]=func(q[front])+total_dist[i]+dist2origin[i];
			while(front<=rear&&func(i)<=func(q[rear])) 
				rear--;
			q[++rear]=i;
		}
		printf("%d\n",d[n]);
		if(T>0)printf("\n");
	}
	return 0;
}































