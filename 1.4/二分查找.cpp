#include<cstdio>
using namespace std;
//       0 1 2 3 4 5 6 7 8 
int s[]={1,2,2,3,5,6,6,6,7};
int ss[]={0,1,2,3,4,5,6,7,8};
/*
int lower_bound(int t){
	int a=0,b=9;
	int mid;
	while(a<b){
		mid=a+b>>1;
		if(t<=s[mid]) b=mid;
		else a=mid+1;
	}
	return b;
}
*/
int lower_bound(int t){
	int a=0,b=8;
	int mid;
	while(a<=b){
		mid=a+b>>1;
		if(t<=s[mid]) b=mid-1;
		else a=mid+1;
	}
	return a;
}

int upper_bound(int t){
	int a=0,b=9;
	int mid;
	while(a<b){
		mid=a+b>>1;
		if(t>=s[mid]) a=mid+1;
		else b=mid;
	}
	return b;
}
int binary_search(int t){
	int a=0,b=9;
	int mid;
	while(a<b){
		mid=a+b>>1;
		if(ss[mid]==t) return mid;
		else if(t>ss[mid]) a=mid+1;
		else b=mid;
	}
}



int main(){
	int x=lower_bound(6);
	int y=upper_bound(6);
	int z=binary_search(3);	
	printf("%d %d %d\n",x,y,z);
	return 0;
}
