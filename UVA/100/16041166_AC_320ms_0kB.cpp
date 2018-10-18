#include <iostream>
using namespace std;
int main(){
    unsigned long i, j;
    while (cin >> i >> j){
        int maxcount = -1000000;
        int count = 0;
        unsigned long ci = i,cj = j;
        if (i > j){
            unsigned long temp = i;
            i = j;
            j = temp;
        }
        while (i <= j){
            unsigned long n = i;
            while(n != 1){
                if(n % 2 != 0){
                    n = (3*n) + 1;
                }
                else{
                    n = n >> 1;
                }
                count = count + 1;
            }
            if (n % 2 != 0){
                n = (3 * n) + 1;
            }
            else{
                n = n >> 1;
            }
            count = count + 1;

            if(count > maxcount){
                maxcount = count;
            }
            count = 0;
            i = i + 1;
        }
        printf("%ld %ld %d\n",ci,cj, maxcount);
    }
    return 0;
}