#include<bits/stdc++.h>
using namespace std;
///////////////////////////////////////////////////////////////////
//Geometry
typedef complex<double> point;
#define EPS 1e-9
#define OO 1e9
#define X real()
#define Y imag()
#define vec(a,b) ((b) - (a))
#define polar(r,t) ((r) * exp(point(0, (t))))
#define angle(v) (atan2((v).Y, (v).X))
#define length(v) ((double)hypot((v).Y, (v).X))
#define lengthSqr(v) (dot(v, v))
#define dot(a,b) ((conj(a) * (b)).real())
#define cross(a,b) ((conj(a) * (b)).imag())
#define rotate(v,t) (polar(v, t))
#define rotateabout(v,t,a) (rotate(vec(a, v), t) + (a))
#define reflect(p,m) ((conj((p) / (m))) * (m))
#define normalize(p) ((p) / length(p))
#define same(a,b) (lengthSqr(vec(a, b)) < EPS)
#define mid(a,b) (((a) + (b)) / point(2, 0))
#define perp(a) (point(-(a).Y, (a).X))
#define colliner pointOnLine
enum STATE {
    IN, OUT, BOUNDRY
};

// Intersect 
bool intersect(const point& a, const point& b,
    const point& p, const point& q, point& ret) {
    //handle degenerate cases (2 parallel lines, 2 identical lines, line is 1 		point)
    double d1 = cross(p - a, b - a);
    double d2 = cross(q - a, b - a);
    ret = (d1 * q - d2 * p) / (d1 - d2);
    if (fabs(d1 - d2) > EPS) return 1;
    return 0;
}

//Is Point On Ray
bool pointOnRay(const point& a, const point& b, const point& p) {
    //IMP NOTE: a,b,p must be collinear
    return dot(vec(a, p), vec(a, b)) > -EPS;
}

//Point On Segment
bool pointOnSegment(const point& a, const point& b, const point& p) {
    //el satr da momken y3mel precision error
    if (!colliner(a, b, p)) return 0;
    return pointOnRay(a, b, p) && pointOnRay(b, a, p);
}
//Point On Line
bool pointOnLine(const point& a, const point& b, const point& p) {
    // degenerate case: line is a point
    return fabs(cross(vec(a, b), vec(a, p))) < EPS;
}
//Point Line Dist
double pointLineDist(const point& a, const point& b, const point& p) {
    // handle degenrate case: (a,b) is point
    return fabs(cross(vec(a, b), vec(a, p)) / length(vec(a, b)));
}

//Point Segment Dist
double pointSegmentDist(const point& a, const point& b, const point& p) {
    if (dot(vec(a, b), vec(a, p)) < EPS)
        return length(vec(a, p));
    if (dot(vec(b, a), vec(b, p)) < EPS)
        return length(vec(b, p));
    return pointLineDist(a, b, p);
}

//Segment Lattice Point Count
int segmentLatticePointsCount(int x1, int y1, int x2, int y2) {
    return abs(GCD(x1 - x2, y1 - y2)) + 1;
}

//Sin Rule
double sinRuleAngle(double s1, double s2, double a1) {
    // Handle denom = 0
    double res = s2 * sin(a1) / s1;
    if (res > 1)
        res = 1;
    if (res < -1)
        res = -1;
    return asin(res);
}
double sinRuleSide(double s1, double a1, double a2) {
    // Handle denom = 0
    double res = s1 * sin(a2) / sin(a1);
    return fabs(res);
}

//Cosine Rule
//get angle opposite to side a
double cosRule(double a, double b, double c) {
    // Handle denom = 0
    double res = (b * b + c * c - a * a) / (2 * b * c);
    if (res > 1)
        res = 1;
    if (res < -1)
        res = -1;
    return acos(res);
}

//Triangle Area
double triangleAreaBH(double b, double h) {
    return b * h / 2;
}
double triangleArea2sidesAngle(double a, double b, double t) {
    return fabs(a * b * sin(t) / 2);
}
double triangleArea2anglesSide(double t1, double t2,
    double s) {
    return fabs(s * s * sin(t1) * sin(t2) / (2 * sin(t1 + t2)));
}
double triangleArea3sides(double a, double b, double c) {
    double s((a + b + c) / 2);
    return sqrt(s * (s - a) * (s - b) * (s - c));
}
double triangleArea3points(const point& a, const point& b,
    const point& c) {
    return fabs(cross(a, b) + cross(b, c) + cross(c, a)) / 2;
}


//Pick’s Theorem
//count interior lattice points
int picksTheorem(int a, int b) {
    return a - b / 2 + 1;
}
int picksTheorem(vector<point>& p) {
    double area = 0;
    int bound = 0;
    for (int i = 0; i < sz(p); i++) {
        int j = (i + 1) % sz(p);
        area += cross(p[i], p[j]);
        point v = vec(p[i], p[j]);
        bound += abs(GCD((int)v.X, (int)v.Y));
    }
    area /= 2;
    area = fabs(area);
    return round(area - bound / 2 + 1);
}
//Circle Line Intersection
int circleLineIntersection(const point& p0, const point& p1,
    const point& cen, double rad, point& r1, point& r2) {
    // handle degenerate case if p0 == p1
    double a, b, c, t1, t2;
    a = dot(p1 - p0, p1 - p0);
    b = 2 * dot(p1 - p0, p0 - cen);
    c = dot(p0 - cen, p0 - cen) - rad * rad;
    double det = b * b - 4 * a * c;
    int res;
    if (fabs(det) < EPS)
        det = 0, res = 1;
    else if (det < 0)
        res = 0;
    else
        res = 2;
    det = sqrt(det);
    t1 = (-b + det) / (2 * a);
    t2 = (-b - det) / (2 * a);
    r1 = p0 + t1 * (p1 - p0);
    r2 = p0 + t2 * (p1 - p0);
    return res;
}


