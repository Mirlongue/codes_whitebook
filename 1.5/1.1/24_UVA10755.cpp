#include<cstdio>
#include<cstring>
using namespace std;

void expand(int i,int &b0,int &b1,int &b2){
	b0=i&1;i>>=1;
	b1=i&1;i>>=1;
	b2=i&1;
}
int sign(int b0,int b1,int b2){
	return (b0+b1+b2)%2==1?1:-1;
}

const int maxn=30;
const long long INF=0x3f3f3f3f3f3f3f3f;
long long S[maxn][maxn][maxn];

long long sum(int x1,int x2,int y1,int y2,int z1,int z2){
	int dx=x2-x1+1,dy=y2-y1+1,dz=z2-z1+1;
	long long s=0;
	int b0,b1,b2;
	for(int i=0;i<8;i++){
		expand(i,b0,b1,b2);
		s-=S[x2-b0*dx][y2-b1*dy][z2-b2*dz]*sign(b0,b1,b2);
	}
	return s;
}



int main(){
	int T;
	scanf("%d",&T);
	while(T--){
		int a,b,c,b0,b1,b2;
		scanf("%d%d%d",&a,&b,&c);
		memset(S,0,sizeof(S));
		for(int x=1;x<=a;x++)
			for(int y=1;y<=b;y++)
				for(int z=1;z<=c;z++)
					scanf("%lld",&S[x][y][z]);
		for(int x=1;x<=a;x++)
			for(int y=1;y<=b;y++)
				for(int z=1;z<=c;z++)
					for(int i=1;i<=7;i++){
						expand(i,b0,b1,b2);
						S[x][y][z]+=S[x-b0][y-b1][z-b2]*sign(b0,b1,b2);
					}
		
		long long ans=-INF;
		for(int x1=1;x1<=a;x1++)
			for(int x2=x1;x2<=a;x2++)
				for(int y1=1;y1<=b;y1++)
					for(int y2=y1;y2<=b;y2++){
						long long M=0;
						for(int z=1;z<=c;z++){
							long long s=sum(x1,x2,y1,y2,1,z);
							ans=max(ans,s-M);
							M=min(M,s);
						}
					}
		
		printf("%lld\n",ans);
		if(T) printf("\n");
	}
	return 0;
}
