#include<cstdio>
#include<cmath>
using namespace std;
const double eps=1e-5;

int D,H,B,L;

double F(double a,double x){
	double a2=a*a;double x2=x*x;double tmp;
	tmp=tmp+x*sqrt(a2+x2);
	tmp=tmp+a2*log(fabs(x+sqrt(a2+x2)));
	return tmp/2;
}

double parabola_arc_length(double w,double h){
	double a=4.0*h/(w*w);
	double b=1.0/(2*a);
	return (F(b,w/2)-F(b,0))*4*a;
}

int main(){
	int T;
	while(scanf("%d",&T)!=EOF){
		while(T--){
			scanf("%d%d%d%d",&D,&H,&B,&L);
			int n=(B-1)/D+1;
			double D1=(double)B/n;
			double L1=(double)L/n;
			double x=0.0,y=H;
			while(y-x>eps){
				double m=x+(y-x)/2;
				if(parabola_arc_length(D1,m)<L1)
					x=m;
				else
					y=m;
			}
			printf("%.2lf\n",H-x);
			
		}
	}
	return 0;
}
