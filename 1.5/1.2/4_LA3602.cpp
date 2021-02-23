#include <iostream>
#include <map>
#include <cstring>
 
#define MAXN 1000
 
int dnacount[MAXN][4];
 
using namespace std;
 
int main()
{
    int t, m, n, ans, i, j;
    map<char, int> dnamap;
    char dna[] = "ACGT", c;
    char result[MAXN+1];
 
    dnamap['A'] = 0;
    dnamap['C'] = 1;
    dnamap['G'] = 2;
    dnamap['T'] = 3;
 
    scanf("%d", &t);
    while(t--) {
        scanf("%d%d", &m, &n);
        getchar();
 
        memset(dnacount, 0, sizeof(dnacount));
 
        for(i=0; i<m; i++) {
            for(j=0; j<n; j++)
                dnacount[j][dnamap[c = getchar()]]++;
            getchar();
        }
 
        ans = m * n;
        for(i=0; i<n; i++) {
            int maxval = dnacount[i][0];
            int maxindex = 0;
            for(j=1; j<4; j++)
                if(dnacount[i][j] > maxval) {
                    maxval = dnacount[i][j];
                    maxindex = j;
                }
 
            ans -= maxval;
            result[i] = dna[maxindex];
        }
        result[n] = '\0';
 
        printf("%s\n", result);
        printf("%d\n", ans);
    }
 
    return 0;
}
