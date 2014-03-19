#include <stdio.h>
#include <string.h>

int n = 0;
char a[10002] = "";
int m = 2;
int i, j;
int main() {
  scanf("%d", &n);
  memset(a, 2, n+1);
  a[1] = 1;

  if (n == 1)  m = 1;

  for (i=2; i<=n/2; ++i) {
    for (j=2; j<=i && i*j<=n; ++j) {
      if (a[i]+1 > a[i*j]) a[i*j] = a[i] + 1;
      if (a[i]+1 > m) m = a[i] + 1;
    }
  }

  printf("%d\n", m);
  for (i=1; i<=n; ++i) {
    printf("%d ", a[i]);
  }
  putchar('\n');
  return 0;
}
