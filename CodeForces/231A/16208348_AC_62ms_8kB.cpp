#include <iostream>
using namespace std;
int main(){
    int n, count = 0;
    cin >> n;
    while(n--){
        int a[4], subcount = 0;
        cin >> a[0] >> a[1] >> a[2];
        for(int i = 0 ; i < 3 ; i++)
            if(a[i] == 1) subcount++;
        if(subcount >= 2) count++;
    }
    printf("%d\n", count);
    return 0;
}