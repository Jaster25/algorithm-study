#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Max Heap
void heapify(int *ar, int index, int size)
{
  int maxIndex = index;
  int leftChildIndex = index * 2 + 1;
  int rightChildIndex = index * 2 + 2;

  if (leftChildIndex < size && ar[maxIndex] < ar[leftChildIndex])
    maxIndex = leftChildIndex;
  if (rightChildIndex < size && ar[maxIndex] < ar[rightChildIndex])
    maxIndex = rightChildIndex;

  if (maxIndex != index)
  {
    int temp = ar[index];
    ar[index] = ar[maxIndex];
    ar[maxIndex] = temp;

    heapify(ar, maxIndex, size);
  }
}

void buildHeap(int *ar, int size)
{
  for (int i = size / 2 - 1; i >= 0; i--)
    heapify(ar, i, size);
}

void heapSort(int *ar, int size)
{
  buildHeap(ar, size);

  for (int i = size; i > 0; i--)
  {
    heapify(ar, 0, i);

    // max <-> last index
    int temp = ar[0];
    ar[0] = ar[i - 1];
    ar[i - 1] = temp;
  }
}

int main()
{
  srand((int)time(NULL));

  int size = 20;
  int *ar = (int *)malloc(sizeof(int) * size);

  for (int i = 0; i < size; i++)
    ar[i] = rand() % size;

  printf("Before heap sort\n");
  for (int i = 0; i < size; i++)
    printf("%d ", ar[i]);

  heapSort(ar, size);

  printf("\nAfter heap sort\n");
  for (int i = 0; i < size; i++)
    printf("%d ", ar[i]);

  free(ar);
}