#!/bin/python3

import math
import os
import random
import re
import sys

# Complete the miniMaxSum function below.
def miniMaxSum(arr):
    total = 0
    for i in arr:
        total = total + i
        
    res = []
    for i in arr:
        res.append(total-i)
        
    res.sort()
    
    print(res[0], res[len(res)-1])
        

if __name__ == '__main__':
    arr = list(map(int, input().rstrip().split()))

    miniMaxSum(arr)
