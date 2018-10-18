#include <iostream>
#include <cmath>
#define ll long long
using namespace std;
int main(){
    ll n,res;
    cin >> n;
    res = ceil((double)n / 2);
    if(n % 2 != 0) res = -res;
    cout << res << endl;
    return 0;
}