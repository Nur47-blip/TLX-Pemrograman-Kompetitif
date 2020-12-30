#include <bits/stdc++.h>

using namespace std;

const int mod=1000000;
int powerlarge(long long a, long long b){
	long long result=1;
	while (b){
		if (b & 1) result=result*a%mod;
		b=b/2;
		a=a*a%mod;
	}
	return result;
}
	
int main()
{

	long long int a,b;
	cin>>a>>b;
	int d=powerlarge(a,b);
	bool tes=true;
	int c=1;
	while (b){
		c=c*a;
		if (c>999999){
			tes=false;
			break;
		}
		b--;
	}
	if (tes) cout<<d<<endl;
	else {
		ostringstream ss;
		ss<<d;
		int n=6-ss.str().length();
		for (int i=1;i<=n;i++) cout<<0;
		cout<<d<<endl;
	}

return 0;
}
