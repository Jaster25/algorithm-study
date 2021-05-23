#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Linked List version

typedef struct Node
{
  struct Node *next;
  int data;
} Node;

typedef struct Lists
{
  Node *L1;
  Node *L2;
} Lists;

int getSize(Node *list)
{
  int count = 0;
  while (list)
  {
    count++;
    list = list->next;
  }
  return count;
}

Lists mergePartition(Node *list, int k)
{
  Node *L1;
  Node *L2;

  Node *curNode = list;
  Node *beforeCurNode = list;

  int index = 0;
  while (index < k / 2)
  {
    beforeCurNode = curNode;
    curNode = curNode->next;
    index++;
  }

  L1 = list;
  L2 = curNode;
  beforeCurNode->next = NULL;

  Lists lists = {L1, L2};
  return lists;
}

Node *merge(Node *L1, Node *L2)
{
  Node *mergedList = NULL;

  if (!L1)
    return L2;
  if (!L2)
    return L1;

  if (L1->data < L2->data)
  {
    mergedList = L1;
    mergedList->next = merge(L1->next, L2);
  }
  else
  {
    mergedList = L2;
    mergedList->next = merge(L1, L2->next);
  }

  return mergedList;
}

void mergeSort(Node **list)
{
  int size = getSize(*list);
  if (size > 1)
  {
    Lists lists = mergePartition(*list, size);

    // Divide
    mergeSort(&lists.L1);
    mergeSort(&lists.L2);

    // Conquer
    *list = merge(lists.L1, lists.L2);
  }
}

Node *getNode()
{
  Node *newNode = (Node *)malloc(sizeof(Node));
  newNode->next = NULL;

  return newNode;
}

void appendNode(Node *list, int newData)
{
  Node *newNode = getNode();
  newNode->data = newData;

  Node *curNode = list;

  if (curNode == NULL)
    curNode = newNode;
  else
  {
    while (curNode->next)
      curNode = curNode->next;

    curNode->next = newNode;
  }
}

void printList(Node *node)
{
  Node *curNode = node;
  while (curNode)
  {
    printf("%d ", curNode->data);
    curNode = curNode->next;
  }
}

void freeList(Node *node)
{
  if (node->next)
    freeList(node->next);
  free(node);
}

int main()
{
  srand((int)time(NULL));

  Node *linkedList = NULL;
  int size = 20;

  for (int i = 0; i < size; i++)
    appendNode((Node *)&linkedList, rand() % size);

  printf("Before merge sort\n");
  printList(linkedList);

  mergeSort(&linkedList);

  printf("\nAfter merge sort\n");
  printList(linkedList);

  freeList(linkedList);
}