#include <stdio.h>>
#define MAX_N 1000

int next[MAX_N+1];
int non_loopy[MAX_N+1];  

int main(void)
{
  int count, i, j, N;

  freopen ("relay.in", "r", stdin);
  freopen ("relay.out", "w", stdout);

  scanf ("%d", &N);
  for (i=1; i<=N; i++) {
    scanf ("%d", &next[i]);
    if (next[i] == 0) 
      non_loopy[i] = 1;
  }

  for (i=1; i<=N; i++)
    for (j=1; j<=N; j++)
      if (non_loopy[next[j]]) 
	non_loopy[j] = 1;
  
  for (i=1; i<=N; i++)
    count += non_loopy[i];

  printf ("%d\n", count);
  return 0;
}
