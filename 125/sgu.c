
/**
 * @file
 * @brief my c solution for problem 125 on SGU OJ
 * @author ck<chengkechengke@gmail.com>
 * @date 2013-06-19
 * @version 
 * 
 * @section DESCRIPTION
 *
 * There must exist zero in B, if not, the problem has no answer.
 * The A value in the zero position must be bigger than others.
 * Put the biggest value to A at the zero position, update B around
 * the zero positon. Continue this untill A is all filled.
 * Here is the algrithm:
 *  1, init
 *      biggest_value = 9;
 *      A = 0;    // zero in A means that it is not filled, we can always
 *                   fill it with a negtive number.
 *      zero[] = 0; // mark zero positons.
 *                  // zero position means a positon where A and B 
                    // are both zero
 *                  // 0: not a zero positon,
 *                  // 1: a zero positon, its neighbours ar not checked
 *                  // 2: a zero positon, its neighbours are checked
 *  2, find a positon where A and B are both zero
 *      if exist
 *           mark the position with 1, goto 3
 *      else if A is all filled 
 *           success! output A 
 *      else 
 *           NO_ANS
 * 3, extend zero positon in the same row or column, extend in four 
 *    directions -- up, down, right, left
 *        1) find a zero position mark with 1.
 *        2) check if its four neighbours are zero positon
 *           if it is, and its zero mark is zero,
 *                mark the positon with 1;
 *        3) mark this positon with 2
 *        4) goto 1), untill you cannot find zero positon mark with 1.
 * 4, put biggest_value to A at zero positons
 * 5, biggest_value = biggest_value - 1;
 * 6, update B with zero positons
 *      foreach zero positon
 *         if its neighbour value in A is zero
 *              sub B value with 1
 *              if B value < 0
 *                 NO_ANS
 * 7, goto 2
 */

#include <stdio.h>
#include <string.h>

#define NO_ANS 	printf("NO SOLUTION\n");return 0;
#define SZ 3        /**< max size of input */

int n;   
int A[SZ][SZ] = {{0}};
int B[SZ][SZ] = {{0}};

int i, j, nn, row, col;
int element = SZ*SZ;  /**< the number need to put to A */
int zero[SZ*SZ];    /**< zeros positon row*n+col */

int main() 
{
  // read input
  scanf("%d", &n);
  nn = n * n;
  for (i=0; i<n; ++i) {
    for (j=0; j<n; ++j) {
      scanf("%d", &B[i][j]);
    }
  }

  while (element > 0) {
    // find zeros
    row = 0;   //indicate if there is zero
    memset(zero, 0, sizeof(zero));
    for (i=0; i<n; ++i) {
      for (j=0; j<n; ++j) {
	if (B[i][j] == 0 && A[i][j] == 0) {
	  row = 1;
	  zero[i*n+j] = 1;
	  break;
	}
      }
      if (row > 0) {
	break;
      }
    }
    // cannot find zero
    if (row <= 0) {
      for (i=0; i<n; ++i) {
	for (j=0; j<n; ++j) {
	  if (A[i][j] <= 0) {
	    NO_ANS;
	  }
	}
      }
      break;
    }
    // can find zero, extend
    j = 1;  // indicate if zero can be extened
    while (j) {
      j = 0;
      for (i=0; i<nn; ++i) {
	if (zero[i] == 1) {
	  row = i / n;
	  col = i % n;
	  j = row - 1;
	  if (j>=0 && A[j][col]==0 && B[j][col]==0 && zero[j*n+col]==0) {
	    zero[j*n+col] = 1;
	  }
	  j = row + 1;
	  if (j<n && A[j][col]==0 && B[j][col]==0 && zero[j*n+col]==0) {
	    zero[j*n+col] = 1;
	  }
	  j = col - 1;
	  if (j>=0 && A[row][j]==0 && B[row][j]==0 && zero[row*n+j]==0) {
	    zero[row*n+j] = 1;
	  }
	  j = col + 1;
	  if (j<n && A[row][j]==0 && B[row][j]==0 && zero[row*n+j]==0) {
	    zero[row*n+j] = 1;
	  }
	  zero[i] = 2;
	  j = 1;
	}
      }
    }
    // put element to A
    for (i=0; i<nn; ++i) {
      if (zero[i]) {
	row = i / n;
	col = i % n;
	A[row][col] = element;
      }
    }
    --element;
    // update B
    for (i=0; i<nn; ++i) {
      if (zero[i]) {
	row = i / n;
	col = i % n;      
	j = row - 1;
	if (j>=0 && A[j][col]<=0) {
	  --B[j][col];
	  if (B[j][col] < 0) {
	    NO_ANS;
	  }
	}
	j = row + 1;
	if (j<n && A[j][col]<=0) {
	  --B[j][col];
	  if (B[j][col] < 0) {
	    NO_ANS;
	  }
	}      
	j = col - 1;
	if (j>=0 && A[row][j]<=0) {
	  --B[row][j];
	  if (B[row][j] < 0) {
	    NO_ANS;
	  }
	}
	j = col + 1;
	if (j<n && A[row][j]<=0) {
	  --B[row][j];
	  if (B[row][j] < 0) {
	    NO_ANS;
	  }
	}
      }
    }
  }

  // output ans
  for (i=0; i<n; ++i) {
    for (j=0; j<n; ++j) {
      printf("%d ", A[i][j]);
    }
    putchar('\n');
  }

  return 0;
}
