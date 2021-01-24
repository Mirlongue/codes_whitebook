#include<cstdio>
using namespace std;

map<long long,int> st;

const long long nie[9]={1,9,81,729,6561,59049,531441,4782969,43046721};
struct vnode{
	int k;
	int a[10];
	int dnxt[10];
	int unxt[10];
};

vnode V[13000];
int top;

int vdfs(long long bitm){
	if(st.find(bitm)!=st.end()) return st[bitm];
	st[bitm]=top;
	int pos=top;
	top++;
	long long p=bitm;
	V[pos].k=0;
	for(int i=0;i<8;i++){
		V[pos].a[i]=p%9;
		V[pos].k+=V[pos].a[i];
		p/=9;
	}
	
	for(int i=0;i<8;i+){
		if(V[pos].a[i]>0) V[pos].dnxt[i]=vdfs(bitm-nie[i]);
		else V[pos].dnxt[i]=-1;
		if(V[pos].k<8&&V[pos].a[i]<8) V[pos].unxt[i]=vdfs(bitm+nie[i]);
		else V[pos].unxt[i]=-1;
	}
	return pos;
}

void init(){
	st.clear();
	top=0;
	vdfs(0LL);
}

double c;
int m,n,k;
int S[10],K[10];
double P[10][105];
char name[10][105];

int main(){
	init();
	bool flag=false;
	while(scanf("%lf%d%d%d",&c,&m,&n,&k)==4){
		if(!flag) flag=true;
		else printf("\n");
		for(int i=0;i<n;i++){
			scanf("%s%d%d",name[i],&S[i],&K[i]);
			for(int j=0;j<m;j++)
				scanf("%lf",&P[i][j]);
		}
	}
	return 0;
}
