/**
   @file 
   @brief 
   @date 
   @version 
   @author 

   @section Description 
   notice:
   1. for input '123@1234.com   123 ', the output is 'NO', other tan 'Yes NO'
   2. space on the tail should be ignored.
   3. the difftrence between gets and scanf.
   */
#include <stdio.h>

char s[102];

int dotPsn[100];
int dotCount = 0;
int atPsn = -1;
int len = 0;
char *p = 0;

int isLetter(char c) {
  return ('a'<=c && c<='z') || ('A'<=c && c<='Z');
}

int isSymbol(char c) {
  return isLetter(c) || c =='-' || c=='_' || ('0'<=c && c<='9');
}

int isWord(int p, int q) {
  if (p >= q) return 0;
  while (p < q) {
    if (!isSymbol(s[p])) return 0;
    ++p;
  }
  return 1;
}

int isDomain(int p, int q) {
  if(q-p<2 || q-p>3) return 0;
  while (p < q) {
    if (!isLetter(s[p])) return 0;
    ++p;
  }
  return 1;
}

int check() {
  len = 0;
  atPsn = -1;
  dotCount = 0;

  for ( p=s; *p!='\0'; ++p) {
    if ('.' == *p) {
      dotPsn[dotCount++] = len;
    }
    else if ('@' == *p) {
      if (atPsn > 0) return 0; // more than one '@'
      atPsn = dotCount;
      dotPsn[dotCount++] = len;
    }
    ++len;
  }

  while (s[len-1] == ' ') --len; // trim the space on tail.

  if (atPsn < 0) return 0; // witout '@'
  if (dotCount - atPsn == 1) return 0; // without '.' after '@'
  //check domain
  if (!isDomain(dotPsn[--dotCount]+1, len)) return 0;
  
  while (dotCount > 0) {
    if (!isWord(dotPsn[dotCount-1]+1, dotPsn[dotCount])) return 0;
    --dotCount;
  }
  
  return isWord(0, dotPsn[0]);
}

int main () {
  int N;
  scanf("%d\n", &N);
  while (N--) {
    //scanf("%s", s);
    gets(s);
    if (check()) 
      printf("YES\n");
    else
      printf("NO\n");
  }
  return 0;
}
