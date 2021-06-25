/*
#include<cstdio>
#include<algorithm>
using namespace std;
const int maxn=100+10;
const int INF=0x3f3f3f3f;
int n;
struct node{
	int h,w;
	node(){}
	node(int h,int w):h(h),w(w){}
	
	bool operator < (const node &rhs)const{
		return h>rhs.h;
	}
}books[maxn];

int h1,h2;
int w1,w2;
int ans,sum_w;
void dfs(int t){
	if(t==n){
		int tmp_h=h1+h2+books[0].h;
		int tmp_w=max(w1,max(w2,sum_w-w2-w1));
		ans=min(ans,tmp_h*tmp_w);
		return;
	}
	dfs(t+1);
	
	if(h1==0){
		h1=books[t].h;
		w1+=books[t].w;
		dfs(t+1);
		h1=0;
		w1-=books[t].w;
	}else{
		w1+=books[t].w;
		dfs(t+1);
		w1-=books[t].w;
	}
	
	if(h1==0) return;
	
	if(h2==0){
		h2=books[t].h;
		w2+=books[t].w;
		dfs(t+1);
		h2=0;
		w2-=books[t].w;
	}else{
		w2+=books[t].w;
		dfs(t+1);
		w2-=books[t].w;		
	}
	
}

int main(){
	while(scanf("%d",&n)!=EOF){
		sum_w=0;
		for(int i=0;i<n;i++){
			int h,w;
			scanf("%d%d",&h,&w);
			sum_w+=w;
			books[i]=node(h,w);
		}
		sort(books,books+n);
		h1=h2=w1=w2=0;
		ans=INF;
		dfs(1);
	}
	return 0;
}
*/

