#include <iostream>
#include <cstdlib>
#include <cstdio>
 
using namespace std;
 
int main()
{
	long a,b;
	while ( ~scanf("%ld%ld",&a,&b) )
		printf("%ld\n",a*b-1L);
	return 0;
}
