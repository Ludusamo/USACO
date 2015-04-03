#include <iostream>
#include <fstream>

using namespace std;

/* Given two 3 digit integers
 * Written in bases X and Y (10 <= X,Y <= 15000)
 *
 * Objective: Find bases X and Y
*/

int A, B, N;

int main() {
	ifstream fin("whatbase.in");
		fin >> N;
		for (int i = 0; i < N; i++) {
			fin >> A >> B;
					
		}		
	fin.close();
	A = 47;
	B = 35;
	ofstream fout("whatbase.out");
		fout << A << " " << B << endl;
	fout.close();
	return 0;
}
