#include <stdio.h>

void merge(int *v, int l, int m, int r) {
  int i, j, k;
  int n1 = m - l + 1;
  int n2 = r - m;

  int v1[n1], v2[n2];

  for (i = 0; i < n1; i++) {
    v1[i] = v[l + i];
  }
  for (j = 0; j < n2; j++) {
    v2[j] = v[m + 1 + j];
  }

  i = 0;
  j = 0;
  k = l;
  while (i < n1 && j < n2) {
    if (v1[i] <= v2[j]) {
      v[k] = v1[i];
      i++;
    } else {
      v[k] = v2[j];
      j++;
    }
    k++;
  }

  while (i < n1) {
    v[k] = v1[i];
    i++;
    k++;
  }

  while (j < n2) {
    v[k] = v2[j];
    j++;
    k++;
  }
}

void mergesort(int *v, int l, int r) {
  if (l < r) {
    int m = (l + r) / 2;

    mergesort(v, l, m);
    mergesort(v, m + 1, r);

    merge(v, l, m, r);
  }
}

int main() {
  int v[] = {5, 2, 1, 7, 6, 3, 4};
  int n = sizeof(v) / sizeof(v[0]);

  mergesort(v, 0, n - 1);

  for (int i = 0; i < n; i++) {
    printf("%d ", v[i]);
  }

  return 0;
}
