#include <stdio.h>

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
  int ar[10] = {10, 3, 7, 1, 4, 9, 2, 5, 8, 6};

  printf("Before selection sort\n");
  for (int i = 0; i < sizeof(ar) / sizeof(int); i++)
    printf("%d ", ar[i]);

  selection_sort(ar, sizeof(ar) / sizeof(int));

  printf("\nAfter selection sort\n");
  for (int i = 0; i < sizeof(ar) / sizeof(int); i++)
    printf("%d ", ar[i]);
}