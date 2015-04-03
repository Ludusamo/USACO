#include <stdio.h>

int N;

int main() {
	FILE *input = fopen("superbull.in", "r");
		fscanf(input, "%d", &N);
		printf("%d\n", N);
	fclose(input);
	return 0;
}
