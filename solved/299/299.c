#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct BigInt{
  char s[510];
} ck;

ck a[1000];
int n;

void add(const ck* x, const ck* b, ck* ans) {
  ck r;
  int n1 = strlen(x->s) - 1;
  int n2 = strlen(b->s) - 1;
  int c = 0;
  int i = 0;
  int tmp;
  int over = 0;
  while(1){
    tmp = c;
    over = 1;
    if (n1 >= 0) {
      tmp += (x->s)[n1] - '0';
      over = 0;
    }
    if (n2 >= 0) {
      tmp += (b->s)[n2] - '0';
      over = 0;
    }
    if (over && !c) break;
    (r.s)[i++] = tmp % 10 + '0';
    c = tmp / 10;
    --n1;
    --n2;
  }

  // reverse r.s
  int j = 0;
  while (j < i) {
    (ans->s)[j] = (r.s)[i-j-1];
    ++j;
  }
  (ans->s)[j] = '\0';
  
}

int cmp(const void *p1, const void *p2) {
  char* s1 = ((ck*)p1)->s;
  char* s2 = ((ck*)p2)->s;
  
  int r = strcmp(s1, s2);
  if (r == 0) return 0;
  
  int n1= strlen(s1);
  int n2 = strlen(s2);
  
  if (n1 > n2) return 1;
  else if (n1 < n2) return -1;
  
  return r;  
}

int solve() {
  int i = 0;
  ck tmp;
  qsort(a, n,sizeof(a[0]), cmp);

  while (i < n-2) {
    add(&a[i], &a[i+1], &tmp);
    if (cmp(&tmp, &a[i+2]) > 0) return i;
    ++i;
  }
  return -1;	
}

int main() {

#ifndef ONLINE_JUDGE
  freopen("testcase.txt", "r", stdin);
#endif

  int i = 0;
  scanf("%d", &n);
  i = n;
  while (i--) scanf("%s", a[i].s);

#ifndef ONLINE_JUDGE
  ck tmp;
  ck x;
  ck b;
  strcpy(x.s, "12");
  strcpy(b.s, "9");
  add (&x, &b, &tmp);
  printf("%s\n", tmp.s);

  strcpy(x.s, "99");
  add(&x, &x, &tmp);
  printf("%s\n", tmp.s);
#endif

  
  if((i=solve()) != -1) 
    printf("%s %s %s\n", a[i].s, a[i+1].s, a[i+2].s);
  else
    printf("0 0 0\n");

  return 0;  
}
