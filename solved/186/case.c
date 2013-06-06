#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
  srand(time(NULL));
  int n =  random() % 101;
  int i;
  printf("%d\n", n);
  for (i=0; i<n; ++i) {
    int a = random()%100 + 1;
    printf("%d ", a);
  }
  printf("\n");
  return 0;
}
