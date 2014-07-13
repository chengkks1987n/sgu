/**
   @file 
   @brief 
   @date 
   @version 
   @author 

   @section Description 
   1. �Խڵ㰴k���򣬵õ��ľ�����������������
   sort nodes by k, got the inorder traversal of the tree.
   2. �Խڵ㰴a���򣬵õ�����һ�����ƶѵ����򣨿����ǲ���ȫ����
   sort nodes by a, got something like heap-sort of the tree(not a complete tree)
   3. ��ջ�洢�������Ҳ��֧��
   store the right branch of the tree in a stack��
   4. ����½ڵ�aֵ����ջ��Ԫ�أ��ýڵ�����Ҳ��֧����ջ����������ڣ���ջ���������ص�һ��aֵ�����½ڵ��ջԪ�أ��½ڵ�����ڸ�λ�ã�ջ�к���Ԫ����Ϊ�½ڵ���������������������

   steps�� 
   1. sort nodes by k
   2. put the first node to stack.
   3. traverse the other nodes�� add them to the tree according to the previous rules��
   
   */
#include <stdio.h>
#include <stdlib.h>

int n;
int k[50001];   
int a[50001];

int p[50001];   
int L[50001];   
int r[50001];   

int sk[50001];  // sorted inddex of k
int stack[500001];
int q = 0;
int i, j;

int cmpk (const void *a, const void *b) {
	return k[*(int*)a] - k[*(int*)b];
}

void solve() {
	stack[q++] = sk[1];
	for (i=2; i<=n; ++i) {
		for(j=q; j>0 && a[sk[i]]<a[stack[j-1]]; --j);
		if (j == 0) {
			q = 0;
			L[sk[i]] = stack[q];
			p[stack[q]] = sk[i];
			stack[q++] = sk[i];
		}else if (j == q) {
			p[sk[i]] = stack[q-1];
			r[stack[q-1]] = sk[i];
			stack[q++] = sk[i];
		}
		else {
			q=j;
			p[sk[i]] = stack[q-1];
			r[stack[q-1]] = sk[i];
			L[sk[i]] = stack[q];
			p[stack[q]] = sk[i];
			stack[q++] = sk[i];
		}	
	}
}

int main() {
	scanf("%d", &n);
	for (i=1; i<=n; ++i) {
		scanf("%d%d", &k[i], &a[i]);
		sk[i] = i;
	}
	qsort(sk+1, n, sizeof(int), cmpk);
	solve();
	puts("YES");
	for (i=1; i<=n; ++i) {
		printf("%d %d %d\n", p[i], L[i], r[i]);
	}
	return 0;
}

