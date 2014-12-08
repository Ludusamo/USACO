/*
ID: brehor1
PROG: ariprog
LANG: C++
*/

#include <algorithm>
#include <fstream>
#include <iostream>
#include <vector>
 
using namespace std;
 
 
bool Sort(pair < int, int > a, pair < int, int > b)
{
	if (a.second < b.second)
		return true;
	if (a.second == b.second && a.first < b.first)
		return true;
	return false;
}
 
int main(void)
{
	ifstream input;
	int      table[125000 + 1] = { 0 };
	int      a, i, j;
	int      N = 0;
	int      M = 0;
	ofstream output;
	pair < int, int > p;
	vector < pair < int, int > > answer;
 
 
	for (i = 0; i < 125000; i++)
		table[i] = -1;
 
 
	input.open("ariprog.in", ios_base::in);
	output.open("ariprog.out", ios_base::out | ios_base::trunc);
 
	input >> N >> M;
 
	//  Build a table of the valid numbers.
	for (i = 0; i <= M; i++)
	{
		for (j = i; j <= M; j++)
		{
			table[i * i + j * j] = i * i + j * j;
		}
	}
 
	//  Loop through each number looking for sequences.
	for (i = 0; i < 125000; i++)
	{
		if (table[i] == -1)
			continue;
 
		j = (125000 - i) / (N - 1);
		for (j = j; j > 0; j--)
		{
			for (a = 0; a < N; a++)
			{
				if (table[i + (a * j)] == -1)
					break;
			}
			if (a == N)
			{
				p.first = i;
				p.second = j;
				answer.push_back(p);
			}
		}
	}
 
	sort(answer.begin(), answer.end(), Sort);
 
	if (answer.size() == 0)
		output << "NONE" << endl;
	else
	{
		for (int j = 0; j < answer.size(); j++)
			output << answer[j].first << " " << answer[j].second << endl;
	}
 
	input.close();
	output.close();
 
 
	return 0;
}