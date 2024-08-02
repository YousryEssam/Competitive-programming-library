long long Extended_GCD(long long a, long long  b, long long& x, long long& y)
{
	if (b == 0) {
		x = 1, y = 0;
		return a;
	}
	long long x1, y1;
	long long d = Extended_GCD(b, a % b, x1, y1);
	x = y1;
	y = x1 - y1 * (a / b);
	return d;
}
// need Extended_GCD
// A.B == 1(mod M)
long long ModInverse(long long A, long long M){
	long long B, temp, d;
	d = Extended_GCD(A, M, B, temp);
	//(a*b)%m=1   b exist if gcd(b,m)=1//coprimes 
	return (B % M + M) % M;//B is negative 
}