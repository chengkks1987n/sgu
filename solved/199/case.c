/**
   @file 
   @brief create test cases fro problem 199 
   @date 2013-07-19
   @version 1.0
   @author ck <chengkechengke@gmail.com>

   @section Description 

   */

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int n, i;

int main () {
  srand (time(NULL));
  n = rand() % 7 + 2;
  printf("%d\n", n);
  for (i=0; i< n; ++i) {
    printf("%d %d\n", rand()%99 + 1, rand()%99 + 1);
  }
  putchar('\n');
  return 0;
}
