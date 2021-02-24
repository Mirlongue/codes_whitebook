#include<cstdio>
#include<cstring>
#include<queue>
#include<map>
#define eps 1e-8
using namespace std;

double c;
int m,n,k;
int S[10],K[10];
double P[10][105];
char name[10][105];

const long long conv[]={1,9,81,729,6561,59049,531441,4782969};
map<long long,int> mp;
int tjs;
struct vnode{
	int k;
	int a[10];
	int anxt[10];
	int dnxt[10];
}V[13000];

int dfs(long long bitm){
	if(mp.count(bitm)) 
	return mp[bitm];
	mp[bitm]=tjs;
	
	int top=tjs++;long long tmp=bitm;
	V[top].k=0;
	for(int i=0;i<8;i++){
		V[top].a[i]=tmp%9;
		V[top].k+=V[top].a[i];
		tmp/=9;
	}
	
	for(int i=0;i<8;i++){
		if(V[top].k<8) 
			V[top].anxt[i]=dfs(bitm+conv[i]);
		else
			V[top].anxt[i]=-1;
		
		if(V[top].a[i])
			V[top].dnxt[i]=dfs(bitm-conv[i]);
		else
			V[top].dnxt[i]=-1;
	}
	/*
	printf("%d: %d ",top,bitm);
	for(int i=0;i<8;i++){
		printf("%d",V[top].a[i]);
	}
	printf("\n");
	*/
	return top;
}

void init(){
	mp.clear();
	tjs=0;
	dfs(0LL);
}

struct node{
	int i,j;
	node(){}
	node(int i,int j):i(i),j(j){}
};
int pre[105][13000];
int vis[13000];
double d[2][13000];

void bfs(){
	queue<node> q;
	q.push(node(0,0));
	d[0][0]=c;
	memset(vis,0,sizeof(vis));
	
	int tag=0;
	
	while(!q.empty()){
		node x=q.front();
		q.pop();
		int b1=x.i,b2=x.j;
		if(b1==m) continue;
		if(b1%2!=tag){
			memset(vis,0,sizeof(vis));
			tag=tag^1;
		}
		
		if(!vis[b2]){
			q.push(node(b1+1,b2));
			d[tag^1][b2]=d[tag][b2];
			vis[b2]=1;
			pre[b1+1][b2]=b2;
		}else 
			if(d[tag][b2]>d[tag^1][b2]){
				d[tag^1][b2]=d[tag][b2];
				pre[b1+1][b2]=b2;
			}
		
		
		for(int i=0;i<8;i++){
			double w=P[i][b1]*S[i];
			if(V[b2].k<k&&V[b2].a[i]<K[i]&&d[tag][b2]-w>-eps){
				if(!vis[V[b2].anxt[i]]){
					q.push(node(b1+1,V[b2].anxt[i]));
					d[tag^1][V[b2].anxt[i]]=d[tag][b2]-w;
					vis[V[b2].anxt[i]]=1;
					pre[b1+1][V[b2].anxt[i]]=b2;
				}else 
					if(d[tag][b2]-w>d[tag^1][V[b2].anxt[i]]){
						d[tag^1][V[b2].anxt[i]]=d[tag][b2]-w;
						pre[b1+1][V[b2].anxt[i]]=b2;
					}
			}
			if(V[b2].a[i]){
				if(!vis[V[b2].dnxt[i]]){
					q.push(node(b1+1,V[b2].dnxt[i]));
					d[tag^1][V[b2].dnxt[i]]=d[tag][b2]+w;
					vis[V[b2].dnxt[i]]=1;
					pre[b1+1][V[b2].dnxt[i]]=b2;
				}else
					if(d[tag][b2]+w>d[tag^1][V[b2].dnxt[i]]){
						d[tag^1][V[b2].dnxt[i]]=d[tag][b2]+w;
						pre[b1+1][V[b2].dnxt[i]]=b2;
					}
			}
		}
	}
	
	
}

void print_dfs(int d,int x){
	if(d==0) return;
	int tmp=pre[d][x];
	print_dfs(d-1,tmp);
	int i;
	for(i=0;i<n;i++){
		if(V[tmp].anxt[i]==x){
			printf("BUY %s\n",name[i]);
			break;
		}
		if(V[x].dnxt[i]==x){
			printf("SELL %s\n",name[i]);
			break;
		}
	}
	if(i==n) printf("HOLD\n");
}

