import random
from collections import deque

size = 20
ar = [random.randrange(0, 1000) for _ in range(size)]

Q = [deque() for _ in range(10)]


def radixSort(ar):
    maxRadix = len(str(max(ar)))

    for i in range(maxRadix + 1):
        for data in ar:
            Q[int(str(data)[len(str(data)) - 1 - i])].append(data)

        ar = []
        for j in range(10):
            while Q[j]:
                ar.append(Q[j].popleft())

    print(ar)


if __name__ == "__main__":
    print("Before radix sort")
    print(ar)

    radixSort(ar)

    print("After radix sort")
    print(ar)
