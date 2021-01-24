#include<cstdio>
#include<map>
using namespace std;

double c;
int m,n,k;
int S[10],K[10];
double P[10][105];
char name[10][105];

const long long conv[]={1,9,81,729,6561,59049,531441,4782969};
map<long long,int> mp;
struct node{
	int k;
	int a[10];
	int anxt[10];
	int dnxt[10];
};
node nodes[13000];
int tjs;

int dfs(long long t){
	if(mp.count(t)) return mp[t];
	mp[t]=tjs++;
	long long _t=t;int _tjs=tjs-1;
	
	nodes[_tjs].k=0;
	for(int i=0;i<8;i++){
		nodes[_tjs].a[i]=_t%9;
		nodes[_tjs].k+=nodes[_tjs].a[i];
		_t/=9;
	}
	for(int i=0;i<8;i++){
		if(nodes[_tjs].a[i]) 
			nodes[_tjs].dnxt[i]=dfs(t-conv[i]);
		else
			nodes[_tjs].dnxt[i]=-1;
		
		if(nodes[_tjs].k<8&&nodes[_tjs].a[i]<8)
			nodes[_tjs].anxt[i]=dfs(t+conv[i]);
		else
			nodes[_tjs].anxt[i]=-1;
	}
	
	return _tjs;
}

int main(){
	mp.clear();
	tjs=0;
	dfs(0LL);
	
	while(scanf("%lf%d%d%d",&c,&m,&n,&k)==4){
		for(int i=0;i<n;i++){
			scanf("%s%d%d",name[i],&S[i],&K[i]);
			for(int j=0;j<m;j++)
				scanf("%lf",&P[i][j]);
		}
		
	}
	return 0;
}
