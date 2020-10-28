#include <bits/stdc++.h>

using namespace std;

int main(){

	long long a, b, c, d;
	cin >> a >> b >> c >> d;
	
	long long x = __gcd(a,b);
	a /= x;
	b /= x;
	
	x = __gcd(c,d);
	c /= x;
	d /= x;
	
	long long e, f;
	e = a*d + c*b;
	f = b*d;
	
	x = __gcd(e,f);
	e /= x;
	f /= x;
	
	cout << e << " " << f << endl;

	return 0;
}

