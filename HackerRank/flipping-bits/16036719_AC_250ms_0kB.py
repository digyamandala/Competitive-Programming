#!/bin/python3

import math
import os
import random
import re
import sys

# Complete the flippingBits function below.
def flippingBits(n):
    s = '{0:032b}'.format(n)
    s = s.replace('0','x')
    s = s.replace('1','y')
    s = s.replace('x','1')
    s = s.replace('y','0')
    
    return int(s,2)

if __name__ == '__main__':
    fptr = open(os.environ['OUTPUT_PATH'], 'w')

    q = int(input())

    for q_itr in range(q):
        n = int(input())

        result = flippingBits(n)

        fptr.write(str(result) + '\n')

    fptr.close()
