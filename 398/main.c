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
      if (x!=i && x!=j && i!=j && a[x][i] && a[i][j] && !a[x][j]) {
	b[++b[0]] = j;
      }
    }

  printf("%d\n", b[0]);
  for (i=1; i<=b[0]; ++i) {
    printf("%d ", b[i]);
  }
  putchar('\n');
  return 0;
}
