#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Array version

void merge(int *ar, int left, int mid, int right)
{
  int *temp = (int *)malloc(sizeof(int) * (right - left + 1));
  int tempIndex = 0;
  int leftIndex = left;
  int rightIndex = mid + 1;

  while (leftIndex <= mid && rightIndex <= right)
  {
    if (ar[leftIndex] < ar[rightIndex])
      temp[tempIndex++] = ar[leftIndex++];
    else
      temp[tempIndex++] = ar[rightIndex++];
  }

  while (leftIndex <= mid)
    temp[tempIndex++] = ar[leftIndex++];
  while (rightIndex <= right)
    temp[tempIndex++] = ar[rightIndex++];

  for (int i = left; i <= right; i++)
    ar[i] = temp[i - left];

  free(temp);
}

void mergeSort(int *ar, int left, int right)
{
  if (left < right)
  {
    int mid = (left + right) / 2;

    // Divide
    mergeSort(ar, left, mid);
    mergeSort(ar, mid + 1, right);

    // Conquer
    merge(ar, left, mid, right);
  }
}

int main()
{
  srand((int)time(NULL));

  int size = 50;
  int *ar = (int *)malloc(sizeof(int) * size);

  for (int i = 0; i < size; i++)
    ar[i] = rand() % size;

  printf("Before merge sort\n");
  for (int i = 0; i < size; i++)
    printf("%d ", ar[i]);

  mergeSort(ar, 0, size - 1);

  printf("\nAfter merge sort\n");
  for (int i = 0; i < size; i++)
    printf("%d ", ar[i]);

  free(ar);
}