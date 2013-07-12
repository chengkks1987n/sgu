/**
   @file
   @brief hashtable version.
   @date 2013-07-11
   @version 1.0
   @author ck

   @section Description

   the complexity is N*lgN.

   use map to store the end points of walls, key is the point,
   value is a index;
   user array to represent the sets, s[i] = j(i != j) mean that the
   i-th point  and j-th point are in the same set, s[i] = i mean that
   the i-th point is in set i.
   the Complexity of union two sets on time is constant,so as to find.

   key point: a effective representaton of sets, the elements in same set
   are link to the set id, the length is 2 or 3 at most.

   use printf/scanf rather than cin/cout.

   ref: http://hi.baidu.com/zyz913614263/item/991b9cb288985257ba0e1215
   */

#include <cstdio>
#include <map>
using namespace std;

const int SIZE = 200001;

int m;
map<pair<int,int>, int> p;
pair<map<pair<int,int>,int>::iterator,bool> r1, r2;
int s[SIZE<<1];
int a, b, c, d, i;

/**
   @brief find which set the a-th point belong to
   complexity is constant
   during the find process, you the short the link path to 2.

   @param a 
   @return 
   */
int find(int a) {
  if (s[a] == a) {
    return a;
  }
  return (s[a] = find(s[a]));
}

int main()
{
  scanf("%d", &m);
  for (i=0; i<(m<<1); ++i) {
    s[i] = i;
  }
  for (i=1; i<=m; ++i) {
    scanf("%d%d%d%d", &a, &b, &c, &d);
    r1 = p.insert(make_pair(make_pair(a,b),-1));
    if (r1.second) { // p1 is not in any sets
      r1.first->second = p.size() - 1;
    }
    a = find(r1.first->second);
    r2 = p.insert(make_pair(make_pair(c,d),-1));
    if (r2.second) { // p2 is not in any sets
      r2.first->second = p.size() - 1;
    }
    b = find(r2.first->second);

    if (a == b) {
      printf("%d\n", i);
      return 0;
    }
    else {
      s[a] = b;
    }
  }

  puts("0");
  return 0;
}
