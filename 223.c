#include <stdio.h>
#include <stdlib.h>

int n, k;
long long ans = 0;
int stk[102];       //stk, ps 作为stack，存储放棋子方法
int ps = 0;

int bounds[] = {0, 2, 2, 5, 5, 10 };

//void dfs(int m);                //搜素总方法数
int isAvailable(int m);         //判断位置m是否不和已放棋子冲突
int isConflict(int p1, int p2); // 判断p1和p2两个位置是否冲突

int main() {
    scanf("%d%d", &n, &k);
    //    dfs(0);
    while (ps >= 0) {
      if (k == ps) {
        ++ans;
        --ps;
	m = stk[ps] + 1;
      }
      else if (m == n*n) {
        --ps;
	m = stk[ps] + 1;
      }
      else if (isAvailable(m)) {
        stk[ps] = m;
        ++ps;
	++m;
      }
      else {
	++m;
      }
      
    }
    printf("%d", ans);
    return 0;
}

/*
void dfs(int m) {
    if (ps < 0) {
        return ;
    }
    else 
      if (k == ps) {
	
      }

    }
    printf("%d", ans);
    return 0;
}

void dfs(int m) {
    if (ps < 0) {
        return ;
    }
    else 
}
*/
int isAvailable(int m) {
    int i = ps - 1;
    while (i >=0) {
        if (isConflict(m, stk[i])){
            return 0;
        }
        --i;
    }
    return 1;
}

int isConflict(int p1, int p2) {
    int x1 = p1 / n;
    int y1 = p1 % n;

    int x2 = p2 / n;
    int y2 = p2 % n;

    if (abs(x1 - x2) <= 1 && abs(y1 - y2) <= 1) {
        return 1;
    }
    return 0;
}

/*
test:
Input
1 0
1 1
10 11
10 5
10 16
10 21
10 22

Output
1
1
1390559658508
35464464
18440809729503
499506408188
96747372100



*/

