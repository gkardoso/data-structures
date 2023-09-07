#include <stdio.h>

void bubbleSort(int *array, int n) {
  int i, j;
  for (i = 0; i < n - 1; i++) {
    for (j = 0; j < n - i - 1; j++) {
      if (array[j] > array[j + 1]) {
        int temp = array[j];
        array[j] = array[j + 1];
        array[j + 1] = temp;
      }
    }
  }
}

int main() {
  int array[] = {5, 2, 1, 7, 6, 3, 4};
  int n = sizeof(array) / sizeof(array[0]);

  bubbleSort(array, n);

  for (int i = 0; i < n; i++) {
    printf("%d ", array[i]);
  }
  printf("\n");

  return 0;
}
