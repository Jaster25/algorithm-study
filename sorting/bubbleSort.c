#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void bubbleSort(int *ar, int size)
{
  for (int i = 0; i < size; i++)
    for (int j = 0; j < size - i - 1; j++)
      if (ar[j] > ar[j + 1])
      {
        int temp = ar[j];
        ar[j] = ar[j + 1];
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

  printf("Before bubble sort\n");
  for (int i = 0; i < size; i++)
    printf("%d ", ar[i]);

  bubbleSort(ar, size);

  printf("\nAfter bubble sort\n");
  for (int i = 0; i < size; i++)
    printf("%d ", ar[i]);

  free(ar);
}