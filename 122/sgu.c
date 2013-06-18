#include <stdio.h>

#define SIZE  1002

char adj[SIZE][SIZE] = {{0}};
char visited[SIZE] = { 0 };  
int n,  next[SIZE], start, tail, len;

int i, j, a;
int tmp[SIZE], c;
char flag;

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
  a = tail;
  flag = 1;
  while (flag) {
    flag = 0;
    for (i=1; i<=n; ++i) {
      if (adj[a][i] && !visited[i]) {
	next[a] = i;
	++len;
	flag = visited[i] = 1;
	a = tail = i;
      }    
    }
  }
  
  //back
  a = start;
  flag = 1;
  while (flag) {
    flag = 0;
    for (i=1; i<=n; ++i) {
      if (adj[a][i] && !visited[i]) {
	next[i] = a;
	++len;
	flag = visited[i] = 1;
	a = start = i;
      }    
    }
  }
}

int main() 
{
  // read
  scanf("%d", &n);
  getchar();
  for (i=1; i<=n; ++i) {
    while(1) {
      scanf("%d", &a);
      adj[i][a] = adj[a][i] = 1;
      a = getchar();
      if(a=='\n' || a=='\r' || a==EOF)	break;
    }   
  }
  
  // solve 
  len = start = tail =  visited[1] = 1;
  // find a path
  find_one_path();
  
  while (1) {
    if (adj[start][tail]) {
      next[tail] = start;
      if (len == n) {
	//output result
	i = 1;
	do {
	  printf("%d ", i);
	  i = next[i];
	}while (i != 1);
	printf("1 \n");
	return 0;
      }
      else {
	//extend path
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
    }
    else {
      //path to cycle
      i = next[start];
      j = next[i];
      while (j != tail) {
	if (adj[i][tail] && adj[j][start]) {
	  break;
	}
	else {
	  i = j;
	  j = next[i];
	}
      }
      a = j;
      c = 0;
      do {
	tmp[c] = a;
	++c;
	a = next[a];
      }while (a != tail);
      next[i] = tail;
      i = tail;
      for (--c; c>=0; --c) {
	next[i] = tmp[c];
	i = tmp[c];
      }
      tail = i;
    }
  }

  return 0;
}

