/**
   @file 
   @brief my solution to problem 188 on sgu oj
   @date 2013-07-15
   @version 1.0
   @author ck <chengkechengke@gmail.com>

   @section Description 
   
   */

#include <stdio.h>
#include <stdlib.h>


#define P 1000    //!<  perimeter
#define MAX_N 20

int n, t;
int L[MAX_N], v[MAX_N];
int a[MAX_N] = { 0 }; //!< the answers

int i, j, tmp;


/**
   @brief how many times the x-th soldier metet the y-th soldier

   @param x 
   @param y 
   @return 
   */
int between(int x, int y) {
  double len  = abs(L[x] - L[y]);
  if ((L[x]<L[y] && v[x]<0) || (L[x]>L[y] && v[x]>0)) {
    len = P - len;
  }
  double vxy = abs(v[x] - v[y]);
  double t1 = len / vxy;
  int ans = 0;
  if (t >= t1) {
    ++ans;
    t1 = t - t1;
  }
  else {
    return 0;
  }
  double t2 = P / vxy;
  while (t1 >= t2) {
    ++ans;
    t1 -= t2;
  }

  return ans;
}

int main() 
{
  scanf("%d%d", &n, &t);
  for (i=0; i<n; ++i) {
    scanf("%d", &L[i]);
  }
  for (i=0; i<n; ++i) {
    scanf("%d", &v[i]);
  }

  for (i=0; i<n-1; ++i) {
    for (j=i+1; j<n; ++j) {
      if ((v[i]>0 && v[j]<0) || (v[i]<0 && v[j]>0)) {
	tmp = between(i, j);
	a[i] += tmp;
	a[j] += tmp;
      }
    }
  }    
  
  for (i=0; i<n; ++i) {
    printf("%d ", a[i]);
  }
  return 0;
}
