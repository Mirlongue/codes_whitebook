#include<stdio>
using namespace std;
const double INF=1e22;
const int MAXN=1111;

double d[MAXN][MAXN][2];
struct Sec{
	int x,c,d;
	void read(){
		scanf("%d%d%d",&x,&c,&d);
	}
	bool operator <(const Sec &tmp)const{
		return x<tmp.x;
	}
}sec[MAXN];

int main(){
	int n,s;
	double v;
	while(~scanf("%d%lf%d",&n,&v,&s)&&n){
		for(int i=1;i<=n;i++){
			sec[i].read();
		}
		sort(sec+1,sec+1+n);
		sum[0]=0;
		for(int i=1;i<=n;i++)
			sum[i]=sum[i-1]+sec[i].d;
		
		for(int len=0;len<n;len++)
			for(int i=1;i+len<=n;i++)
				d[i][i+len][0]=d[i][i+len][1]=INF;
		
		int x1,x2;
		for(int i=1;i<=n;i++){
			if(sec[i].x>s){
				x2=i;
				break;
			}
			x1=i;
		}
		d[x1][x1][0]=d[x1][x1][1]=sum[n]*(abs(s-sec[x1].x)/v)+sec[x1].c;
		d[x2][x2][0]=d[x2][x2][1]=sum[n]*(abs(s-sec[x2].x)/v)+sec[x2].c;		
		
		for(int len=1;len<n;len++){
			for(int i=1;i+len<=n;i++){
				int j=i+len;
				d[i][j][0]=min(d[i+1][j][0]+(sum[n]+sum[i]-sum[j])*(sec[i+1].x-sec[i].x)/v+sec[i].c,
							   d[i+1][j][1]+(sum[n]+sum[i]-sum[j])*(sec[j].x-sec[i].x)/v+sec[i].c);
				d[i][j][1]=min(d[i][j+1][1]+(sum[n]+sum[i-1]-sum[j-1])*(sec[j].x-sec[j-1].x)/v+sec[j].c,
							   d[i][j+1][0]+(sum[n]+sum[i-1]-sum[j-1])*(sec[j].x-sec[i].x)/v+sec[j].c);
			}
		}
		printf("%.0f\n",min(d[n][1][0],d[n][1][1]));
	}
	return 0;
}
