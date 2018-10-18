#!/bin/python3

import math
import os
import random
import re
import sys

# Complete the extraLongFactorials function below.
def extraLongFactorials(n):
    t = 1
    for i in range(n,0,-1):
        t = t*i    
    print(t)

if __name__ == '__main__':
    n = int(input())
    extraLongFactorials(n)
