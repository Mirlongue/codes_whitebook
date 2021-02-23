#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#define maxlen 500010
using namespace std;
int num[maxlen];
bool cmp(int a,int b)
{
    return abs(a)<abs(b);
}
int main ()
{
    int n,t;
    scanf("%d",&t);
    while(t--)
    {
        scanf("%d",&n);
        for(int i=0;i<n;++i)
            scanf("%d",&num[i]);
        sort(num,num+n,cmp);
        int ans=1;
        int flag=num[0]>0;
        for(int i=1;i<n;++i)
        {
            if(num[i]<0&&flag)
            {
                ans++;
                flag=0;
            }
            else if(num[i]>0&&!flag)
            {
                ans++;
                flag=1;
            }
        }
        printf("%d\n",ans);
    }

}
