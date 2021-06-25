int gcd(int a,int b){
	return b==0? a:gcd(b,a%b);
}

//a*x+b*y=gcd(a,b)

/*
b*x1+(a%b)*y1=gcd
b*x1+(a-(a/b)*b)*y1=gcd
b*x1+a*y1-(a/b)*b*y1=gcd
a*y1+b*(x1-a/b*y1)=gcd
   x      y
*/

void ex_gcd(int a,int b,int &d,int &x,int &y){
	if(!b){d=a,x=1,y=0;}
	else{
		ex_gcd(b,a%b,d,y,x);
		//             x1,y1
		y-=x*(a/b);
	}
}

// a，x《1(mod p),gcd(a,p)=1
// a，x+p，y=1
