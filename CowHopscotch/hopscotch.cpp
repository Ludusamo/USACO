#include <iostream>
#include <fstream>

using namespace std;

int X, Y, board[20][20], finalTile;
int output;

int examineRoute(int x, int y, int currentTile) {
	cout << "start " << board[y][x] << endl;
	int total = (board[y][x] == finalTile) ? 0 : 1;
	for (int i = y + 1; i < Y; i++) {
		for (int j = x + 1; j < X; j++) {
			if (board[i][j] != currentTile && i != Y - 1 && j != X - 1) {
				cout << i << " " << j << endl;
				total += examineRoute(j, i, board[i][j]);
			}
		}
	}	
	cout << x << ", " << y << " " << total << endl;
	return total;
}

void solve() {
	output = examineRoute(0, 0, board[0][0]);
}

int main() {
	ifstream fin("hopscotch.in");
		string buffer;	
		fin >> X >> Y;
		for (int i = 0; i < Y; i++) {
			fin >> buffer;
			for (int j = 0; j < X; j++) {
				board[i][j] = (buffer[j] == 'R') ? 0 : 1;	
			}
		}
		finalTile = board[Y - 1][X - 1];
	fin.close();
	for (int i = 0; i < Y; i++) {
		for (int j = 0; j < X; j++) {
			cout << board[i][j];
		}
		cout << endl;
	}
	solve();

	ofstream fout("hopscotch.out");
		fout << output << endl;
	fout.close();
	return 0;
}
