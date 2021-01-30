#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
const int maxn=1000+10;
int N;
struct node{
	int B;
	int J;
	
	bool operator < (const node & rhs)const{
		return J<rhs.J;
	}
};
node V[maxn];

int main(){
	while(scanf("%d",&N)&&N){
		for(int i=0;i<N;i++)
			scanf("%d%d",&V[i].B,&V[i].J);
		sort(V,V+N);
		
		int front,rear;
		front=rear=0;
		for(int i=0;i<N;i++){
			front=front+V[i].B;
			rear=max(rear,front+V[i].J);		
		}
		printf("%d\n",rear);
	}	
	return 0;
}
