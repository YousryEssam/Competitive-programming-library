#include<bits/stdc++.h>
using namespace std;
#define PI 3.1415926535
///////////////////////////////////////////////////////////////////

// intersect 2 ranges
int intersect(int a, int b, int c, int d) {
	int l = a > c ? a : c;
	int r = b < d ? b : d;
	return l <= r;
}

// Distance between points
double dis(long long x1, long long y1, long long x2, long long y2) {
    return sqrt(pow((x2 - x1), 2) + pow((y2 - y1), 2));
}


// Line Through 3 Points
bool onTheLine(int x1, int y1, int x2, int y2, int x3, int y3) {
    if ((y2 - y1) * (x3 - x2) == (y3 - y2) * (x2 - x1)) return true;
    return false;
}

// Degree => Radian
double toRadian(double degree) { return (degree * PI / 180.0); }

// Radian => Degree
double toDegree(double radian) {
    if (radian < 0) radian += 2 * PI;
    return (radian * 180.0 / PI);
}


// Area Of Triangle From Points 
double areaOfTriangle(pair<double, double> a, pair<double,double> b, pair<double, double> c) {
    double area = a.first * b.second + b.first * c.second +
        c.first * a.second - a.second * b.first - b.second * c.first -
        c.second * a.first;
    area /= 2;
    return abs(area);
}

// slid lenght
double triangleArea(double a, double b, double c) {
    double s = (a + b + c) / 2.0;
    return sqrt((s - a) * (s - b) * (s - c) * s);
}