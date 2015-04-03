#include <iostream>
#include <fstream>
#include <cmath>

#define MAX_N 100000

using namespace std;

int N;
int X[MAX_N], Y[MAX_N];
int distances[MAX_N], TOTAL_DISTANCE = 0;
int skips[MAX_N];
int minDistance;

int calculateDistance(int x1, int y1, int x2, int y2) {
	return abs(x1 - x2) + abs(y1 - y2);
}

int solve() {
	minDistance = TOTAL_DISTANCE;	
	for (int i = 0; i < N - 2; i++) {
		int posSkipDis = TOTAL_DISTANCE - distances[i] - distances[i+1] + skips[i];
		if (posSkipDis < minDistance) minDistance = posSkipDis;
	}
	return minDistance;	
}

int main() {
	ifstream fin("marathon.in");
	fin >> N;
	for (int i = 0; i < N; i++) {
		fin >> X[i] >> Y[i];
		if (i > 0) {
			distances[i - 1] = calculateDistance(X[i - 1], Y[i - 1], X[i], Y[i]);
			TOTAL_DISTANCE += distances[i - 1];
		}
		if (i > 1) {
			skips[i - 2] = calculateDistance(X[i - 2], Y[i - 2], X[i], Y[i]);
		}	
	}
	ofstream fout("marathon.out");
	fout << solve() << endl;
	return 0;
}
