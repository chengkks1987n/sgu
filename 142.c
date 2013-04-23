

#include <stdio.h>
#include <string.h>

char s[500002] = "";
char ans[22] = "";

/*
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
*/

//convert int v to binary string in length len
void int2str(int v, int len, char *str) {
  int i = 0;
  for (; i<len; ++i) {
    str[i] = 'a' + (v & 1);
    v >>= 1;
  }
  str[i] = '\0';
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
  int b = (1 << len);
  for ( ; i<b; ++i) {
    int2str(i, len, ans);
    if (strstr(s, ans) == NULL) {
      return 0;
    }
  }

  return 1;
}


int main() {
  #ifndef ONLINE_JUDGE
  freopen("in.txt", "r", stdin);
  #endif

  int n;
  scanf("%d%s",&n, s);

  int low = 0;
  int up = LOG2(n) + 1;
  int mid;
  while (up - low > 1) {
    mid = (up + low) / 2;
    if (contain(mid)) {
      low = mid;
    }
    else {
      up = mid;
    }
  }
  if (up != mid) {
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
