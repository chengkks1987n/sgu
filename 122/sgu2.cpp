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
int next[SIZE], start, tail, len;

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

void find_one_path() 
{
  start = tail = 1;
  int v ;
  int i;
  bool over = false;
  //forword
  v = 1;
  visited[1] = true;
  len = 1;
  while (!over) {
    over = true;
    for (i=0; i<g[v].size(); ++i) {
      if (!visited[g[v][i]]) {
	tail = g[v][i];
	next[v] = tail;
	visited[tail] = true;
	++len;
	v = tail;
	over = false;
	break;
      }
    }
  }

  //back
  v = 1;
  over = false;
  while (!over) {
    over = true;
    for (i=0; i<g[v].size(); ++i) {
      if (!visited[g[v][i]]) {
	start = g[v][i];
	next[start] = v;
	visited[start] = true;
	++len;
	v = start;
	over = false;
	break;
      }
    }
  }
}

void output() 
{
  int v ;
  for (v=1; v!=tail; v=next[v]) {
    cout << v << " ";
  }
  cout << tail << " ";
  for (v=start; v!=1; v=next[v]) {
    cout << v << " ";
  }
  cout << 1 << endl;
}

void find_node_outside_path(int &z, int &k)
{
  int i, j;
  for (i=1; i<=n; ++i) {
    if (!visited[i]) {
      for (j=0; j<g[i].size(); ++j) {
	if (visited[g[i][j]]) {
	  z = i;
	  k = g[i][j];
	  return;
	} 
      }
    }
  }
}

void extend_path(int z, int k)
{
  next[tail] = start;
  next[z] = k;
  visited[z] = true;
  ++len;
  start = z;
  tail = start;
  while (next[tail] != k) tail = next[tail];
}

void find_loop_node(int& k) 
{
  k = next[start];
  while (k != tail) {
    if (is_adj(k, tail) && is_adj(next[k], start)) {
      return;
    }
  }
}

void path2loop(int k) 
{
  int v = next[k];
  int pre[SIZE], sp, tp;
  sp = tail;
  tp = v;
  while (next[v] != tail) {
    pre[next[v]] = v;
    v = next[v];
  }
  pre[tail] = v;

  next[k] = sp;
  tail = tp;
  v = sp;
  while (v != tp) {
    next[v] = pre[v];
    v = pre[v];
  }
}

void solve() 
{
  find_one_path();
  
  while (true) {
    if (is_adj(start, tail)) {
      if (len == n) {
	output();
	return;
      }
      else {
	int z, k;
	find_node_outside_path( z, k);
	extend_path(z, k);
      }
    }
    else {
      int k;
      find_loop_node( k);
      path2loop( k);
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
