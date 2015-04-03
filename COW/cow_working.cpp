#include <iostream>
#include <fstream>

using namespace std;

long long int N, output;
string S;

void solve() {
	long long int numO[S.length()];
	long long int numW[S.length()];
	for (long long int i = 0; i < S.length(); i++) {
		numO[i] = 0;
		numW[i] = 0;
	}
	long long int numC = 0;
	bool CEncountered = false;
	for (long long int i = 0; i < S.length(); i++) {
		switch (S[i]) {
		case 'C':
			numC++;
			break;
		case 'O':
			if (numC != 0) {
				numO[numC - 1]++;	
			}
			break;
		case 'W':
			if (numC != 0) {
				numW[numC - 1]++;
			}
			break;
		}	
	}
	
	for (long long int i = 0; i < S.length(); i++) {
		output += numO[i] * numW[i] * (i + 1);
	}
}

int main() {
	ifstream fin("cow.in");
		fin >> N >> S;
	fin.close();

	solve();	

	ofstream fout("cow.out");
		fout << output << endl;	
	fout.close();
	return 0;
}