#include<cstdio>
#include<algorithm>
using namespace std;

const int maxn=10000+10;
const double eps=1e-5;
int n,a[maxn],b[maxn],c[maxn];

double F(double x){
	double tmp;
	tmp=a[0]*x*x+b[0]*x+c[0];
	for(int i=1;i<n;i++)
		tmp=max(tmp,a[i]*x*x+b[i]*x+c[i]);
	return tmp;
}

int main(){
	int T;
	while(scanf("%d",&T)!=EOF){
		while(T--){
			scanf("%d",&n);
			for(int i=0;i<n;i++)
				scanf("%d%d%d",&a[i],&b[i],&c[i]);
			
			double L=0.0,R=1000.0,M1,M2;
			while(R-L>eps){
				double len=(R-L)/3;
				M1=L+len;
				M2=R-len;
				double f1=F(M1);
				double f2=F(M2);
				if(f1>f2){
					L=M1;
				}else{
					R=M2;
				}
			}
			printf("%.4lf\n",F(L));
			
		}
	}
	
	
	return 0;
}
