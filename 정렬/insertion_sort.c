#include<stdio.h>

void insertion_sort (int* ar, int size) {
  for (int i = 1; i < size ; i++)
  {
    int temp = ar[i];
    int j = i - 1;
    while ( j >= 0 && ar[j] >= temp ) {
      ar[j + 1] = ar[j];
      j--;
    }
    ar[j + 1] = temp;
  }
}

int main() {
  int ar[10] = {10,3,7,1,4,9,2,5,8,6};

  printf("Before insertion sort\n");
  for(int i=0 ; i< sizeof(ar) / sizeof(int) ; i++)
    printf("%d ", ar[i]);

  insertion_sort(ar, sizeof(ar) / sizeof(int));

  printf("\nAfter insertion sort\n");
  for(int i=0 ; i< sizeof(ar) / sizeof(int) ; i++)
    printf("%d ", ar[i]);
}