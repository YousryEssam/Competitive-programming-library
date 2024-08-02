//This algorithm not only computes the greatest common divisor (GCD) of two integers a and 𝑏 
//but also finds coefficients x and y such that ===>  a*x  + b*y  = GCD(a ,b) 
long long Extended_GCD(long long a, long long  b, long long& x, long long& y){
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