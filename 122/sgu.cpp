#include <algorithm>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>

using namespace std;

const int SIZE = 1002;
int n;
vector<int> g[SIZE];  //the graph, representation by adjacency list

/*************************
description:
 - read input
***********************/
void read()
{
  string str;  
  getline(cin, str);
  istringstream sin(str);
  sin >> n;
  int i, a;
  
  for (i=1; i<=n; ++i) {
    getline(cin, str);
    istringstream sin(str);
    while (sin >> a){
      g[i].push_back(a);
    }
  }
}

/****************
description:
 - find node a's child after its child b
input:
 a - the father node
 b - a's child node
output:
 - if b is the last child of a, return -1;
 - else return a's child node after b
*****************/
int next(int a, int b)
{
  vector<int>::iterator it;
  it = find(g[a].begin(), g[a].end(), b);
  ++it;
  if (it == g[a].end()) {
    return -1;
  }
  else {
    return *it;
  }
}

/****************************************
description: 
 - is it ok to visit the node v, s is the visited nodes
input:
 v - current visit node
 s - nodes has been visited
output:
 - if add v to st is the answer, return 0;
 - if v is in st, return -1;
 - if v is not in st, return 1;
***************************************/
int is_ok(int v, vector<int> s)
{
  vector<int>::iterator it;
  it = find(s.begin(), s.end(), v);
  if (it != s.end()) {
    return -1;
  }
  else {
    if (s.size() == n -1) {
      return 0;
    }
    return 1;
  }
}

/***************************
description:
 - find answer use dfs.
 ************************/
void dfs(int v, vector<int> s)
{
  if (v <= 0) {
    if (s.size() < 2){
      cout << "No solution" << endl;
      return;
    }
    else {
      int e = s.back();
      s.pop_back();
      int a = s.back();
      dfs (next(a, e), s);
    }
  }
  else {
    int r = is_ok(v, s);
    if (r > 0) {
      s.push_back(v);
      dfs(g[v][0], s);
    }
    else if (r == 0) {
      int i;
      for (i=0; i<s.size(); ++i) {
	cout << s[i] << " ";
      }
      cout << v << " " << 1 << endl;
      return;
    }
    else {
      dfs(next(s.back(), v), s);
    }
  }
}

int main() 
{
  read();
  dfs(1, g[0]);
  return 0;
}

/* test cases
4
2 3
1 4
1 4
2 3
1 3 4 2 1

5
2 3 4
1 5
1 5
1 5
2 3 4

 */
