#include<cstdio>
#include<cstring>
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
 
const int N = 100 + 5;
char s1[N],s2[N];
int dp[N][N];
 
int main() {
	while(scanf("%s%s",s1,s2) != EOF) {
		int len = strlen(s2);
		memset(dp, 0, sizeof(dp));
		for(int i = 0; i < len; i++) dp[i][i] = 1;
		for(int i = 1; i < len; i++) {
			for(int j = 0; j + i < len; j++) {
				int r = j + i;
				dp[j][r] = dp[j + 1][r] + 1;
				for(int k = j + 1; k <= r; k++) {
					if(s2[j] == s2[k])
						dp[j][r] = min(dp[j][r], dp[j + 1][k] + dp[k + 1][r]);
				}
			}
		}
		int ans[N];
		if(s1[0] == s2[0]) 
			ans[0] = 0;
		else
		   	ans[0] = 1;
		for(int i = 1; i < len; i++) {
			if(s1[i] == s2[i]) {
				ans[i] = ans[i - 1];
				continue;
			}
			ans[i] = dp[0][i];
			for(int j = 0; j < i; j++) {
				ans[i] = min(ans[i], ans[j] + dp[j + 1][i]);
			}
		}
		printf("%d\n",ans[len - 1]);
	}
}
————————————————
版权声明：本文为CSDN博主「二分查找」的原创文章，遵循CC 4.0 BY-SA版权协议，转载请附上原文出处链接及本声明。
原文链接：https://blog.csdn.net/yeyeyeguoguo/article/details/45030729
