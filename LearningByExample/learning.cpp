#include <iostream>
#include <fstream>
#include <string>
#include <algorithm>
#include <cmath>

#define MAX 50000

using namespace std;

int N;
long int A, B, numSpots, difference;
enum CASE { LOWER, MIDDLE, UPPER, OUT };

class cow {
public:
	long int weight, low, high;
	bool spots;
	bool operator<(const cow& other) const {
		return weight < other.weight;
	}
};

cow cows[MAX];

CASE checkCase(long int x1, long int x2) {
	cout << x1 << " " << x2 << endl;
	if ((x1 <= A && x2 >= A)) {
		cout << "Lower" << endl;
		return LOWER;
	}
	if ((x1 <= B && x2 >= B)) {
		cout << "Upper" << endl;
		return UPPER;
	}
	if ((x1 >= A && x2 <= B)) {
		cout << "Middle" << endl;
		return MIDDLE;
	}
	return OUT;
}

void findRanges() {
	for (int i = 0; i < N; i++) {
		if (cows[i].spots) {
			if (i != N - 1) {
				difference = (cows[i+1].weight - cows[i].weight) / 2;
				cows[i].high = cows[i].weight + difference;
			} else {
				cows[i].high = cows[i].weight;
			}
			if (i != 0) {
				difference = (cows[i].weight - cows[i-1].weight) / 2;
				cows[i].low = cows[i].weight - difference;
			} else {
				cows[i].low = cows[i].weight;
			}
		}
	}
}

void accountForIntersection() {
	for (int i = 0; i < N-1; i++) {
		if (cows[i].spots && cows[i+1].spots) {
			if (cows[i].high > cows[i+1].low) {
				numSpots -= (cows[i].high - cows[i+1].low);
			}
		}
	}
}

void solve() {
	findRanges();	
	for (int i = 0; i < N; i++) {
		if (cows[i].spots) {
			switch (checkCase(cows[i].low, cows[i].high)) {
			case LOWER:
				numSpots += cows[i].high - A + 1;
				break;
			case UPPER:
				numSpots += B - cows[i].low + 1;
				break;
			case MIDDLE:
				numSpots += cows[i].high - cows[i].low + 1;
				break;
			case OUT:
				break;
			}
		}
	}
	accountForIntersection();
}

int main() {
	ifstream fin("learning.in");
	fin >> N >> A >> B;
	cout << A << " " << B << endl;
	for (int i = 0; i < N; i++) {
		string buffer;
		fin >> buffer >> cows[i].weight;
		cows[i].spots = (buffer[0]=='S') ? true:false;
	}
	sort(cows, cows+N);
	solve();
	cout << numSpots << endl;
	ofstream fout("learning.out");
	fout << numSpots << endl;
	return 0;
}
