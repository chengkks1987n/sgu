/**
   @file 
   @brief Divide and Conquer Method
   @date 
   @version 
   @author 

   @section Description 
   got:Time Limit Exceeded on test 19, 499ms	4183kb
   */

#include <stdio.h>
#include <stdlib.h>

int n;
int k[50001];   
int a[50001];
int sk[50001];  // sorted inddex of k
int sa[50001];  // sorted inddex of a
int p[50001] = { 0 };  // parent
int L[50001] = { 0 };  // left
int r[50001] = { 0 };  // right
int i;

int cmpk (const void *a, const void *b) {
	return k[*(int*)a] - k[*(int*)b];
}

int cmpa(const void *x, const void *y) {
	return a[sk[*(int*)x]] - a[sk[*(int*)y]];
}

int solve(int h, int t, int pa, int f) {
	int m;
	int min = f;
	while (min<=n && (sa[min]<h || sa[min]>t)) ++min;
	m = sk[sa[min]];
	p[m] = pa;
	if (sa[min]-1 >= h) L[m] = solve(h, sa[min]-1, m, min+1);
	if (sa[min]+1 <= t) r[m] = solve(sa[min]+1, t, m, min+1);
	return m;
}

int main() {
	scanf("%d", &n);
	for (i=1; i<=n; ++i) {
		scanf("%d%d", &k[i], &a[i]);
		sa[i] = sk[i] = i;
	}

	qsort(sk+1, n, sizeof(int), cmpk);
	qsort(sa+1, n, sizeof(int), cmpa);
	solve(1, n, 0, 1);

	puts("YES");
	for (i=1; i<=n; ++i) {
		printf("%d %d %d\n", p[i], L[i], r[i]);
	}
	return 0;
}

