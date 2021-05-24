import random
from collections import deque

size = 20
ar = [random.randrange(0, size) for _ in range(size)]


def radixSort():
    global ar
    maxRadix = len(str(max(ar))) - 1
    Bucket = [deque() for _ in range(10)]

    for i in range(maxRadix + 1):
        for data in ar:
            if len(str(data)) - 1 < i:
                Bucket[0].append(data)
            else:
                Bucket[int(str(data)[len(str(data)) - 1 - i])].append(data)

        temp = []
        for j in range(10):
            while Bucket[j]:
                temp.append(Bucket[j].popleft())
        ar = temp


if __name__ == "__main__":
    print("Before radix sort")
    print(ar)

    radixSort()

    print("After radix sort")
    print(ar)
