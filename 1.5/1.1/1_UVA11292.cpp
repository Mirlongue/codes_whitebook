#include<iostream>  
#include<string>  
#include<set>  
#include<queue>  
#include<vector>  
#include<map>  
#include<algorithm>  
#include<cstdio>  
#include<cstring>  
#include<cstdlib>  
#include<cmath>  
using namespace std;
int a[30005], b[30005];
int main()
{
    int n, m;
    while (cin>>n>>m &&(n||m))
    {
    //  memset(a, 0, sizeof(a));
        //memset(b, 0, sizeof(b));
        int i, j;
        for (i = 0; i < n; i++)
            cin >> a[i];
        for (i = 0; i < m; i++)
            cin >> b[i];
        sort(a, a + n);
        sort(b, b + m);
        int cnt = 0;
        int sum = 0;
        for (i = 0; i < m; i++)
        {
            if (b[i] >= a[cnt])
            {
    sum += b[i];
            if (++cnt == n) break;
            }

        }
        if (cnt < n) printf("Loowater is doomed!\n");
        else cout << sum << endl;


    }
    return 0;
}
