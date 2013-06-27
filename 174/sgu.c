/**
   @file 
   @brief my solution on SGU OJ problem 174 
   @date 2013-06-27
   @version  1.0
   @author ck <chengkechengke@gmail.com>

   @section Description 

   */

#include <stdio.h>

#define SZ 200001

int m, n;
int p[4][SZ] ;

int s[SZ] = { 0 };
int c = 0;

int u, v;

void find() {
  u = 0;
  v = 0;
  int i;
  for (i=1; i<n; ++i) {
    if ((p[0][i]==p[0][n] && p[1][i]==p[1][n]) ||
	(p[2][i]==p[0][n] && p[3][i]==p[1][n])) {
      u = s[i];
      break;
    }
  }
  for (i=1; i<n; ++i) {
    if ((p[0][i]==p[2][n] && p[1][i]==p[3][n]) ||
	(p[2][i]==p[2][n] && p[3][i]==p[3][n])) {
      v = s[i];
      break;
    }
  }
}

int main ()
{
  scanf("%d", &m);
  for (n=1; n<=m; ++n) {
    scanf("%d%d%d%d", &p[0][n], &p[1][n], &p[2][n], &p[3][n]);
    find();
    if (u == v) {
      if (u != 0) {
	printf("%d\n", n);
	return 0;
      }
      else {
	++c;
	s[n] = c;
      }
    }
    else {
      if (u == 0) {
	s[n] = v;
      }
      else if (v == 0) {
	s[n] = u;
      }
      else {
	s[n] = u;
	int i;
	for (i=1; i<n; ++i) {
	  if (s[i] == v) {
	    s[i] = u;
	  }
	}
      }
    }
  }
    
  puts("0");
  return 0;
}
  

