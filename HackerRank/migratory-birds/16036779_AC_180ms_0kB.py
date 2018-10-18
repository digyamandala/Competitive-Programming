#!/bin/python3

import math
import os
import random
import re
import sys


# Complete the migratoryBirds function below.
def migratoryBirds(arr):
    temparr = list(set(arr))
    tempcount = []
    for i in range(0, len(temparr)):
        tempcount.append(arr.count(temparr[i]))   
    return temparr[tempcount.index(max(tempcount))]
        
    
if __name__ == '__main__':
    fptr = open(os.environ['OUTPUT_PATH'], 'w')

    arr_count = int(input().strip())

    arr = list(map(int, input().rstrip().split()))

    result = migratoryBirds(arr)

    fptr.write(str(result) + '\n')

    fptr.close()
