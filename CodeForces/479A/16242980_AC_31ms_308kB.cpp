#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
int main(){
    int a,b,c;
    cin >> a; cin >> b; cin >> c;
    vector<int> arr;
    arr.push_back(a*b*c);
    arr.push_back(a+b+c);
    arr.push_back(a+b*c);
    arr.push_back(a*(b+c));
    arr.push_back((a+b)*c);
    sort(arr.begin(),arr.end());
    cout << arr[4] << endl;
    return 0;
}