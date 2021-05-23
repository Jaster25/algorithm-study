#include <stdio.h>

void bubble_sort(int *ar, int size)
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
  int ar[10] = {10, 3, 7, 1, 4, 9, 2, 5, 8, 6};

  printf("Before bubble sort\n");
  for (int i = 0; i < sizeof(ar) / sizeof(int); i++)
    printf("%d ", ar[i]);

  bubble_sort(ar, sizeof(ar) / sizeof(int));

  printf("\nAfter bubble sort\n");
  for (int i = 0; i < sizeof(ar) / sizeof(int); i++)
    printf("%d ", ar[i]);
}