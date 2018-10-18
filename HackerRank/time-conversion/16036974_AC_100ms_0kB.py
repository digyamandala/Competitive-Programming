#!/bin/python3

import os
import sys

#
# Complete the timeConversion function below.
#
def timeConversion(s):
    #
    # Write your code here.
    #
    h,m,s = s.split(":")
    
    newH = ""
    newS = ""
    
    if "PM" in s:
        newH = str(12 + int(h))
        if(h == "12"):
            newH = "12"
            
        newS = str(s.replace("PM",""))
        
    elif "AM" in s: 
        newH = h
        
        if(h == "12"):
            newH = "00"
        newS = str(s.replace("AM", ""))
    

    newt = newH + ":" + m + ":" + newS
    
    return newt
    
if __name__ == '__main__':
    f = open(os.environ['OUTPUT_PATH'], 'w')

    s = input()

    result = timeConversion(s)

    f.write(result + '\n')

    f.close()
