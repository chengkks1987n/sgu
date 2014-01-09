#include <stdio.h>
#include <string.h>

enum {S = 101};

int n, m;
char a[S][S] = { 0 };
char flag[S];
int ans[S];

int mark_forword(int cur, int* gt) {
  int i;
  for (i=1; i<=n; ++i) {
    if (a[cur][i]) {
      if (flag[i]==0) {
	flag[i] = 1;
	++(*gt);
	mark_forword(i, gt);
      }
      else if (flag[i] != 1) {
	return 0;
      }
    }
  }
  return 1;
}

int mark_backword(int cur, int* lt) {
  int i;
  for (i=1; i<=n; ++i) {
    if (a[i][cur]) {
      if (flag[i]==0) {
	flag[i] = -1;
	++(*lt);
	mark_backword(i, lt);
      }
      else if (flag[i] != -1) {
	return 0;
      }
    }
  }
  return 1;
}

int solve(int left, int right)
{
  if (left >= right) return 1;
  
  //init
  memset(flag, 0, sizeof(flag));
  flag[ans[left]] = 2;

  //mark forword
  int gt = 0;
  if (!mark_forword(ans[left], &gt)) return 0;
  
  //mark backword
  int lt = 0;
  if (!mark_backword(ans[left], &lt)) return 0;
  
  //check
  if (gt + lt != right - left) return 0;

  //sort
  int mid = left+lt;
  int tmp = ans[mid];
  ans[mid] = ans[left];
  ans[left] = tmp;
  
  int i = left;
  int j = mid+1;
  while (1) {
    while (ans[i]<0 && i<mid) ++i;
    while (ans[j]>0 && j<=right) ++j;
    if (i<mid && j<=right) {
      tmp = ans[i];
      ans[i] = ans[j];
      ans[j] = tmp;
      ++i;
      ++j;
    }
    else break;
  }
  
  for (i=1; i<=n; ++i) {
    a[i][ans[left]] = a[ans[left]][i] = 0;
  }

  return solve(left, mid-1) && solve(mid+1, right);
}

int main()
{
  #ifndef ONLINE_JUDGE
  freopen("in", "r",stdin);
  #endif

  int p, q;

  scanf("%d%d", &n, &m);
  while(m--) {
    scanf("%d%d", &p, &q);
    a[p][q] = 1;
  }
  for (p=0; p<=n; ++p) ans[p] = p;

  if (solve(1, n)) {
    for (p=1; p<=n; ++p) printf("%d ", ans[p]);
    putchar('\n');
  }
  else {
    printf("No solution\n");
  }
  return 0;
}
