#include <stdio.h>

#define R(r, c) (a[((r)*(sm)+(c))])
#define SIZE  0x100000

int a[SIZE] = { 0 };
int n, m;
int sn, sm;

int main() 
{
	int sr = 2, sc = 2;
	int mark = 4;
	int i=0, j=0;

	scanf("%d%d", &n, &m);
	sn = 1 << n;
	sm = 1<< m;
	R(0,0) = 0; R(0,1) = 2;
	R(1,0) = 1; R(1,1) = 3;

	//solve	
	while (sc < sm){
		for ( i=0; i<sc; ++i) {
			for ( j=0; j< sr; ++j) {
				R(j,sc+i) = R(j,sc-1-i) | mark;			
			}
		}
		mark = mark << 1;
		sc = sc << 1;
	}

	while (sr < sn){
		for ( i=0; i<sc; ++i) {
			for ( j=0; j< sr; ++j) {
				R(sr+j, i) = R(sr-1-j, i) | mark;		
			}
		}
		mark = mark << 1;
		sr = sr << 1;
	}

	//outupt
	for ( i=0; i<sn; ++i) {
		for ( j=0; j<sm; ++j) {
			printf("%d ", R(i,j));
		}
		putchar('\n');
	}

	return 0;
}


/***************************************
for a matrix with r rows c columns, we define a mirror opration like this:
mirror right:
  extend the column of the matrix to 2*c, 
  for the column c+j (j=1~c), the datas is same as the column c-j+1
mirror down:
  same as mirror right, but extend the row and fill them.

the solution is:
 1. suppose we have a solution(in matrix A) for N=p, M=q
 2. the solution for N=p, M=q+1 
    2.1 mirror right A
    2.2 for highest bit(int binary) of the new filled datas, add 1
 3. the solution for N=p+1, M=q, is almost the same , just mirror down.

 **************************************/
