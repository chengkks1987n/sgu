#include <stdio.h>

#define MAX 51

int n, x;
int a[MAX][MAX] = { 0 };
int b[MAX] = { 0 };
int s[MAX], sp = 0;
int visited[MAX] = { 0 };
int i, j;

int main() {
  scanf("%d%d", &n, &x);
  for (i=1; i<=n; ++i) {
    scanf("%d", &a[i][0]);
    for (j=1; j<=a[i][0]; ++j) {
      scanf("%d", &a[i][j]);
    }
  }
  
  visited[x] = 1;
  b[x] = -1;
  for (i=1; i<=a[x][0]; ++i) {
    s[sp++] = a[x][i];
    b[a[x][i]] = -1;
  }

  while (sp > 0) {
    j = s[--sp];
    if (visited[j]) continue;

    for(i=1; i<=a[j][0]; ++i) {
      if (b[a[j][i]] == 0){
	b[a[j][i]] = 1;
	++b[0];
      }
      if (!visited[a[j][i]]) s[sp++] = a[j][i];
    }
    visited[j] = 1;
  }

  printf("%d\n", b[0]);
  for (i=1; i<=n; ++i) {
    if (b[i]==1) printf("%d ", i);
  }
  putchar('\n');
  return 0;
}
