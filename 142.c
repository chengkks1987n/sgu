

#include <stdio.h>
#include <string.h>

int n ;
char s[500002] = "";
char mark[20][524290];
int result;
char ans[21];

void initMark(int p) {
  memset(mark, sizeof(mark), 0);
  int i;
  for (i=0; i<n; ++i) {
    s[i] -= 'a';
  }
  
  for (i=0; i<n; ++i) {
    int v = 0;
    int j = 1;
    while (j<=p && i+j-1<n) {
      v = (v<<1) | s[i+j-1];
      mark[j][v] = 1;
      ++j;
    }
  }
}

//convert int v to binary string in length len
void int2str(int v, int len, char *str) {
  int i = len - 1;
  for (; i>=0; --i) {
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
    if (mark[len][i] == 0) {
      result = i;
      return 0;
    }
  }
  return 1;
}


int main() {
  #ifndef ONLINE_JUDGE
  freopen("in.txt", "r", stdin);
  #endif

  scanf("%d%s",&n, s);

  int low = 0;
  int up = LOG2(n) + 1;
  int mid;
  initMark(up);
  while (up - low > 1) {
    mid = (up + low) / 2;
    if (contain(mid)) {
      low = mid;
    }
    else {
      up = mid;
    }
  }
  if (up == LOG2(n)+1) {
    contain(up);
  }
  
  int2str(result, up, ans);
  printf("%d\n%s\n", up, ans);
  return 0;
}

/** test cases
aabaaabbbab
4
aaaa

 */
