#include <iostream>
#include <fstream>
#include <algorithm>
#include <vector>
#include <utility>

#define pb push_back

// N cows (1 <= N <= 1000)
// Communication with tin cans
// Each cow can forward message to at most 1 cow
// Cow i; F(i) = (cow that i forwards to)
// if F(i) = 0; i cannot forward messages
// cow = loopy if message gets stuck in loop
// want to avoid loopy cows
//
// Objective: Count number of none loopy cows.
//
// Strategy: Vector keeping track of all the cows, who they forward to
// 		and if they are loopy or not. 

using namespace std;

typedef vector<int> VI;

int N, output;
VI cows;

bool checkBranch(int i) {
	int currentCow = i;
	int numSteps = 0;
	while (numSteps <= N) {
		cout << i << " " << cows[i] << endl;
		if (cows[i] == -1) return true;
		i = cows[i];
		numSteps++;
	}
	return false;
}

void solve() {
	for (int i = 0; i < N; i++) {
		cout << i << endl;
		if (checkBranch(i)) output++;	
		cout << endl;
	}		
}

int main() {
	ifstream fin("relay.in");	
	fin >> N;
	int buffer;
	for (int i = 0; i < N; i++) {
		fin >> buffer;	
		buffer -= 1;
		cows.pb(buffer);
	}
	fin.close();	
	solve();

	ofstream fout("relay.out");
	fout << output << endl;
	fout.close();
	return 0;
}
