#include <iostream>
#include <fstream>

#define MAX_N 10000
#define FIELD_SIZE 102

/* N hay bales (1 <= N <= 10000)
 * Field is a 100x100 grid
 * E/a hay bale takes up 1x1
 * All hay bales are connected in one mass
 *
 * Objective: Determine the perimeter that this mass creates.
*/

using namespace std;

int N, field[FIELD_SIZE][FIELD_SIZE], visited[FIELD_SIZE][FIELD_SIZE], perimeter = 0;

int numSurrounded(int x, int y) {
	return ((field[y-1][x] == 1) ? 1 : 0) + ((field[y+1][x] == 1) ? 1 : 0) + 
		((field[y][x+1] == 1) ? 1 : 0) + ((field[y][x+1] == 1) ? 1 : 0);
}

void checkCell(int x, int y) {
	if (visited[y][x] == 1) return;
	if (field[y][x] == 0) {
		visited[y][x] = 1;
		if (y != 0) checkCell(x, y - 1);
		if (y < FIELD_SIZE - 1) checkCell(x, y + 1);
		if (x != 0) checkCell(x - 1, y);
		if (x < FIELD_SIZE - 1) checkCell(x + 1, y);
	} else {
		cout << x << " " << y << endl;
		perimeter++;	
	}
}

void solve() {
	checkCell(0, 0);
}

int main() {
	int x, y;
	ifstream fin("perimeter.in");
		fin >> N;
		for (int i = 0; i < N; i++) {
			fin >> x >> y;
			field[y][x] = 1;
		}
	fin.close();
	solve();
	ofstream fout("perimeter.out");
		cout << perimeter;
		fout << perimeter << endl;
	fout.close();	

	return 0;
}
