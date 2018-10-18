#include <iostream>
#include <cmath>
#define ull unsigned long long
using namespace std;

int main(){
    ull n,m,a;
    cin >> n >> m >> a;
    ull d,h;
    // d = n/a;
    // h = m/a;
    // d = (unsigned long)ceil(n/a);
    // h = (unsigned long)ceil(m/a);
    // cout << d << " " << h  << endl;
    // cout << d*h << endl;

    d = n / a;
    h = m / a;
    if(n % a != 0) d++;
    if(m % a != 0) h++;
    cout << d*h << endl;
    return 0;
}