int main(){
	init();
	while(scanf("%lf%d%d%d",&c,&m,&n,&k)==4){
		for(int i=0;i<n;i++){
			scanf("%s%d%d",name[i],&S[i],&K[i]);
			for(int j=0;j<m;j++)
				scanf("%lf",&P[i][j]);
		}
		bfs();
		print_dfs(m,0);
		
		printf("%d\n",d[m%2][0]);
		
	}
	return 0;
}
/*
#include<bits/stdc++.h>
#define eps 1e-8
using namespace std;
 
map<long long,int> st;
 
const long long nie[9]={1,9,81,729,6561,59049,531441,4782969,43046721};
 
//预处理 
 
struct vnode
{
	int k;
	int a[10];
	int dnxt[10];
	int unxt[10];
};
 
vnode V[13000];
int top;
 
int vdfs(long long bitm)
{
	if(st.find(bitm)!=st.end())return st[bitm];
	st[bitm]=top;
	int pos=top;
	top++;
	long long p=bitm;
	V[pos].k=0;
	for(int i=0;i<8;i++)
	{
		V[pos].a[i]=p%9;
		V[pos].k+=V[pos].a[i];
		p/=9;
	}
	for(int i=0;i<8;i++)
	{
		if(V[pos].a[i]>0)V[pos].dnxt[i]=vdfs(bitm-nie[i]);
		else V[pos].dnxt[i]=-1;
		if(V[pos].k<8&&V[pos].a[i]<8)V[pos].unxt[i]=vdfs(bitm+nie[i]);
		else V[pos].unxt[i]=-1;
	}
	return pos;
}
 
void init()
{
	st.clear();
	top=0;
	vdfs(0LL);
}
 
//预处理结束 
 
bool vis[105][13000];
double dp[105][13000];
int lst[105][13000];
 
 
double c;
int m,n,k;
int S[10],K[10];
double P[10][105];
char name[10][105];
 
struct node
{
	int i,j;
	node(int ii=0,int jj=0):i(ii),j(jj){}
};
 
void bfs()
{
	memset(vis,0,sizeof(vis));
	queue<node> q;
	q.push(node(0,0));
	dp[0][0]=c;
	vis[0][0]=true;
	while(!q.empty())
	{
		node p=q.front();
		q.pop();
		if(p.i==m)continue;
		int &b1=p.i,&b2=p.j;
		if(V[b2].k<k)
		{
			for(int i=0;i<n;i++)
			{
				double w=P[i][b1]*S[i];
				if(V[b2].a[i]<K[i]&&(dp[b1][b2]-w>-eps))
				{
					if(dp[b1+1][V[b2].unxt[i]]<=dp[b1][b2]-w)
					{
						dp[b1+1][V[b2].unxt[i]]=dp[b1][b2]-w;
						lst[b1+1][V[b2].unxt[i]]=b2;
					}
					if(!vis[b1+1][V[b2].unxt[i]])
					{
						q.push(node(b1+1,V[b2].unxt[i]));
						vis[b1+1][V[b2].unxt[i]]=true;
					}
				}
			}
		}
		for(int i=0;i<n;i++)
		{
			double w=P[i][b1]*S[i];
			if(V[b2].a[i]>0)
			{
				if(dp[b1+1][V[b2].dnxt[i]]<=dp[b1][b2]+w)
				{
					dp[b1+1][V[b2].dnxt[i]]=dp[b1][b2]+w;
					lst[b1+1][V[b2].dnxt[i]]=b2;
				}
				if(!vis[b1+1][V[b2].dnxt[i]])
				{
					q.push(node(b1+1,V[b2].dnxt[i]));
					vis[b1+1][V[b2].dnxt[i]]=true;
				}
			}
		}
		if(dp[p.i+1][p.j]<=dp[p.i][p.j])
		{
			dp[p.i+1][p.j]=dp[p.i][p.j];
			lst[p.i+1][p.j]=p.j;
		}
		if(!vis[p.i+1][p.j])
		{
			q.push(node(p.i+1,p.j));
			vis[p.i+1][p.j]=true;
		}
	}
}
 
void print_ans()
{
	printf("%.2lf\n",dp[m][0]);
	vector<int> ans;
	int p=0;
	for(int i=m;i>=0;i--)
	{
		ans.push_back(p);
		p=lst[i][p];
	}
	reverse(ans.begin(),ans.end());
	for(int i=1;i<ans.size();i++)
	{
		int x=ans[i-1],y=ans[i],j;
		for(j=0;j<n;j++)
		{
			if(V[x].unxt[j]==y)
			{
				printf("BUY %s\n",name[j]);
				break;
			}
			if(V[x].dnxt[j]==y)
			{
				printf("SELL %s\n",name[j]);
				break;
			}
		}
		if(j==n)printf("HOLD\n");
	}
}
 
int main()
{
//	freopen("1.txt","r",stdin);
//	freopen("2.txt","w",stdout);
	init();
	bool flag=false;
	while(scanf("%lf%d%d%d",&c,&m,&n,&k)==4)
	{
		if(!flag)flag=true;
		else printf("\n");
		memset(dp,0,sizeof(dp));
		for(int i=0;i<n;i++)
		{
			scanf("%s%d%d",name[i],&S[i],&K[i]);
			for(int j=0;j<m;j++)
				scanf("%lf",&P[i][j]);
		}
		bfs();
		print_ans();
	}
}
*/
