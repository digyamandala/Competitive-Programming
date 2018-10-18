#!/bin/python3

import math
import os
import random
import re
import sys

# Complete the birthday function below.

def birthday(s, d, m):
    total, c, i, l = 0, 0, 0,len(s)
    while(i+(m-1) < l):
        for j in range(i, i+m):
            total = total + s[j]
        if total == d:
            c = c + 1
        total = 0
        i = i + 1
    return c

if __name__ == '__main__':
    fptr = open(os.environ['OUTPUT_PATH'], 'w')

    n = int(input().strip())

    s = list(map(int, input().rstrip().split()))

    dm = input().rstrip().split()

    d = int(dm[0])

    m = int(dm[1])

    result = birthday(s, d, m)

    fptr.write(str(result) + '\n')

    fptr.close()
