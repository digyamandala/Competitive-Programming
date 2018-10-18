#include <iostream>
using namespace std;
int main(){
    int n,x,y,z;
    int totalx = 0, totaly = 0, totalz = 0;
    cin >> n;
    while(n--){
        cin >> x >> y >> z;
        totalx = x + totalx;
        totaly = y + totaly;
        totalz = z + totalz;
    }
    if (totalx == 0 && totaly == 0 && totalz == 0)
        cout << "YES" << endl;
    else
        cout << "NO" << endl;
    return 0;
}