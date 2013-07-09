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
int t[2*SZ]; //!< the sortted index of p
int len = 0; //!< length of p, t, s

int s[2*SZ] = { 0 }; //!< set the i-th point belongs to
int c = 0; //!< the total sets count.

int x1, z1, x2, y2;

/**
   @brief compare point(a,b) and point(x,y)

   @param a 
   @param b 
   @param x 
   @param y 
   @return if equal, return 0; big 1; else -1;
   */
int compare(int a, int b, int x, int y)
{
  if (a == x) {
    return b - y;
  }
  return a - x;
}


/**
   @brief insert point(x,y) to p in positon psn.
   make sure t is sorted.
   
   @param x 
   @param y 
   @param psn 
   */
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


/**
   @brief binary search point(x,y)

   @param low 
   @param up 
   @param x 
   @param y
   @return if cannot find ,insert the point and return -1; 
   else return the set of the point.
   */
int bs(int low, int up, int x, int y) 
{
  if (low > up) {
    insert(x, y, low);
    return -1;
  }
  if (low == up) {
      int r = compare(p[0][t[low]], p[1][t[low]], x, y);
      if (r == 0) {
	return s[low];
      }
      else if (r > 0) {
	insert(x, y, low);
	return -1;
      }
      else {
	insert(x, y, low+1);
	return -1;
      }
  }
  int mid = (up + low) / 2;
  int r = compare(p[0][t[mid]], p[1][t[mid]], x, y);
  if (r == 0) {
    return s[mid];    
  }
  else if (r > 0) {
    return bs(low, mid-1, x, y);
  }
  else {
    return bs(mid+1, up, x, y);
  }
}

int main ()
{
  scanf("%d", &m);
  for (n=1; n<=m; ++n) {
    scanf("%d%d%d%d", &x1, &z1, &x2, &y2);
    int u = bs(0, len-1, x1, z1);
    int v = bs(0, len-1, x2, y2);

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
  

