#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

long long int N, output = 0;
string S;

class C {
public:
	long long int W[100002], currentW, O;
	C() {
		for (int i = 0; i < 100002; i++) {
			W[i] = 0;
		}
		currentW = 0;
		O = 0;
	}
	void incrementO() {
		O++;
	}
	void addW() {
		currentW++;
		W[currentW] = O;
	}
	int calculateTotal() {
		int total = 0;
		for (long long int i = 0; i < 100002; i++) {
			total += W[i];
		}
		return total;
	}
};

vector<C> c;

void solve() {
	for (long long int i = 0; i < S.length(); i++) {
		switch (S[i]) {
		case 'C':
			c.push_back(C());
			break;
		case 'O':
			for (long long int i = 0; i < c.size(); i++) {
				c[i].incrementO();
			}
			break;
		case 'W':
			for (long long int i = 0; i < c.size(); i++) {
				c[i].addW();
			}
			break;
		}	
	}
	for (long long int i = 0; i < c.size(); i++) {
		output += c[i].calculateTotal();
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
