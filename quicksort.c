#include <stdio.h>

void quicksort(int *array, int left, int right) {
  if (left >= right) {
    return;
  }

  int pivot = array[(left + right) / 2];

  int i = left;
  int j = right;
  while (i < j) {
    while (array[i] < pivot) {
      i++;
    }
    while (array[j] > pivot) {
      j--;
    }
    if (i < j) {
      int temp = array[i];
      array[i] = array[j];
      array[j] = temp;
    }
  }
  quicksort(array, left, i - 1);
  quicksort(array, i + 1, right);
}

int main() {
  int array[] = {5, 2, 1, 7, 6, 3, 4};
  int size = sizeof(array) / sizeof(array[0]);

  quicksort(array, 0, size - 1);

  for (int i = 0; i < size; i++) {
    printf("%d ", array[i]);
  }
  printf("\n");

  return 0;
}
