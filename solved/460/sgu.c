#include <stdio.h>
#include <string.h>

int main() {
  int n = 0;
  char s[30] = "";
  int len = 0;
  scanf("%d", &n);

  while (n--) {
    scanf("%s", s);
    len = strlen(s);

    if ( s[len-1] == 'o' || s[len-1] == 's' || s[len-1] == 'x' || 
	 (s[len-2] == 'c' && s[len-1] == 'h')) {
      s[len] = 'e';
      s[len+1] = 's';
      s[len+2] = '\0';
    }
    else if (s[len-1] == 'y') {
      s[len-1] = 'i';
      s[len] = 'e';
      s[len+1] = 's';
      s[len+2] = '\0';
    }
    else if (s[len-1] == 'f') {
      s[len-1] = 'v';
      s[len] = 'e';
      s[len+1] = 's';
      s[len+2] = '\0';
    }
    else if (s[len-2] == 'f' && s[len-1] == 'e') {
      s[len-2] = 'v';
      s[len] = 's';
      s[len+1] = '\0';
    }
    else {
      s[len] = 's';
      s[len+1] = '\0';
    }

    puts(s);
  }

  return 0;
}
