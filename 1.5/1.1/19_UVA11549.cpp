#include<cstdio>
#include<iostream>
using namespace std;

int next(int n,int k){
	streamstring ss;
	ss<<(long long)k*k;
	string s=ss.str();
	if(s.length>n) s.substr(0,n);
	int ans;
	stringstream ss2(s);
	ss2>>ans;
	return ans;
}
/*
int buf[101];
int next(int n,int k){
	long long s=(long long) k*k;
	memset(buf,0,sizeof(buf));
	int res=0;
	while(s){
		buf[res++]=s%10;
		s=s/10;
	}
	k=0;
	if(res>n){
		for(int i=res-1;i>res-1-n;i--){
			k=k*10+buf[i];
		}
	}else{
		for(int i=res-1;i>=0;i--){
			k=k*10+buf[i];
		}
	}
	return k;
}
*/

int main(){
	int T;
	cin>>T;
	while(T--){
		int n,k;
		cin>>n>>k;
		int ans=k;
		int k1=k,k2=k;
		do{
			k1=next(n,k1);
			k2=next(n,k2);if(k2>ans) ans=k2;
			k2=next(n,k2);if(k2>ans) ans=k2;
		}
	}
	return 0;
}
