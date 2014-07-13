#include <stdio.h>

#define MAX 51

int n, x;
int a[MAX][MAX] = { 0 };
int b[MAX] = { 0 };
int i, j, d;

int main() {
  scanf("%d%d", &n, &x);
  for (i=1; i<=n; ++i) {
    scanf("%d", &a[i][0]);
    for (j=1; j<=a[i][0]; ++j) {
      scanf("%d", &d);
      a[d][i] = a[i][d] = 1;
    }
  }
  
  for (i=1; i<=n; ++i) 
    for (j=1; j<=n; ++j) {
      if (!b[j] && x!=i && i!=j && x!=j && a[x][i] && a[i][j] && !a[x][j]) {
	++b[0];
	b[j] = 1;
      }
    }

  printf("%d\n", b[0]);
  for (i=1; i<=n; ++i) {
    if (b[i]) printf("%d ", i);
  }
  putchar('\n');
  return 0;
}
