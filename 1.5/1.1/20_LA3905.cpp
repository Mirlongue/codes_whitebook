#include<cstdio>
#include<algorithm>
#include<cstring>
#define eps 1e-8
using namespace std;
const int maxn=100000+10;

int w,h;
int n;

struct Event{
	double x;
	int type;
	bool operator <(const Event & rhs)const{
		if(x-rhs.x<eps) return type<rhs.type;
		return x<rhs.x;
	}
}events[maxn*2];
int e;

void update(int x,int a,double &L,double &R){
	if(a==0){
		if(x<=0||x>=w) R=L-1;
	}else if(a>0){
		L=max(L,(double)(0-x)/a);
		R=min(R,(double)(w-x)/a);
	}else{
		L=max(L,(double)(w-x)/a);
		R=min(R,(double)(0-x)/a);
	}
}

int main(){
	int T;
	scanf("%d",&T);
	while(T--){
		e=0;
		scanf("%d%d",&w,&h);
		scanf("%d",&n);
		for(int i=0;i<n;i++){
			int x,y,a,b;
			scanf("%d%d%d%d",&x,&y,&a,&b);
			double L=0,R=1e9;
			update(x,a,L,R);
			update(y,b,L,R);
			if(R>L){
				events[e++]=(Event){L,0};
				events[e++]=(Event){R,1};
			}
		}
		sort(events,events+e);
		
		int cnt=0,ans=0;
		for(int i=0;i<e;i++){
			if(events[i].type==0) ans=max(ans,++cnt);
			else cnt--;
		}
		printf("%d\n",ans);
	}
	return 0;
}
