/**
   @file 
   @brief problem 178 on sgu oj
   @date 2013-07-15
   @version 1.0
   @author ck <chengkechengke@gmail.com>

   @section Description 
   
   1. for the first step, break n to three parts: a1=n-n1-1, a2=1, and a3=n1 (a1>=a3).
   - for the first day to a3-th day, we use the a3 part(breaked by te
   follow steps, suppose we have a solution for a3 ) to pay
   - for the(a3+1)-th day, we pay a2
   - for the (a3+2)-th day we must pay a1, make sure we can get changes,
   a1 - (1 + a3) = 0 or 1, so n1 = floor(n/2) - 1
   
   2. for the (k+1)-th step, we already have k ones. we want to break
   nk to three part: a1=nk - 1 - n(k+1), a2=1, a3=n(k+1)
   - for the first day to (a3+k+1)-th day, we have (1+1) ones and a a3
   part (alse suppose we have the solution for this)
   - for the (a3+k+2)-th day we must pay a1, make sure we can get changes,
   a1 - (k + 1 + a3) = 0 or 1, so  n(k+1) = floor(n(k) - k - 2) / 2;
   
   3. if k - n(k) >= 1 , means that we have k ones and need to break
   nk, in this situation we need do nothing the answer is 0.

   */

#include <stdio.h>

long long n;
int k = 0; //!< how many ones we have; which step we are in.

int main()
{
  scanf("%lld", &n);
  while (n - k > 1) {
    n = (n - k - 2) >> 1;
    ++k;
  }

  printf("%d\n", k);
  return 0;
}
