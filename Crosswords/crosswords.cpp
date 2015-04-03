#include <iostream>
#include <fstream>
#include <string>
#include <cmath>

#define MAX 50

using namespace std;

int N, M;
int board[MAX][MAX];
int flags[MAX][MAX];
int numFlags = 0;

bool isHorizontal(int x, int y) {
	if (board[y][x] == 1) return false;	
	if (x == 0 || board[y][x-1] == 1) {
		if (board[y][x+1] == 0 && board[y][x+2] == 0 && x < M - 2) {
			return true;
		}
	}
	return false;
}

bool isVertical(int x, int y) {
	if (board[y][x] == 1) return false;	
	if (y == 0 || board[y - 1][x] == 1) {
		if (board[y + 1][x] == 0 && board[y + 2][x] == 0 && y < N - 2) {
			return true;
		}
	}
	return false;
}

void solve() {
	for (int y = 0; y < N; y++) {
		for (int x = 0; x < M; x++) {
			if (isVertical(x, y) || isHorizontal(x,y)) {
				flags[y][x] = 1;
				numFlags++;
			} else {
				flags[y][x] = 0;
			}
		}
	}
}

int main() {
	ifstream fin("crosswords.in");
	fin >> N >> M;
	string row;
	for (int y = 0; y < N; y++) {
		fin >> row;
		for (int x = 0; x < M; x++) {
			if (row[x] == '.') board[y][x] = 0;
			else board[y][x] = 1;
		}
	}
	solve();	
	ofstream fout("crosswords.out");
	fout << numFlags << endl;
	for (int y = 0; y < N; y++) {
		for (int x = 0; x < M; x++) {
			if (flags[y][x] == 1) {
				fout << y + 1 << " " << x + 1 << endl;
			}
		}
	}
}
