#include <algorithm>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>

using namespace std;

const int SIZE = 1002;
int n;
vector<int> g[SIZE];  //the graph, representation by adjacency list
bool visited[SIZE] = {false};
int index[SIZE] = { 0 }; //index[a] means the next child node of a, that will be visited.

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
int next(int a)
{
  /*  vector<int>::iterator it;
  it = find(g[a].begin(), g[a].end(), b);
  ++it;
  if (it == g[a].end()) {
    return -1;
  }
  else {
    return *it;
    }*/
  int ans = -1;
  if (index[a] < g[a].size()) {
    ans = g[a][index[a]];
    ++index[a] ;
  }
  
  return ans;
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
/*int is_ok(int v, vector<int> s)
{
  vector<int>::iterator it;
  it = find(s.begin(), s.end(), v);
  if (it != s.end()) {
    return -1;
  }
  else {
    if (s.size() == n - 1) {
      return 0;
    }
    return 1;
  }
  }*/

/***************************
description:
 - find answer use dfs.
 ************************/
void dfs()
{
  int v = 1;
  vector<int> &s = g[0];
  while(true) {
    if (v <= 0) {
      if (s.size() < 2){
	cout << "No solution" << endl;
	return;
      }
      else {
	int e = s.back();
	s.pop_back();
	visited[e] = false;
	index[e] = 0;
	int a = s.back();
	v = next(a);
      }
    }
    else {
      if (visited[v]) {
	v = next(s.back());
      }
      else if (s.size() == n - 1) {
	int i;
	for (i=0; i<s.size(); ++i) {
	  cout << s[i] << " ";
	}
	cout << v << " " << 1 << endl;
	return;
      }
      else {
	s.push_back(v);
	visited[v] = true;
	v = next(v);
      }
    }
  }
}

int main() 
{
  read();
  dfs();
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
