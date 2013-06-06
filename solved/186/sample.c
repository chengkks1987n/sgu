#include <stdio.h>
#include <stdlib.h>

int n;
int L[101];

int cmp(const void* a, const void* b) 
{
  int aa = *(int*)a;
  int bb = *(int*)b;
  return aa - bb;
}

int main()
{
  scanf("%d", &n);
  int i;
  for (i=0; i<n; ++i) {
    scanf("%d", &L[i]);
  }

  qsort(L, n, sizeof(int), cmp);

  int ans = 0;
  int s = 0;
  int e = n - 1;

  while (s < e) {
    if (s == e - 1) {
      ++ans;
      break;
    }
    else if (L[s] > 0) {
      ++ans;
      --L[s];
      --e;
      if (L[s] == 0) {
	++s;
      }
     }
  }
  printf("%d\n", ans);
  return 0;
}
