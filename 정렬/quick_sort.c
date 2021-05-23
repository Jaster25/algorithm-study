#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int partition(int *ar, int start, int end)
{
  // pivot: left
  int pivot = ar[start];
  int toRight = start + 1;
  int toLeft = end;

  while (toRight <= toLeft)
  {
    // left section: find a value greater than pivot
    while (toRight <= end && pivot >= ar[toRight])
      toRight++;

    // right section: find a value less than pivot
    while (toLeft > start && pivot <= ar[toLeft])
      toLeft--;

    if (toRight > toLeft)
    {
      // pivot <-> toLeft
      ar[start] = ar[toLeft];
      ar[toLeft] = pivot;
    }
    else
    {
      // toRight <-> toLeft
      int temp = ar[toLeft];
      ar[toLeft] = ar[toRight];
      ar[toRight] = temp;
    }
  }

  return toLeft;
}

void quick_sort(int *ar, int start, int end)
{
  if (start >= end)
    return;

  // divide
  int pivot = partition(ar, start, end);

  // conquer
  quick_sort(ar, start, pivot - 1);
  quick_sort(ar, pivot + 1, end);
}

int main()
{
  srand((int)time(NULL));

  int size = 20;
  int *ar = malloc(sizeof(int) * size);

  for (int i = 0; i < size; i++)
    ar[i] = rand() % size;

  printf("Before quick sort\n");
  for (int i = 0; i < size; i++)
    printf("%d ", ar[i]);

  quick_sort(ar, 0, size - 1);

  printf("\nAfter quick sort\n");
  for (int i = 0; i < size; i++)
    printf("%d ", ar[i]);

  free(ar);
}