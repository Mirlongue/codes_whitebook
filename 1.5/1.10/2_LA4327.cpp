#include<cstdio>
#include<cstring>
#include<queue>
#include<algorithm>
using namespace std;
 
#define MP make_pair
 
typedef long long lld;
 
const int INF = 0x0fffffff ;
 
struct Road
{
    int val,len;
} road[111][11111] ;
 
int sum_val[111][11111],sum_len[111][11111];
 
int d[111][11111];
 
int q[11111];
 
int main()
{
    int n,m,k;
    while(~scanf("%d%d%d",&n,&m,&k)&&(n+m+k))
    {
        n++;
        for(int i = 1;i<=n;i++)
        {
            sum_val[i][0] = 0;
            for(int j = 1;j<=m;j++)
            {
                scanf("%d",&road[i][j].val);
                sum_val[i][j]  = sum_val[i][j-1] + road[i][j].val;
            }
        }
        for(int i = 1;i<=n;i++)
        {
            sum_len[i][0] = 0;
            for(int j = 1;j<=m;j++)
            {
                scanf("%d",&road[i][j].len);
                sum_len[i][j] = sum_len[i][j-1] + road[i][j].len;
            }
        }
        for(int i = 1;i<=(m+1);i++)
            d[0][i] = 0;
        for(int i = 1;i<=n;i++)
        {
            int front = 0,rear = 0;
            q[0] = 1;
            for(int j = 1;j<=(m+1);j++)
            {
                while(front<=rear&& d[i-1][q[rear]] - sum_val[i][q[rear]-1] <= d[i-1][j] - sum_val[i][j-1] ) rear--;
                q[++rear] = j;
                
                while(front<=rear&& sum_len[i][j-1] - sum_len[i][q[front]-1] > k) front++;
                
                d[i][j] = d[i-1][q[front]] + sum_val[i][j-1] - sum_val[i][q[front]-1];
            }
 
            front = 0,rear = 0;
            q[0] = m+1;
            for(int j = (m+1);j>=1;j--)
            {
                while(front<=rear&& d[i-1][q[rear]] + sum_val[i][q[rear]-1] <= d[i-1][j] + sum_val[i][j-1]) rear--;
                q[++rear] = j;
                
                while(front<=rear&& sum_len[i][q[front]-1] - sum_len[i][j-1] > k) front++;
                
                d[i][j] = max(d[i][j],d[i-1][q[front]] + sum_val[i][q[front]-1] - sum_val[i][j-1]);
            }
            /*for(int j = 1;j<=(m+1);j++)
                printf("d[%d][%d] = %d\n",i,j,d[i][j]);*/
/*

		for(int i=0;i<=m;i++) d[0][i]=0;
		
		int rear,front;
		for(int i=1;i<=n;i++){
			rear=front=0;
			q[0]=0;
			d[i][0]=d[i-1][0];
			
			for(int j=1;j<=m;j++){
				while(front<=rear&&d[i-1][q[rear]]-sum_val[i][q[rear]]<=d[i-1][j]-sum_val[i][j]) rear--;
				q[++rear]=j;
				while(front<=rear&&sum_len[j]-sum_len[q[front]]>k) front++;
				d[i][j]=sum_val[i][j]+d[i-1][q[front]]-sum_val[i][q[front]];
			}
			
			rear=front=0;
			q[0]=m;
			d[i][m]=max(d[i][m],d[i-1][m]);
			
			for(int j=m-1;j>=1;j--){
				while(front<=rear&&d[i-1][q[rear]]+sum_val[i][q[rear]]<=d[i-1][j]+sum_val[i][j])rear--;
				q[++rear]=j;
				while(front<=rear&&sum_len[q[front]]-sum_len[j]>k) front++;
				d[i][j]=max(d[i][j],d[i-1][q[front]]+sum_val[i][q[front]]-sum_val[i][j]);
			}
			
		}
*/        
		
		
		
		}
        int ans = -INF;
        for(int i = 1;i<=(m+1);i++)
            ans = max(ans,d[n][i]);
        printf("%d\n",ans);
    }
    return 0;
}
