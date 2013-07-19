/**
   @file 
   @brief my solution for problem 199 on SGU OJ 
   @date  2013-07-19
   @version 1.0
   @author ck <chengkechengke@gmail.com>

   @section Description 
   1. sort all of the members -- use index sort.
   2. for k = n to 1
          find a member j (j>k) who do not hate k
          if cannt find let len[k] = 1, next[k] = -1;
          else let len[k] = len[j] + 1, next[k] = j;
   3. the one that has the max len is the answer, go through next,
      find the member.
   */

#include <stdio.h>
#include <stdlib.h>

#define S 100002

struct SB {
  int s;
  int b;
} m[S];
int n;

int len[S] ;
int next[S] ;
int idx[S]; //!< used to index sort.
int max_value = 1;
int max_idx = 1;
int i, j;

/**
   @brief used to index sort.

   @param a 
   @param b 
   @return 
   */
int cmp (const void* a, const void* b) {
  int a1 = *(int*)a;
  int b1 = *(int*)b;
  if (m[a1].s == m[b1].s) {
    return m[a1].b - m[b1].b;
  }
  return m[a1].s - m[b1].s;
}

int main()
{
  scanf("%d", &n);
  for (i=1; i<=n; ++i) {
    scanf("%d%d", &m[i].s, &m[i].b);
    idx[i] = i;
  }
  
  qsort(idx+1, n, sizeof(int), cmp);

  for (i=n; i>=1; --i) {
    for (j=i+1; j<=n; ++j) {
      if (m[idx[i]].s<m[idx[j]].s && m[idx[i]].b<m[idx[j]].b) {
        break;
      }
    }
    if (j > n) {
      next[i] = -1;
      len[i] = 1;
    }
    else {
      next[i] = j;
      len[i] = 1 + len[j];
      if (max_value < len[i]) {
        max_value = len[i];
        max_idx = i;
      }
    }    
  }
  
  printf("%d\n", max_value);
  for (i=max_idx; i!=-1; i=next[i]) {
    printf("%d ", i);
  }
  putchar('\n');
  return 0;
}
