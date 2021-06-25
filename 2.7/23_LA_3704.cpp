#include<cstdio>
using namespace std;
const int maxn=600+10;
int n,m,d,k;
int e[maxn];

struct Matrix{
	int m[maxn];
};

Matrix mult(Matrix A,Matrix B){
	Matrix C;
	for(int i=0;i<n;i++){
		C.m[i]=0;
		for(int j=0;j<n;j++){
			C.m[i]=(C.m[i]+A.m[j]*B.m[(i-j+n)%n])%m;
		}
	}
	return C;
}

Matrix pow(Matrix A){
	Matrix C;
	C.m[0]=1;
	for(int i=1;i<n;i++) C.m[i]=0;
	
	while(k){
		if(k&1){
			C=mult(C,A);
		}
		A=mult(A,A);
		k>>=1;
	}
	return C;
}

int main(){
	while(scanf("%d%d%d%d",&n,&m,&d,&k)!=EOF){
		for(int i=0;i<n;i++)
			scanf("%d",&e[i]);
		
		Matrix A;
		for(int i=0;i<n;i++) A.m[i]=0;
		for(int i=0;i<=d;i++) A.m[i]=A.m[(n-i)%n]=1;
		
		Matrix B;
		for(int i=0;i<n;i++) B.m[i]=e[(n-i)%n];
		
		Matrix C=mult(A,B);
		
		for(int i=0;i<n;i++)
			printf("%d ",C.m[(n-i)%n]);
		
		
	}
	return 0;
}
