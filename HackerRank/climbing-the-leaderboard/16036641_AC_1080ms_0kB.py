#!/bin/python3

import math
import os
import random
import re
import sys

# Complete the climbingLeaderboard function below.
def climbingLeaderboard(scores, alice):
#     setscores = list(set(scores))
    
#     #setscores.sort()
#     #setscores.reverse()
#     checkindex = 0
#     alicelen = len(alice)
    
#     res = []

#     for i in range(alicelen):
#         setscores.append(alice[i])
#         setscores.sort()
#         setscores.reverse()
#         res.append((setscores.index(alice[i]))+1)
    
    setscores = sorted(set(scores), reverse = True)
    arank = len(setscores)
    res = []
    
    for i in alice:
        while i >= setscores[arank-1] and arank > 0:
            arank = arank - 1
        
        res.append(arank + 1)
    return res

if __name__ == '__main__':
    fptr = open(os.environ['OUTPUT_PATH'], 'w')

    scores_count = int(input())

    scores = list(map(int, input().rstrip().split()))

    alice_count = int(input())

    alice = list(map(int, input().rstrip().split()))

    result = climbingLeaderboard(scores, alice)

    fptr.write('\n'.join(map(str, result)))
    fptr.write('\n')

    fptr.close()
