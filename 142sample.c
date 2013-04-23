#include <stdio.h>
#include <string.h>

char s[5000002] = "";
char ans[22] = "a";

void next(char *str) {
  int i = 0;
  while (1) {
    if (str[i] == 'a') {
      str[i] = 'b';
      return ;
    }
    else if (str[i] == '\0') {
      str[i] = 'a';
      str[i+1] = '\0';
      return ;
    }
    else {
      str[i] = 'a';
      ++i;
    }
  }
}

int main() {

  freopen("in.txt", "r", stdin);

  int n ;
  scanf("%d%s", &n, s);

  char *p = strstr(s, ans);
  while (p != NULL ) {
    next(ans);
    p = strstr(s, ans);
  }
  printf("%d\n%s\n", strlen(ans), ans);
  return 0;
}
