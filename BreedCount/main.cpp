#include <stdio.h>
#include <vector>

#define MAX_N 100000

int N, Q;

int counts[MAX_N + 2][3];

int main() {
	FILE *in = fopen("bcount.in", "r");
	fscanf(in, "%d %d", &N, &Q);

	counts[0][0] = 0;
	counts[0][1] = 0;
	counts[0][2] = 0;

	for (int i = 1; i <= N; i++) {
		int breed;
		fscanf(in, "%d", &breed);
		for (int j = 0; j < 3; j++) {
			counts[i][j] = counts[i - 1][j];
		}
		counts[i][breed - 1] += 1;
	}
	for (int i = 0; i <= N; i++) {
		for (int j = 0; j < 3; j++) {
			printf("%d ", counts[i][j]);
		}
		printf("\n");
	}
	FILE *out = fopen("bcount.out", "w");
	for (int i = 0; i < Q; i++) {
		int low, high;
		fscanf(in, "%d %d", &low, &high);
		printf("%d %d %d\n", 
				counts[high][0] - counts[low - 1][0],
				counts[high][1] - counts[low - 1][1],
				counts[high][2] - counts[low - 1][2]);
		fprintf(out, "%d %d %d\n", 
				counts[high][0] - counts[low - 1][0],
				counts[high][1] - counts[low - 1][1],
				counts[high][2] - counts[low - 1][2]);
	}
	fclose(in);
	fclose(out);
	return 0;
}
