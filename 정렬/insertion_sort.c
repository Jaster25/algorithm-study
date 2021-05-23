#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void insertion_sort(int *ar, int size)
{
  for (int i = 1; i < size; i++)
  {
    int temp = ar[i];
    int j = i - 1;
    while (j >= 0 && ar[j] >= temp)
    {
      ar[j + 1] = ar[j];
      j--;
    }
    ar[j + 1] = temp;
  }
}

int main()
{
  srand((int)time(NULL));

  int size = 20;
  int *ar = (int *)malloc(sizeof(int) * size);

  for (int i = 0; i < size; i++)
    ar[i] = rand() % size;

  printf("Before insertion sort\n");
  for (int i = 0; i < size; i++)
    printf("%d ", ar[i]);

  insertion_sort(ar, size);

  printf("\nAfter insertion sort\n");
  for (int i = 0; i < size; i++)
    printf("%d ", ar[i]);

  free(ar);
}