// Intersect
int intersect(int a, int b, int c, int d) {
	int l = a > c ? a : c;
	int r = b < d ? b : d;

	return l <= r;
}

// distance between two pointes
double distance(double x1, double y1, double x2, double y2)
{
    return hypot(x1 - x2, y1 - y2);
}

//Circle Circle Intersection
int circleCircleIntersection(const point& c1, const double& r1,
    const point& c2, const double& r2,
    point& res1, point& res2) {
    if (same(c1, c2) && fabs(r1 - r2) < EPS) {
        res1 = res2 = c1;
        return fabs(r1) < EPS ? 1 : OO;
    }
    double len = length(vec(c1, c2));
    if (fabs(len - (r1 + r2)) < EPS ||
        fabs(fabs(r1 - r2) - len) < EPS) {
        point d, c;
        double r;
        if (r1 > r2)
            d = vec(c1, c2), c = c1, r = r1;
        else
            d = vec(c2, c1), c = c2, r = r2;
        res1 = res2 = normalize(d) * r + c;
        return 1;
    }
    if (len > r1 + r2 || len < fabs(r1 - r2))
        return 0;
    double a = cosRule(r2, r1, len);
    point c1c2 = normalize(vec(c1, c2)) * r1;
    res1 = rotate(c1c2, a) + c1;
    res2 = rotate(c1c2, -a) + c1;
    return 2;
}
//Circle From 2 Points
void circle2(const point & p1, const point & p2, point & cen, double& r) {
    cen = mid(p1, p2);
    r = length(vec(p1, p2)) / 2;
}

//Circle From 3 Points
bool circle3(const point & p1, const point & p2, const point & p3,
    point & cen, double& r) {
    point m1 = mid(p1, p2);
    point m2 = mid(p2, p3);
    point perp1 = perp(vec(p1, p2));
    point perp2 = perp(vec(p2, p3));
    bool res = intersect(m1, m1 + perp1, m2, m2 + perp2, cen);
    r = length(vec(cen, p1));
    return res;
}

//Circle Point
STATE circlePoint(const point& cen, const double& r, const point& p) {
    double lensqr = lengthSqr(vec(cen, p));
    if (fabs(lensqr - r * r) < EPS)
        return BOUNDRY;
    if (lensqr < r * r)
        return IN;
    return OUT;
}
//Circle Tangent from Point
int tangentPoints(const point& cen, const double& r, const point& p,
    point& r1, point& r2) {
    STATE s = circlePoint(cen, r, p);
    if (s != OUT) {
        r1 = r2 = p;
        return s == BOUNDRY;
    }
    point cp = vec(cen, p);
    double h = length(cp);
    double a = acos(r / h);
    cp = normalize(cp) * r;
    r1 = rotate(cp, a) + cen;
    r2 = rotate(cp, -a) + cen;
    return 2;
}

//Minimum Enclosing Circle
//init p array with the points and ps with the number of points
//cen and rad are result circle
//you must call random_shuffle(p,p+ps); before you call mec
#define MAXPOINTS 100000
point p[MAXPOINTS], r[3], cen;
int ps, rs;
double rad;
void mec() {
    if (rs == 3) {
        circle3(r[0], r[1], r[2], cen, rad);
        return;
    }
    if (rs == 2 && ps == 0) {
        circle2(r[0], r[1], cen, rad);
        return;
    }
    if (!ps) {
        cen = r[0];
        rad = 0;
        return;
    }
    ps--;
    mec();
    if (circlePoint(cen, rad, p[ps]) == OUT) {
        r[rs++] = p[ps];
        mec();
        rs--;
    }
    ps++;
}
//Polygon Area
//to check if the points are sorted anti-clockwise or clockwise
//remove the fabs at the end and it will return -ve value if clockwise
double polygonArea(const vector<point>& p) {
    double res = 0;
    for (int i = 0; i < sz(p); i++) {
        int j = (i + 1) % sz(p);
        res += cross(p[i], p[j]);
    }
    return fabs(res) / 2;
}
//Sort Anti - Clockwise
struct cmp {
    point about;
    cmp(point c) {
        about = c;
    }
    bool operator()(const point& p, const point& q) const {
        double cr = cross(vec(about, p), vec(about, q));
        if (fabs(cr) < EPS)
            return make_pair(p.Y, p.X) < make_pair(q.Y, q.X);
        return cr > 0;
    }
};
void sortAntiClockWise(vector<point>& pnts) {
    point mn(1 / 0.0, 1 / 0.0);
    for (int i = 0; i < sz(pnts); i++)
        if (make_pair(pnts[i].Y, pnts[i].X) < make_pair(mn.Y, mn.X))
            mn = pnts[i];
    sort(all(pnts), cmp(mn));
}