#include<cstdio>
#include<cmath>
using namespace std;
const double eps= 1e-14;
const double len= 1e-5;

int p,q,r,s,t,u;
double F(double x){
	double tmp=0.0;
	tmp=tmp+p*exp(-x);
	tmp=tmp+q*sin(x);
	tmp=tmp+r*cos(x);
	tmp=tmp+s*tan(x);
	tmp=tmp+t*x*x;
	tmp=tmp+u;
	
	return tmp;
}

int main(){
	double x;
	p=q=r=s=t=u=1;
	while(scanf("%d%d%d%d%d%d",&p,&q,&r,&s,&t,&u)==6){
		double L=0.0,R=1.0,M;
		if(F(L)>eps&&F(R)<-eps){
			while(R-L>len){
				M=(L+R)/2;
				double tmp=F(M);
				if(tmp>=eps){
					L=M;
				}else if(tmp<-eps){
					R=M;
				} 
			}
			printf("%.4lf",L);
			
		}else{
			printf("No solution\n");
		}
		
	}
	return 0;
}
