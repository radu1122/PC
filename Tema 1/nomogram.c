#include <stdio.h>

int puzzleCheck() {
  int i, j, n, m, k = 0, v[100][100], a[10000], p[10000], q, y;
  scanf("%d", &n);
  scanf("%d", &m);
  for (i = 0; i < n; i++) {
    scanf("%d", &p[i]);
    for (j = 0; j < p[i]; j++) {
      scanf("%d", &a[k + j]);
    }
    k = k + p[i];
  }

  for (i = 0; i < m; i++) {
    scanf("%d", &p[i + n]);

    for (j = 0; j < p[i + n]; j++) {
      scanf("%d", &a[k + j]);
    }
    k = k + p[i + n];
  }
  for (i = 0; i < n; i++) {
    for (j = 0; j < m; j++) {
      scanf("%d", &v[i][j]);
    }
  }
  k = 0;
  y = 0;
  for (i = 0; i < n; i++) {
    j = 0;
    while (j < m) {
      k = 0;
      while (v[i][j] == 0 && j < m) {
        j++;
      }
      q = 0;
      while (v[i][j] == 1 && j < m) {
        j++;
        q++;
      }
      if (q != 0 && k >= p[i]) {
        return 0;
      }
      if (q != 0 && q == a[y]) {
        k++;
        y++;
      }
      if (q != 0 && q != a[y - 1]) {
        return 0;
      }
      j++;
    }
  }
  k = 0;
  for (i = 0; i < m; i++) {
    j = 0;
    while (j < n) {
      k = 0;
      while (v[j][i] == 0 && j < n) {
        j++;
      }
      q = 0;
      while (v[j][i] == 1 && j < n) {
        j++;
        q++;
      }
      if (q != 0 && k >= p[i + n]) {
        return 0;
      }
      if (q != 0 && q == a[y]) {
        k++;
        y++;
      }
      if (q != 0 && q != a[y - 1]) {
        return 0;
      }
      j++;
    }
  }
  return 1;
}

int main() {
  int t, i;
  scanf("%d", &t);
  for (i = 0; i < t; i++) {
    if (puzzleCheck()) {
      printf("Corect\n");
    } else {
      printf("Eroare\n");
    }
  }
  return 0;
}
