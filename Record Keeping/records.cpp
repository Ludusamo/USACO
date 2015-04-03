#include <iostream>
#include <fstream>

#define MAX_N 1000

using namespace std;

int N;
int output = 0;
string name1[MAX_N], name2[MAX_N], name3[MAX_N];

int main() {
	ifstream fin("records.in");
	fin >> N;
	string cow1, cow2, cow3;
	for (int i = 0; i < N; i++) {
		fin >> name1[i] >> name2[i] >> name3[i];
		cout << i << ": " << name1[i] << ", " << name2[i] << ", " << name3[i] << endl; 
		int numTimesOccurred = 0;
		for (int j = 0; j < i + 1; j++) {
			if (name1[i] == name1[j] || name1[i] == name2[j] || name1[i] == name3[j]) {
				if (name2[i] == name1[j] || name2[i] == name2[j] || name2[i] == name3[j]) {
					if (name3[i] == name1[j] || name3[i] == name2[j] || name3[i] == name3[j]) {
						cout << i << ": " << name1[j] << ", " << name2[j] << ", " << name3[j] << endl; 
						numTimesOccurred++;
					}
				}
			}
			if (numTimesOccurred > output) output = numTimesOccurred;
		}
		cout << numTimesOccurred << endl << endl;
	}
	fin.close();

	ofstream fout("records.out");
	fout << output << endl;
	fout.close();
	return 0;
}

/*
for (int k = 0; k < N; k++) {
					if (cow2 == name1[j] || cow2 == name2[j] || cow2 == name3[j]) {
						for (int l = 0; l < N; l++) {
							if (cow3 == name1[j] || cow3 == name2[j] || cow3 == name3[j]) {
						}
				}
*/