#!/bin/python3

import math
import os
import random
import re
import sys

# Complete the plusMinus function below.
def plusMinus(arr):
    
    arrlen = len(arr)
    negcount = 0
    poscount = 0
    zercount = 0

    for i in arr:
        if i < 0:
            negcount = negcount+1
        elif i > 0:
            poscount = poscount+1
        else:
            zercount = zercount+1

    negrat = float(negcount/arrlen)
    posrat = float(poscount/arrlen)
    zerrat = float(zercount/arrlen)
    
    print(round(posrat,6))
    print(round(negrat,6))
    print(round(zerrat,6))


if __name__ == '__main__':
    n = int(input())

    arr = list(map(int, input().rstrip().split()))

    plusMinus(arr)
