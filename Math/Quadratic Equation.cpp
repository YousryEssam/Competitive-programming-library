#include<bits/stdc++.h>
using namespace std;
#define ll long long
///////////////////////////////////////////////////////////////////
// Quadratic Equation
pair<double, double> solveQuadratic(double a, double b, double c) 
{
	// ax^2 + bx + c = 0 
	// Calculate the discriminant
	double discriminant = b * b - 4 * a * c;

	// Handle different cases based on the discriminant
	if (discriminant < 0) {
		// Complex roots
		return make_pair(-b / (2 * a), NAN); // NAN for "Not a Number"
	}
	else if (discriminant == 0) {
		// Repeated real root
		return make_pair(-b / (2 * a), -b / (2 * a));
	}
	else {
		// Two distinct real roots
		double root1 = (-b + sqrt(discriminant)) / (2 * a);
		double root2 = (-b - sqrt(discriminant)) / (2 * a);
		return make_pair(root1, root2);
	}
}