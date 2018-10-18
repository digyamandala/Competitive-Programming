#!/bin/python3

import math
import os
import random
import re
import sys

# Complete the maxMin function below.
def maxMin(k, arr):
    sarr = arr.copy()
    sarr.sort()
    l = len(arr)
    i = 0
    minx = 1000000000
    while(k+i <= l):
        minx = min(minx,sarr[i+k-1]-sarr[i])
        i = i+1
    return minx

if __name__ == '__main__':
    fptr = open(os.environ['OUTPUT_PATH'], 'w')

    n = int(input())

    k = int(input())

    arr = []

    for _ in range(n):
        arr_item = int(input())
        arr.append(arr_item)

    result = maxMin(k, arr)

    fptr.write(str(result) + '\n')

    fptr.close()
