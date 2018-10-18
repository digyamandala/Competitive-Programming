#include <iostream>
#include <vector>
#include <algorithm>
#define ull unsigned long long
using namespace std;
int main(){
    ull n,k;
    cin >> n >> k;
    ull mid = (n+1)/2;
    if(k <= mid) cout << (2*k)-1 << endl;
    else cout << 2*(k-mid) << endl;
    return 0;
}