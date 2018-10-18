#!/bin/python3

import os
import sys

#
# Complete the gradingStudents function below.
#
def gradingStudents(grades):
    #
    # Write your code here.
    #
    base = []
    for i in range(45,101,5):
        base.append(i)
    
    lengrades = len(grades)
    lenbase = len(base)
    for i in range(0,lengrades):
        for j in range(0,lenbase):
            if grades[i] >= 40:
                if base[j] >= grades[i] and abs(grades[i] - base[j]) < 3:
                    grades[i] = base[j]
                    break
            
            else:
                if abs(grades[i] - 40) < 3:
                    grades[i] = 40
    
    return grades
    

if __name__ == '__main__':
    f = open(os.environ['OUTPUT_PATH'], 'w')

    n = int(input())

    grades = []

    for _ in range(n):
        grades_item = int(input())
        grades.append(grades_item)

    result = gradingStudents(grades)

    f.write('\n'.join(map(str, result)))
    f.write('\n')

    f.close()
