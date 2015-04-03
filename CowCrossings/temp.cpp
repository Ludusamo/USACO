#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
#include <utility>

#define pb push_back
#define mp make_pair
#define a first
#define b second
#define MAX_N = 100000

/* N cows (1 <= N <= 100000)
 * Road runs horizontally
 * One sided described by y = 0; other by y = 1
 * The cows will cross the road based on a_i and b_i which are their initial and final x positions
 * 1M <= a_i, b_i <= 1M
 * Cows are "safe" if their path does not intersect another cows's
 *
 * Objective: Count the number of safe cows.
 *
 * Strategy: Keep an array of cows with their starting and ending positions. Sort the array based on their
 * 		initial positions. Go through array and search for safe cows. Easier to brute force the cows
 * 		that are not safe. 
*/

using namespace std;

typedef pair<int, int> cow;
typedef vector<cow> VP;

int N, output, checked[100000];
VP cows;

bool compareCows(const cow &a, const cow &b) {
	return a.a < b.a;
}

bool intersects(const cow &a, const cow &b) {
	return (a.a <= b.a && a.b >= b.b) || (b.a <= a.a && b.b >= a.b);
}

void solve() {
	output = 0;	
	int nSC = 0; // not safe cows
	int maxB = cows[0].b;
	for (int a = 0; a < N; a++) {
		if (checked[a] == 1) continue; // if this one was already caught by a past one
		for (int b = 0; b < N; b++) {
			if (a == b) continue; // stops it from checking against itself
			if (intersects(cows[a], cows[b])) {
				cout << a << endl;
				nSC++;
				if (checked[b] != 1) {
					nSC++;
				}
				checked[a] = checked[b] = 1;
				break;
			}
		}
		maxB = (maxB > cows[a].b) ? maxB : cows[a].b;
	}

	output = N - nSC;
}

int main() {
	ifstream fin("crossings.in");
		fin >> N;
		int a, b, bN, sN; // buffer A and B, bigger number, smaller number
		for (int i = 0; i < N; i++) {
			fin >> a >> b;
			cows.pb(mp(a, b));
		}
		sort(cows.begin(), cows.end(), compareCows);
	fin.close();

	solve();

	ofstream fout("crossings.out");
	cout << output << endl;
	fout << output << endl;
	fout.close();
	return 0;
}
