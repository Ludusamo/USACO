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
*/

using namespace std;

typedef pair<int, int> cow;
typedef vector<cow> VP;

int N, output, checked[100000];
VP cows;

bool compareCows(const cow &a, const cow &b) {
	return a.a < b.a;
}

void solve() {
	output = 0;	
	int nSC = 0; // not safe cows
	int maxB = -2000000;
	for (int a = 1; a < N; a++) {
		if (maxB >= cows[a].b) {
			checked[a] = 1;
		       	nSC++;	
		}
		maxB = (maxB > cows[a].b) ? maxB : cows[a].b;
	}
	int minB = 2000000;	
	for (int a = N - 1; a >= 0; a--) {
		if (minB <= cows[a].b && checked[a] != 1) nSC++;	
		minB = (minB < cows[a].b) ? minB : cows[a].b;
	}
	output = N - nSC;
}

int main() {
	ifstream fin("crossings.in");
		fin >> N;
		int a, b;
		for (int i = 0; i < N; i++) {
			fin >> a >> b;
			cows.pb(mp(a, b));
		}
		sort(cows.begin(), cows.end(), compareCows);
	fin.close();

	solve();

	ofstream fout("crossings.out");
	fout << output << endl;
	fout.close();
	return 0;
}
