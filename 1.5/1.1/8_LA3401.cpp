/*
#include<cstdio>
using namespace std;
int v[6];
//          上 4 下5 后2 
//            3   0  1 
void init(){
	for(int i=0;i<6;i++)
		v[i]=i;
}

void P(){
	printf("{");
	for(int i=0;i<5;i++)
		printf("%d,",v[i]);
	printf("%d",v[5]);
	printf("},\n");
}

// 向前翻转 
void A(){
	int t[6];
	t[0]=v[4];t[1]=v[1];t[2]=v[5];
	t[3]=v[3];t[4]=v[2];t[5]=v[0];	
	for(int i=0;i<6;i++)
		v[i]=t[i];
	
}

// 向左翻转 
void B(){
	int t[6];
	t[0]=v[0];t[1]=v[5];t[2]=v[2];
	t[3]=v[4];t[4]=v[1];t[5]=v[3];
	for(int i=0;i<6;i++)
		v[i]=t[i]; 
}
void show(){
	P();
	B();P();
	B();P();
	B();P();
	//printf("\n");	
}
int main(){
	
	//0面 
		init();
		show(); 		
	//1面
		init();
		B();A();
		show();
	//2面
		init();
		A();A();
		show();
	//3面 
		init();
		B();B();B();A();
		show();
	//4面
		init();
		A();
		show();
	//5面
		init();
		A();A();A();
		show(); 		
	return 0;
}
*/
#include<cstdio>
#include<string>
#include<vector>
#include<cstring>
using namespace std;
int dice24[24][6]={
{0,1,2,3,4,5},{0,5,2,4,1,3},{0,3,2,1,5,4},{0,4,2,5,3,1},
{1,5,3,4,2,0},{1,0,3,2,5,4},{1,4,3,5,0,2},{1,2,3,0,4,5},
{2,1,0,3,5,4},{2,4,0,5,1,3},{2,3,0,1,4,5},{2,5,0,4,3,1},
{3,4,1,5,2,0},{3,0,1,2,4,5},{3,5,1,4,0,2},{3,2,1,0,5,4},
{4,1,5,3,2,0},{4,0,5,2,1,3},{4,3,5,1,0,2},{4,2,5,0,3,1},
{5,1,4,3,0,2},{5,2,4,0,1,3},{5,3,4,1,2,0},{5,0,4,2,3,1}};

int n;
int dice[4][6],ans;
vector<string> names;

int ID(const char* name){
	string s(name);
	for(int i=0;i<names.size();i++)
		if(names[i]==s) return i;
	names.push_back(s);
	return names.size()-1;
}
int r[4],color[4][6];

void check(){
	for(int i=0;i<n;i++)
		for(int j=0;j<6;j++) color[i][j]=dice[i][dice24[r[i]][j]];
	
	int tot=0;
	for(int j=0;j<6;j++){
		int cnt[24];
		memset(cnt,0,sizeof(cnt));
		int maxface=0;
		for(int i=0;i<n;i++)
			maxface=max(maxface,++cnt[color[i][j]]);
		tot+=n-maxface;
	}
	ans=min(ans,tot);
}

void dfs(int d){
	if(d==n) check();
	else for(int i=0;i<24;i++){
		r[d]=i;
		dfs(d+1);
	}
}
int main(){
	while(scanf("%d",&n)==1&&n){
		names.clear();
		for(int i=0;i<n;i++)
			for(int j=0;j<6;j++){
				char name[30];
				scanf("%s",name);
				dice[i][j]=ID(name);
			}
			ans=n*6;
			r[0]=0;
			dfs(1);
			printf("%d\n",ans);
	}
	return 0;
}




