
#include <stdio.h>
#include <string.h>

char s[500002] = "";
char ans[22] = "";

int next(char* str) {
  int i = 0;
  while (str[i] != '\0') {
    if (str[i] == 'a') {
      str[i] = 'b';

      return 1;
    }
    else {
      str[i] = 'a';
      ++i;
    }
  }
  return 0;
}

int LOG2(int m) {
  int t[] = {1, 2, 4, 8, 16, 32, 64, 128, 256, 512, 1024, 2048, 4096, 
	     8192, 16384, 32768, 65536, 131072, 262144, 524288 };
  int r = 0;
  while (t[r] < m) ++r;
  return r;
}

int contain(int len) {
  int i = 0;
  for ( ; i<len; ++i) {
    ans[i] = 'a';
  }
  ans[i] = '\0';
  
  do {
    char *p = strstr(s, ans);
    if (p == 0) {
      return 0;
    }
  } while (next(ans));

  return 1;
}


int main() {
  int n;
  scanf("%d%s",&n, s);
  int low = 0;
  int up = LOG2(n) + 1;
  while (up - low > 1) {
    int mid = (up + low) / 2;
    if (contain(mid)) {
      low = mid;
    }
    else {
      up = mid;
    }
  }
  if (up == LOG2(n) + 1) {
    contain(up);
  }
  
  printf("%d\n%s\n", strlen(ans), ans);
  return 0;
}

/** test cases
aabaaabbbab
4
aaaa

 */
