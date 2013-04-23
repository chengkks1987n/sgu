#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main () {

  freopen("in.txt", "w", stdout);

  int n;
  int i = 0;
  srand (time(NULL));
  n = rand() % 100 + 1;
  printf("%d\n", n);
  for (; i< n; ++i) {
    putchar('a' + rand() % 2);
  }
  putchar('\n');
  return 0;
}
