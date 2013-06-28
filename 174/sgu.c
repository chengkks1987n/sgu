/**
   @file 
   @brief my solution on SGU OJ problem 174 
   @date 2013-06-27
   @version  1.0
   @author ck <chengkechengke@gmail.com>

   @section Description 
   
   # put the linked walls in the same set. when comming a new wall :
   if its two ends are in the same set, return this wall;
   if they are not in any sets, put the wall in a new set;
   if the are in different sets, union the two sets;
   if only one of them is in a set, put the wall in this set.
   # the keys are :
    - inset new wall;
    - search which set the new wall's ends are belong to;
   */

#include <stdio.h>

#define SZ 200001

int m;
int n;
int p[2][2*SZ] ;
int t[2*SZ];
int len = 0;

int s[2*SZ] = { 0 };
int c = 0;

int x1, z1, x2, y2;

int compare(int a, int b, int x, int y)
{
  if (a == x) {
    return b - y;
  }
  return a - x;
}

void insert (int x, int y, int psn) {
  p[0][len] = x;
  p[1][len] = y;
  int i = len;
  while (i > psn) {
    t[i] = t[i-1];
    --i;
  }
  t[psn] = len;
  ++len;
}

int bs(int low, int up, int x, int y, int* psn) 
{
  *psn = low;
  int r1 = compare(p[0][t[low]], p[1][t[low]], x, y);
  int r2 = compare(p[0][t[up]], p[1][t[up]], x, y);
  if (r1>0) {
    *psn = low;
    return 0;
  }
  if (r2<0) {
    *psn = up + 1;
    return 0;
  }
  while (low <= up) {
    if (up - low == 1) {
      *psn = up;
    }
    r1 = (up + low) / 2;
    r2 = compare(p[0][t[r1]], p[1][t[r1]], x, y);
    if (!r2) {
      return s[r1];
    }
    if (r2 > 0) {
      up = r1 - 1;
    }
    else {
      low = r1 + 1;
    }    
  }
  
  return 0;
}

int main ()
{
  scanf("%d", &m);
  for (n=1; n<=m; ++n) {
    scanf("%d%d%d%d", &x1, &z1, &x2, &y2);
    int p1, p2;
    int u = bs(0, len-1, x1, z1, &p1);
    if (!u) { insert(x1, z1, p1); }
    int v = bs(0, len-1, x2, y2, &p2);
    if (!v) { insert(x2, y2, p2); }

    if (u == v) {
      if (u != 0) {
	printf("%d\n", n);
	return 0;
      }
      else {
	++c;
	s[len-2] = c;
	s[len-1] = c;
      }
    }
    else {
      if (u == 0) {
	s[len-1] = v;
      }
      else if (v == 0) {
	s[len-1] = u;
      }
      else {
	int i;
	for (i=0; i<len; ++i) {
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
  

