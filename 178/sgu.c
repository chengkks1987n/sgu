/**
   @file 
   @brief problem 178 on sgu oj
   @date 2013-07-15
   @version 1.0
   @author ck <chengkechengke@gmail.com>

   @section Description 
   - I think
   * if n == 1, answer = 0;
   * else if n < 8, answer = 1;
   * else answer = 1 + answer of n/2-1
   */

#include <stdio.h>

int n;
int ans = 0;

int solve(int a) {
  if (a == 0) {
    return 0;
  }
  if (a < 8) {
    return 1;
  }
  return 1 + solve(a/2 - 1);
}

int main()
{
  scanf("%d", &n);
  printf("%d\n", solve(n));
  return 0;
}
