#include <algorithm>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <fstream>

using namespace std;

const int SIZE = 1002;
int n;
vector<int> g[SIZE];  //graph representation by adjacency list
bool visited[SIZE] = { false };  

/*************************
description:
 - read input
***********************/
void read()
{
  #ifndef ONLINE_JUDGE
  ifstream fin;
  fin.open("in.txt");
  cin.rdbuf(fin.rdbuf());
  #endif

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


bool is_adj(int a, int b)
{
  vector<int>::iterator it;
  it = find(g[a].begin(), g[a].end(), b);
  if (it != g[a].end()) {
    return true;
  }
  
  return false;
}

void find_one_path(vector<int> &p) 
{
  p.clear();
  int node, i;
  for (node=1; !visited[node];){
    p.push_back(node);
    visited[node] = true;
    for (i=0; i<g[node].size(); ++i) {
      if (!visited[g[node][i]]) {
	node = g[node][i];
	break;
      }
    }
  }
}

void output(vector<int> &p) 
{
  vector<int>::iterator start, it;
  start = find(p.begin(), p.end(), 1);
  for (it=start; it!=p.end(); ++it) {
    cout << *it << " ";
  }
  for (it=p.begin(); it!=start; ++it) {
    cout << *it << " ";
  }
  cout << 1 << endl;
}

void find_node_outside_path(vector<int> &p, int &z, int &k)
{
  int i;
  for (k=0; k<p.size(); ++k) {
    for (i=0; i<g[p[k]].size(); ++i) {
      if (!visited[g[p[k]][i]]) {
	z = g[p[k]][i];
	visited[z] = true;
	return;
      }
    }
  }
}

void extend_path(vector<int> &p, int z, int k)
{
  reverse(p.begin(), p.begin()+k);
  reverse(p.begin()+k, p.end());
  p.push_back(z);
}

void find_loop_node(vector<int> &p, int& k) 
{
  for (k=1; k<p.size()-1; ++k) {
    if (is_adj(p.front(), p[k]) && is_adj(p[k-1], p.back())) {
      return;
    }
  }
}

void path2loop(vector<int>& p, int k) 
{
  reverse(p.begin()+k, p.end());    
}

void solve() 
{
  vector<int> &path = g[0];
  find_one_path(path);
  
  while (true) {
    if (is_adj(path.front(), path.back())) {
      if (path.size() == n) {
	output(path);
	return;
      }
      else {
	int z, k;
	find_node_outside_path(path, z, k);
	extend_path(path, z, k);
      }
    }
    else {
      int k;
      find_loop_node(path, k);
      path2loop(path, k);
    }
  }
}

int main() 
{
  read();
  solve();
  return 0;
}

/* test cases
4
2 3
1 4
1 4
2 3
1 3 4 2 1

6
2 3 5
1 3 6
1 2 4
3 5 6
1 4 6
2 4 5
 */
