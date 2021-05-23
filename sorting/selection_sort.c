#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void selection_sort(int *ar, int size)
{
  for (int i = 0; i < size; i++)
  {
    int minIndex = i;
    for (int j = i; j < size; j++)
      if (ar[j] < ar[minIndex])
        minIndex = j;

    int temp = ar[i];
    ar[i] = ar[minIndex];
    ar[minIndex] = temp;
  }
}

int main()
{
  srand((int)time(NULL));

  int size = 20;
  int *ar = (int *)malloc(sizeof(int) * size);

  for (int i = 0; i < size; i++)
    ar[i] = rand() % size;

  printf("Before selection sort\n");
  for (int i = 0; i < size; i++)
    printf("%d ", ar[i]);

  selection_sort(ar, size);

  printf("\nAfter selection sort\n");
  for (int i = 0; i < size; i++)
    printf("%d ", ar[i]);

  free(ar);
}