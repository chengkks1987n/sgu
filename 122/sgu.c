#include <stdio.h>

#define SIZE  1002

char adj[SIZE][SIZE] = {{0}};
char visited[SIZE] = { 0 };  
int n, pre[SIZE], next[SIZE], start, tail, len;

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
  len = start = tail =  visited[1] = 1;

  //forword
  int u, v = 1;
  while ((u=find_unvisited_child(v)) != 0) {
    next[v] = u;
    pre[u] = v;
    ++len;
    visited[u] = 1;
    v = u;
    tail = u;
  }
  //back
  v = 1;
  while((u=find_unvisited_child(v)) != 0) {
    next[u] = v;
    pre[v] = u;
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

  start = i;
  tail = pre[j];
  next[i] = j;
  pre[j] = i;
  next[tail] = 0;
  visited[i] = 1;
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
  
  while (1) {
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

