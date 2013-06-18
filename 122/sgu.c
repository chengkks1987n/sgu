#include <stdio.h>

#define SIZE  1002

char adj[SIZE][SIZE] = {{0}};
char visited[SIZE] = { 0 };  
int n,  next[SIZE], start, tail, len;

void read()
{
  scanf("%d", &n);
  getchar();
  
  int i, a;
  for (i=1; i<=n; ++i) {
    while(1) {
      scanf("%d", &a);
      adj[i][a] = adj[a][i] = 1;
      a = getchar();
      if(a=='\n' || a=='\r' || a==EOF)	break;
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
  //forword
  int u, v = tail;
  while ((u=find_unvisited_child(v)) != 0) {
    next[v] = u;
    ++len;
    visited[u] = 1;
    v = u;
    tail = u;
  }
  //back
  v = start;
  while((u=find_unvisited_child(v)) != 0) {
    next[u] = v;
    ++len;
    visited[u] = 1;
    v = u;
    start = u;
  }
}

void output() 
{
  int v = 1;
  do {
    printf("%d ", v);
    v = next[v];
  }while (v != 1);
  printf("1 \n");
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
  start = next[j];
  tail = i;
  next[j] = i;
  visited[i] = 1;
  ++len;
  find_one_path();
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
  
  int tmp[SIZE];
  int p = j;
  int c = 0;
  do {
    tmp[c] = p;
    ++c;
    p = next[p];
  }while (p != tail);
  next[i] = tail;
  i = tail;
  for (--c; c>=0; --c) {
    next[i] = tmp[c];
    i = tmp[c];
  }
  tail = i;
}

void solve() 
{
  len = start = tail =  visited[1] = 1;
  find_one_path();
  
  while (1) {
    if (adj[start][tail]) {
      next[tail] = start;
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

