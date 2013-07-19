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

int idx[S]; //!< used to index sort.

int len[S] = { 0 };
int next[S] = { 0 };
int visited[S];

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

void dfs(int a) {
  if (!visited[a]) {
    int i;
    for (i=a-1; i>=1; --i) {
      if (m[idx[i]].s<m[idx[a]].s && m[idx[i]].b<m[idx[a]].b) {
        if (!visited[i]) {
          dfs(i);
        }
        if (len[i]+1 > len[a]) {
          len[a] = len[i]+1;
          next[a] = i;
        }
      }
    }
    visited[a] = 1;
  }
}


int main()
{
  int i, j;
  scanf("%d", &n);
  for (i=1; i<=n; ++i) {
    scanf("%d%d", &m[i].s, &m[i].b);
    idx[i] = i;
  }
  
  qsort(idx+1, n, sizeof(int), cmp);
  
  j = 1;
  for (i=n; i>=1; --i) {
    dfs(i);
    if (len[i] > len[j]) {
      j = i;
    }
  }
  
  printf("%d\n", len[j]+1);
  for (i=j; i>0; i=next[i]) {
    printf("%d ", idx[i]);
  }
  putchar('\n');
  return 0;
}
