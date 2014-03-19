#include <stdio.h>

int calc(int a, int b, int x, int y) {
  int r = 0;
  if (a == x) ++r; // guess the score of first tearm
  if (b == y) ++r; // guess the score of second tearm
  //if (a-b == x-y || b-a == x-y) r += 3; //guess the diference
  if (a-b == x-y) r += 3; //guess the diference
  if ((a>b && x>y) || (a==b && x==y) || (a<b && x<y)) r += 2; //guess the winner
  return r;
}

int main() {
  int n, m; // n- number of participants, m - number of games
  int a, b; //scores of two teams
  int x, y; // guess scores of participant
  int s[101] = { 0 }; // sorce of every participants
  int i;
  scanf("%d%d", &n, &m);

  while (m--) {
    scanf("%d%d", &a, &b);
    for (i=1; i<=n; ++i) {
      scanf("%d%d", &x, &y);
      s[i] += calc(a, b, x, y);
    }
  }
  
  for (i=1; i<=n; ++i) {
    printf("%d ", s[i]);
  }
  putchar('\n');
  return 0;
}
