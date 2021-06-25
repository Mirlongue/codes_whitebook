#include<cstdio>
using namespace std;

int d,n,m;
int a[20],f[20];

struct Matrix{
	int m[20][20];
};

Matrix mult(Matrix A,Matrix B){
	Matrix C;
	for(int i=0;i<d;i++)
		for(int j=0;j<d;j++){
			C.m[i][j]=0;
			for(int k=0;k<d;k++)
				C.m[i][j]=(C.m[i][j]+A.m[i][k]*B.m[k][j])%m;
		}
	return C;	
}

void init(Matrix &A){
	for(int i=0;i<d;i++)
		A.m[0][i]=a[i]%m;
	for(int i=1;i<d;i++)
		for(int j=0;j<d;j++)
				A.m[i][j]=0;
	for(int i=1;i<d;i++)
		A.m[i][i-1]=1;
}

Matrix pow(Matrix A,int b){
	Matrix ans;
	for(int i=0;i<d;i++)
		for(int j=0;j<d;j++)
			ans.m[i][j]=0;
	for(int i=0;i<d;i++)
		ans.m[i][i]=1;
	
	while(b){
		if(b&1)
			ans=mult(ans,A);
		A=mult(A,A);
		b>>=1;
	}
	
	return ans;	
}

int main(){
	while(scanf("%d%d%d",&d,&n,&m)!=EOF){
		for(int i=0;i<d;i++) scanf("%d",&a[i]);
		for(int i=0;i<d;i++) scanf("%d",&f[i]);
		
		Matrix A;
		init(A);
		A=pow(A,n-d);
		
		Matrix B;
		for(int i=0;i<d;i++)
			for(int j=0;j<d;j++)
				B.m[i][j]=0;
		
		for(int i=0;i<d;i++)
			B.m[i][0]=f[d-1-i];
		
		Matrix C=mult(A,B);
		
		printf("%d\n",C.m[0][0]);
		
	}
	return 0;
} 
