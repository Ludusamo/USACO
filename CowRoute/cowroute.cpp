#include <iostream>
#include <fstream>

using namespace std;

/* N planes (1 <= N <= 500)
 * Each flies a specific route
 * Bessie can start from any city on the route.
 * Bessie can get off at any city on the route. **
 * ** Route does not loop around.
 * One fixed cost when riding the route.
 *
 * Objective: Cheapest way to fly from her farm to her destination.
 * Conditions: Bessie can only use one route.
*/

int A, B, N, lowestCost;
bool AAppeared;

int main() {
	lowestCost = 1000000;
	ifstream fin("cowroute.in");
		fin >> A >> B >> N;
		int CC, nC, C; // Current Cost and numCities and city
		for (int i = 0; i < N; i++) {
			fin >> CC >> nC;
			AAppeared = false;
			for (int j = 0; j < nC; j++) {
				fin >> C;
				if (C == A) AAppeared = true;
				if (C == B) {
					cout << i << endl;
					if (AAppeared) lowestCost = (CC < lowestCost) ? CC : lowestCost; 
				}
			}
		}		
	fin.close();
	lowestCost = (lowestCost > 1000) ? -1 : lowestCost;

	ofstream fout("cowroute.out");
		fout << lowestCost << endl;
	fout.close();
	return 0;
}
