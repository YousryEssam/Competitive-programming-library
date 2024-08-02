#include<vector>
using namespace std ;
//////////////////////////////////////////////////////////////////

//Ternary Search Discrete
vector<int>v; //Data , Or you can replace it with some values like bainary search
bool cost(int val) {
	// implement cost funcrtion here!!
}
pair<int, int> ternaryDiscrete() {

	int left = v[0], right = v.back(); // set your range
	while (right - left > 3) { // We need 4 different positions
		int g = left + (right - left) / 3, h = left + 2 * (right - left) / 3;
        // use > if f increase then decrease
		if (cost(g) < cost(h))  right = h;
		else left = g;
	}

	int solIdx = left, answer = cost(left++);
	// iterate on the remaining
	for (int i = left; i <= right; ++i)	
		if (answer > cost(i)) answer = cost(i), solIdx = i;
	return make_pair(solIdx, answer);
}
