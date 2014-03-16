#include <stdio.h>
#include <string.h>
#include <stdlib.h>

enum {S = 101};

int n, m;
char a[S][S] = { 0 };
char visited[S] = { 0 };
int ans[S];

int cmp (const void * a, const void * b)
{
  return ans[*(char*)a] - ans[*(char *)b];
}

int main()
{
  #ifndef ONLINE_JUDGE
  //freopen("in", "r",stdin);
  #endif
  
  //input
  int p, q;
  scanf("%d%d", &n, &m);
  while(m--) {
    scanf("%d%d", &p, &q);
    a[p][q] = 1;
  }
  
  // in-degree 
  for (p=1; p<=n; ++p) {
    for (q=1; q<=n; ++q) {
      if (a[p][q]) ++a[0][q];
    }
  }
  
  //solve
  for (m=1; m<=n; ++m) {
    // find a node that has an in-degree of zero.
    for (p=1; p<=n; ++p) {
      if (a[0][p]==0 && !visited[p]) break;
    }

    if (p > n) { //can't find, No solution
      printf("No solution\n");
      return 0;
    }
    //or, find one at the start, clear it.
    ans[m] = p;
    visited[p] = 1;
    for (q=1; q<=n; ++q) {
      if (a[p][q]) --a[0][q];
    }  
  }

  for (p=1; p<=n; ++p) visited[p] = p;
  qsort(visited+1, n, sizeof(char), cmp);
  for (p=1; p<=n; ++p) printf("%d ", visited[p]);
  putchar('\n');
  return 0;
}
