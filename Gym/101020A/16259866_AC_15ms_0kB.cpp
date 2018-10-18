#include <iostream>
using namespace std;
int main(){
    int n;
    cin >> n;
    while(n--){
        int x,y;
        unsigned long long r;
        cin >> x >> y;
        r = (unsigned long long)x*y;
        cout << r << endl;
    }
    return 0;
}