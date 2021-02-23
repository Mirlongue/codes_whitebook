#include <stdio.h>
#include <string.h>
 
char a[100005], b[100005];
int main() {
	while (~scanf("%s%s", a, b)) {
		int star = 0, lenb = strlen(b), lena = strlen(a);
		for (int i = 0; i < lenb; i ++) {
			if (a[star] == b[i])
				star ++;
			if (star == lena) {
				printf("Yes\n");
				break;
			}
		}
		if (star != lena)
			printf("No\n");
	}
	return 0;
}
