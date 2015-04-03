#include <iostream>
#include <fstream>
#include <string>

using namespace std;

string S, T; 
int sizeOfSubstr, minStart;
string output;

void solve() {
	int firstChar;
	for(;;) {
		firstChar = -1;
		firstChar = S.find(T, minStart);
		if (firstChar != -1) {
			S.erase(firstChar, sizeOfSubstr);
			minStart = S.find(T[0], minStart);
			cout << minStart << endl;
		}
		else break;
	}
	output = S;
}

int main() {
	ifstream fin("censor.in");	
		fin >> S >> T;
		sizeOfSubstr = T.length();
		minStart = S.find(T[0]);
	fin.close();

	solve();

	ofstream fout("censor.out");
		fout << output << endl;		
	fout.close();
	return 0;
}
