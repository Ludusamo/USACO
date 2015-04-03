#include <iostream>
#include <fstream>
#include <string>
#include <cmath>

#define MAX 100000

using namespace std;

long int N, position[MAX], speed[MAX], numGroups;
bool finished = false;

void update() {
	finished = true;
	for (int i = 0; i < N; i++) {
		position[i] += speed[i];
	}
	for (int i = N - 1; i > 0; i--) {
		if (position[i-1] >= position[i]) {
			position[i-1] = position[i] - 1;
			speed[i-1] = speed[i];
		}
		if (finished && speed[i-1] > speed[i]) {
			finished = false;
		}
	}
}

int numGroup() {
	int output = 0;
	for (int i = 0; i < N; i++) {
		if (position[i] != position[i+1] - 1) {
			output++;	
		}
	}
	return output;
}

void solve() {
	while (!finished) {
		update();
	}	
}

int main() {
	ifstream fin("cowjog.in");
	fin >> N;	
	for (int i = 0; i < N; i++) {
		fin >> position[i] >> speed[i];
		cout << position[i] << " " << speed[i] << endl;
	}
	cout << endl;
	solve();
	cout << numGroup() << endl;
	ofstream fout("cowjog.out");
	fout << numGroup() << endl;
	return 0;
}
