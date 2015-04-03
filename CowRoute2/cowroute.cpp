#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>

using namespace std;

/* N planes (1 <= N <= 500)
 * Each flies a specific route
 * Bessie can start from any city on the route.
 * Bessie can get off at any city on the route. **
 * ** Route does not loop around.
 * One fixed cost when riding the route.
 *
 * Objective: Cheapest way to fly from her farm to her destination.
 * Conditions: Bessie can use up to two routes.
*/

int A, B, N, lowestCost;
bool AAppeared, BAppeared;

// Airplanes that can reach the destination
class Airplane {
public:
	Airplane(){};
	int cost;
	vector<int> citiesBeforeB; // If any
	vector<int> citiesAfterA; 
	bool isCityBeforeB(int city) { 
		for (int i = 0; i < citiesBeforeB.size(); i++) {
			if (citiesBeforeB[i] == city) return true;
		}	
	}

	bool operator < (const Airplane& B) const {
		return cost < B.cost;
	}
};

vector<Airplane> hasB, hasA;

void solve() {
	for (int a = 0; a < hasA.size(); a++) {
		for (int b = 0; b < hasB.size(); b++) {
			int cost = hasA[a].cost + hasB[b].cost;
			if (cost >= lowestCost) break; // Because everything after will be larger too
			for (int c = 0; c < hasA[a].citiesAfterA.size(); c++) { // Goes through all the cities after A
				if (hasB[b].isCityBeforeB(hasA[a].citiesAfterA[c])) lowestCost = cost; // If any of the cities after A
												  // can reach B, set lowestCost
			}
		}
	}
}

int main() {
	lowestCost = 1000000;
	ifstream fin("cowroute.in");
		fin >> A >> B >> N;
		int CC, nC, C; // Current Cost and numCities and city
		for (int i = 0; i < N; i++) { 
			fin >> CC >> nC;
			
			Airplane buffer;
			buffer.cost = CC;

			AAppeared = false;
			BAppeared = false;
			for (int j = 0; j < nC; j++) {
				fin >> C;
				if (AAppeared) buffer.citiesAfterA.push_back(C);
				if (C == A) AAppeared = true;
				if (C == B) {
					BAppeared = true;
					if (AAppeared) lowestCost = (CC < lowestCost) ? CC : lowestCost; 
				}
				if (!BAppeared) buffer.citiesBeforeB.push_back(C);
			}
			if (AAppeared) hasA.push_back(buffer);
			if (BAppeared) hasB.push_back(buffer);
		}	
	fin.close();

	sort(hasA.begin(), hasA.end());
	sort(hasB.begin(), hasB.end());

	solve();

	lowestCost = (lowestCost > 1000) ? -1 : lowestCost;

	ofstream fout("cowroute.out");
		fout << lowestCost << endl;
	fout.close();
	return 0;
}
