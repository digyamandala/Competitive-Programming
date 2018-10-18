#!/bin/python3

import math
import os
import random
import re
import sys

# Complete the diagonalDifference function below.
def diagonalDifference(arr):
    d1 = 0
    d2 = 0
    i = j = 0
    while i < len(arr):
        d1 = d1 + arr[i][j]
        i = i + 1
        j = j + 1

    i = 0
    j = len(arr[i]) - 1
    while i < len(arr):
        d2 = d2 + arr[i][j]
        i = i + 1
        j = j - 1
    
    return abs(d2-d1)

if __name__ == '__main__':
    fptr = open(os.environ['OUTPUT_PATH'], 'w')

    n = int(input())

    arr = []

    for _ in range(n):
        arr.append(list(map(int, input().rstrip().split())))

    result = diagonalDifference(arr)

    fptr.write(str(result) + '\n')

    fptr.close()
