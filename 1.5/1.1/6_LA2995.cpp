#include<cstdio>
using namespace std;
//	  X   Y   Z
char v[11][11][11];
int n;
char view[6][11][11];

void find(int p,int a,int b,int d,int &x,int &y,int &z){
	if(p==0){z=n+1-a;y=b;x=n+1-d;}
	if(p==1){z=n+1-a;x=b;y=d;}
	if(p==2){z=n+1-a;y=n+1-b;x=d;}
	if(p==3){z=n+1-a;x=n+1-b;y=n+1-d;}
	if(p==4){x=a;y=b;z=n+1-d;}
	if(p==5){x=n+1-a;y=b;z=d;}
}

int main(){
	while(scanf("%d",&n)&&n){
		getchar();
		for(int i=1;i<=n;i++)
			for(int j=1;j<=n;j++)
				for(int k=1;k<=n;k++) v[i][j][k]='#';
		for(int i=1;i<=n;i++){
			for(int j=0;j<6;j++){
				for(int k=1;k<=n;k++){
					view[j][i][k]=getchar();
				}
				getchar();
			}
		}
		
		
		
/*		
		for(int i=1;i<=n;i++){
			for(int j=1;j<=n;j++)
				printf("%c",view[5][i][j]);
			printf("\n");		
		}
*/
	
		for(int i=0;i<6;i++)
			for(int j=1;j<=n;j++)
				for(int k=1;k<=n;k++)
					if(view[i][j][k]=='.'){
						for(int d=1;d<=n;d++){
							int x,y,z;
							find(i,j,k,d,x,y,z);
							v[x][y][z]='.';
						}
					}
		
		for(;;){
			bool done =false;
			for(int i=0;i<6;i++){
				for(int j=1;j<=n;j++)
					for(int k=1;k<=n;k++){
						int x,y,z;
						for(int d=1;d<=n;d++){
							find(i,j,k,d,x,y,z);
							if(v[x][y][z]=='.') continue;
							if(v[x][y][z]=='#') {v[x][y][z]=view[i][j][k];break;}
							if(v[x][y][z]!=view[i][j][k]){
								v[x][y][z]='.';
								done=true;
								continue;
							}
							break;
						}
					}
			}
			
			
			if(!done) break;
		}
	
		
		int ans=0;
		for(int i=1;i<=n;i++)
			for(int j=1;j<=n;j++)
				for(int k=1;k<=n;k++)
					if(v[i][j][k]!='.')ans++;
		
		printf("%d\n",ans);
	
				
		
	}
	return 0;
}
