#include <iostream>
#include <fstream>
#include <vector>
#include <utility>

using namespace std;

#define pb push_back
#define mp make_pair
#define bessie first
#define elsie second

typedef vector< pair<int, int> > VP;

/* N fields (1 <= N <= 16)
 * Field one contains the barn.
 * Field N is favorite field.
 * Farm is built on the side of a hill.
 * Field X is higher than Y.
 * M paths. paths can only be followed downhill.
 * Bessie and Elsie travel at different speeds.
 * Bessie is twice as fast
 *
 * Objective: Find bases X and Y
*/

int N, M, A, B, C, D, leastTime = 1000000, depth;
VP paths, speeds;
vector<int> bessieSpeeds, elsieSpeeds;

pair<int,int> followPath(int path, int startDepth) {
	depth++;
	if (depth > 17) return mp(1000000, 1000000);
	int bessieTime = speeds[path].bessie, elsieTime = speeds[path].elsie;
	int leastTimeBessie = 1000000, leastTimeElsie = 1000001;
	
	cout << paths[path].second << endl;
	if (paths[path].second == N - 1) {
		cout << path << endl;	
		return mp(bessieTime, elsieTime);
	}
	for (int i = startDepth; i < paths.size(); i++) {
		if (path != i && paths[path].second == paths[i].first) {
			bessieTime = speeds[path].bessie;
			elsieTime = speeds[path].elsie;
			pair<int,int> speeds = followPath(i, 0);
			bessieTime += speeds.bessie;
			elsieTime += speeds.elsie;
			if (bessieTime < leastTimeBessie) leastTimeBessie = bessieTime;
			if (elsieTime < leastTimeElsie) leastTimeElsie = elsieTime;
		}
	}	
	return mp(leastTimeBessie, leastTimeElsie);
}

void calculatePaths() {
	for (int i = 0; i < paths.size(); i++) {
		if (paths[i].first == 1) {
			depth = 0;
			for (int j = 0; j < paths.size(); j++) {
				//cout << j << endl;
				pair<int,int> speeds = followPath(i, j);
				bessieSpeeds.pb(speeds.bessie);
				elsieSpeeds.pb(speeds.elsie);
			}
		}
	}	
}

int main() {
	ifstream fin("meeting.in");
		fin >> N >> M;
		cout << N << endl;
		cout << endl;
		for (int i = 0; i < M; i++) {
			fin >> A >> B >> C >> D;
			paths.pb(mp(A,B));
			speeds.pb(mp(C,D));
		}		
	fin.close();
	calculatePaths();
	for (int i = 0; i < bessieSpeeds.size(); i++) {
		cout << "Bessie: " << bessieSpeeds[i] << endl;	
		cout << elsieSpeeds[i] << endl;
	}

	for (int i = 0; i < bessieSpeeds.size(); i++) {
		if (bessieSpeeds[i] > leastTime) break;
		for (int j = 0; j < elsieSpeeds.size(); j++) {
			if (bessieSpeeds[i] == elsieSpeeds[j]) {
				if (bessieSpeeds[i] < leastTime) {
					leastTime = bessieSpeeds[i];
					break;
				}
			}
		}
	}	

	ofstream fout("meeting.out");
		cout << leastTime << endl;
		if (leastTime != 1000000) {
			fout << leastTime << endl;
		} else fout << "IMPOSSIBLE" << endl;
	fout.close();
	return 0;
}
