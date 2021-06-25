#include<bits/stdc++.h>
using namespace std;
struct edge{
	int u,v;
	int w;
	edge(int u,int v,int w):u(u),v(v),w(w){} 
};
vector<edge> e[2005];
int MaxD[2005];

int n,k;
void input(int p){
	n=p;
	char s[10];
	do{
		n=max(n,p);
		while(scanf("%s",s)==1){
			if(s[0]=='0') break;
			int pp=0;
			char c='k';
			int len=strlen(s);
			for(int i=0;i<len;i++){
				if(s[i]>='0'&&s[i]<='9'){
					pp*=10;
					pp+=(s[i]-'0');
				}else c=s[i];
			}
			n=max(n,pp);
			if(c=='k'){
				e[p].push_back(edge(p,pp,1));
				e[pp].push_back(edge(pp,p,1));
			}else if(c=='d'){
				e[p].push_back(edge(p,pp,0));
				e[pp].push_back(edge(pp,p,2));
			}else{
				e[p].push_back(edge(p,pp,2));
				e[pp].push_back(edge(pp,p,0));
			}
		}
		scanf("%d",&p);
	}while(p!=0);
}
void Pre_dfs(int pos){
	
}

int main(){
	int p;
	while(scanf("%d",&p)==1&&p){
		for(int i=1;i<=2000;i++)
			e[i].clear();
		input(p);
		memset(MaxD,-1,sizeof(MaxD));
		for(int i=1;i<=n;i++)
			Pre_dfs(i);
	}
}
