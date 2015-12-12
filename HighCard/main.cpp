#include <stdio.h>
#include <vector>

#define MAX_N 50000

typedef std::vector<int> VI;

int N;
int cards[MAX_N * 2 + 1];
VI bessie, elsie;

int points;

int find_closest(int x) {
	for (int i = 0; i < bessie.size(); i++) {
		if (bessie[i] > x) return i;
	}
	return -1;
}

int main() {
	bessie = VI();
	elsie = VI();
	points = 0;

	FILE *in = fopen("highcard.in", "r");
	fscanf(in, "%d", &N);
	for (int i = 0; i < N; i++) {
		int card;	
		fscanf(in, "%d", &card);
		elsie.push_back(card);
		cards[card] = -1;
	}
	for (int i = 1; i <= N * 2; i++) {
		if (cards[i] != -1) bessie.push_back(i);
	}
	fclose(in);

	for (int i = 0; i < N; i++) {
		printf("Elsie Plays: %d\n", elsie[i]);
		int index = find_closest(elsie[i]);
		printf("Bessie Plays: %d\n", index != -1 ? bessie[index] : bessie[0]);
		if (index == -1) {
			bessie.erase(bessie.begin());
		} else {
			bessie.erase(bessie.begin() + index);
			points++;
		}
	}
	printf("%d\n", points);

	FILE *out = fopen("highcard.out", "w");
	fprintf(out, "%d\n", points);
	fclose(out);
	return 0;
}
