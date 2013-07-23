/**
   @file 
   @brief my solution for problem 199 on SGU OJ 
   @date  2013-07-19
   @version 1.0
   @author ck <chengkechengke@gmail.com>

   @section Description 
   - the complexity is n*log(n)
   - if si<sb,bi<bj, we say the i-th member is smaller than j-th.
   - sort all the members, find the longest subsequence in which the
     adjacent two has the 'smaller' relationship.

   1. sort all of the members -- use index sort, the s in acscend order
      while b in descend order.
   2. find the longest increasing subsequence(LIS) in sorted b.
   
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
int v[S] = { 0 }; //!< v[i] means the min last value in all of the LIS
                  //!  with length i 
int pre[S] = { 0 }; 
int len = 0; //!< the length of array v.


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
    return m[b1].b - m[a1].b;
  }
  return m[a1].s - m[b1].s;
}

void b_search(int low, int up, int k) {
  int mid;
  while (up-low > 1) {
    mid = (up + low) >> 1;
    if (m[k].b > m[v[mid]].b) {
      low = mid;
    }
    else if (m[k].b == m[v[mid]].b) {
      up = low = mid;
    }
    else {
      up = mid;
    }
  }

  v[up] = k;
  pre[k] = v[up-1];
}

int main()
{
  int i;
  scanf("%d", &n);
  for (i=1; i<=n; ++i) {
    scanf("%d%d", &m[i].s, &m[i].b);
    idx[i] = i;
  }
  
  qsort(idx+1, n, sizeof(int), cmp);
  
  v[1] = idx[1];
  len = 1;
  for (i=1; i<=n; ++i) {
    if (m[v[len]].b < m[idx[i]].b) {
      v[len+1] = idx[i];
      pre[idx[i]] = v[len];
      ++len;
    }
    else if (m[v[1]].b >= m[idx[i]].b) {
      v[1] = idx[i];
    }
    else {
      b_search(1, len, idx[i]);
    }
  }
  
  printf("%d\n", len);
  for (i=v[len]; i>0; i=pre[i]) {
    printf("%d ", i);
  }
  putchar('\n');
  return 0;
}

