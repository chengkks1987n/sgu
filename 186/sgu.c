#include <stdio.h>

int n;
int c[101] = { 0 };     // c[Li] is the count of links with length Li
int ac[101] = { 0 };    //ac[Li] is the count of links whith length <= Li
int b[101] = { 0 };     // b[Li] is the Link length less than Li;
char f[50][52] ;

int before(int v) {
  int k = v - 1;
  while (c[k] <= 0) --k;
  return k;
}

//change recusive to loop
int test(int m, int v) {
  if (m == 1 && c[v] > 0) {
    return 1;
  }
  if (ac[v] < m) {
    return 0;
  }

  if (b[v] == 0) {
    return 0;
  }
  return test(m-1, v-b[v]) || test(m, b[v]);
}


int main() {
  scanf("%d", &n);
  int i;
  for (i=0; i<n; ++i) {
    int Li;
    scanf("%d", &Li);
    ++c[Li];
  }
  //init ac[Li]
  for (i=1; i<=n; ++i) {
    ac[i] += c[i] +ac[i-1];
  }
  // init b[Li]
  for (i=n; i>0; ) {
    int j = i - 1;
    while (c[j] <= 0 && j > 0){
      --j;
    }
    for (; i > j; --i) {
      b[i] = j;
    }
  }

  for (i=(n-1)/2; i>0; --i) {
    if (test(i, n-i-1)) {
	break;
    }
  }
  
  printf("%d\n", n-i-1);
  return 0;
}

/** test cases
2
3 4
1

2
1 1
1

3
1 1 1
1

*/
