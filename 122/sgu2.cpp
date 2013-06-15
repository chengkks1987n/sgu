#include <iostream>
#include <sstream>
#include <string>
#include <fstream>

using namespace std;

const int SIZE = 1002;
bool adj[SIZE][SIZE] = { {false} };
bool visited[SIZE] = { false };  
int n, pre[SIZE], next[SIZE], start, tail, len;

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
      adj[a][i] = true; 
      adj[i][a] = true;
    }
  }
}

int find_unvisited_child(int v) {
  int i = 1;
  for (; i<=n; ++i) {
    if (adj[v][i] && !visited[i]) {
      return i;
    }
  }
  return 0;
}

int find_visited_child(int v) {
  int i = start;
  while (i != tail) {
    if (adj[v][i]) return i;
  }
  if (adj[v][tail]) return tail;
  return 0;
}

void find_one_path() 
{
  len = start = tail = 1;
  visited[1] = true;
  //forword
  int u, v = 1;
  while ((u=find_unvisited_child(v)) != 0) {
    next[v] = u;
    pre[u] = v;
    ++len;
    visited[u] = true;
    v = u;
    tail = u;
  }
  //back
  v = 1;
  while((u=find_unvisited_child(v)) != 0) {
    next[u] = v;
    pre[v] = u;
    ++len;
    visited[u] = true;
    v = u;
    start = u;
  }
}

void output() 
{
  int v = 1;
  do {
    cout << v << " ";
    v = next[v];
  }while (v != 1);
  cout << 1 << endl;
}

void extend_path()
{
  int i, j;
  for (i=1; i<=n ; ++i) {
    if (!visited[i]) {
      j = find_visited_child(i);
      if (j != 0) {
	break;
      }
    }
  }

  start = i;
  tail = pre[j];
  next[i] = j;
  pre[j] = i;
  next[tail] = 0;
  visited[i] = true;
  ++len;
}

void path2loop() 
{
  int i = next[start];
  int j = next[i];
  while (j != tail) {
    if (adj[i][tail] && adj[j][start]) {
      break;
    }
    else {
      i = j;
      j = next[i];
    }
  }

  while (tail != j) {
    int tmp = pre[tail];
    next[i] = tail;
    pre[tail] = i;
    i = tail;
    tail = tmp;
  }
  next[i] = tail;
  pre[tail] = i;
}

void solve() 
{
  find_one_path();
  
  while (true) {
    if (adj[start][tail]) {
      next[tail] = start;
      pre[start] = tail;
      if (len == n) {
	output();
	return;
      }
      else {
	extend_path();
      }
    }
    else {
      path2loop();
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
