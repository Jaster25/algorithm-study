#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Array version

void merge(int *ar, int left, int mid, int right)
{
}

void merge_sort(int *ar, int left, int right)
{
  if (left < right)
  {
    int mid = (left + right) / 2;

    // Divide
    merge_sort(ar, left, mid);
    merge_sort(ar, mid + 1, right);

    // Conquer
    merge(ar, left, mid, right);
  }
}

int main()
{
  srand((int)time(NULL));

  int size = 20;
  int *ar = malloc(sizeof(int) * size);

  for (int i = 0; i < size; i++)
    ar[i] = rand() % size;

  printf("Before merge sort\n");
  for (int i = 0; i < size; i++)
    printf("%d ", ar[i]);

  merge_sort(ar, 0, size - 1);

  printf("\nAfter merge sort\n");
  for (int i = 0; i < size; i++)
    printf("%d ", ar[i]);

  free(ar);
}