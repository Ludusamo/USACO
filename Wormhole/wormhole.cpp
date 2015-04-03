#include <iostream>
#include <fstream>
#include <algorithm>

#define MAX_N 12

using namespace std;

int N, highestY = 0, output = 0;
int X[12], Y[12];

bool check_between(int lower, int higher, int i) {
	for (int k = 0; k < N; k++) {
		if (X[k] > lower && X[k] < higher) {
			if (Y[i] == Y[k]) {
				cout << "Higher, Lower:" << higher << ", " << lower << endl;
				
				return true;
			}
		}
	}
	return false;
}

int main() {
	ifstream fin("wormhole.in");
	fin >> N;
	for (int i = 0; i < N; i++) {
		fin >> X[i] >> Y[i];
		if (Y[i] > highestY) highestY = Y[i];
	}
	fin.close();

	
	for (int i = 0; i < N; i++) {
		cout << X[i] << ", " << Y[i] << endl;
	}

	// Cycle through all of the indexes, i is the current index of y that we are checking
	for (int i = 0; i < N; i++) {
		// Goes through all of the remaining indexes
		for (int j = i + 1; j < N; j++) {
			// Checks if Y-values are the same
			if (Y[i] == Y[j]) {
				int lowerX, higherX;
				lowerX = (X[i] < X[j]) ? X[i] : X[j];
				higherX = (X[i] > X[j]) ? X[i] : X[j];
				// Checks if there are X-values between two values
				if (check_between(lowerX, higherX, i)) continue;
				output++;
			}
		}
	}

	cout << output << endl;
	ofstream fout("wormhole.out");
	fout << output << endl;
	fout.close();
	return 0;
}