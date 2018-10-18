#include <iostream>
#define ll long long
using namespace std;
int main(){
    ll n;
    double k, w;
    cin >> k >> n >> w;
    ll total = (ll)(((w / 2) * ((2 * k) + ((w - 1) * (k)))) - n);
    if(total > 0) cout << total << endl;
    else cout << 0 << endl;
    return 0;
}