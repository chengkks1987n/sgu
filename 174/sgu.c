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
int n; //!< current wall NO. 
int p[2][2*SZ] ; //!< all of the end points of walls.
int len = 0; //!< length of p, s

int s[2*SZ] = { 0 }; //!< which set the i-th point belongs to
int c = 0; //!< the total sets count.

int x1, z1, x2, y2;

/**
   @brief find which set the point(x,y) belong to, if cannot find,
   add the point and return -1;

   @param x 
   @param y 
   @return 
   */
int find(int x, int y) 
{
  int i;
  for (i=0; i<len; ++i) {
    if (p[0][i]==x && p[1][i]==y) {
      return s[i];
    }
  }
  p[0][len] = x;
  p[1][len] = y;
  ++len;
  return -1;
}

int main ()
{
  scanf("%d", &m);
  for (n=1; n<=m; ++n) {
    scanf("%d%d%d%d", &x1, &z1, &x2, &y2);
    int u = find(x1, z1);
    int v = find(x2, y2);

    if (u == v) {
      if (u != -1) {
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
      if (u == -1) {
	s[len-1] = v;
      }
      else if (v == -1) {
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
  

