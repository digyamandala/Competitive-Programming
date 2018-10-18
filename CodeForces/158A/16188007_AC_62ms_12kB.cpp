#include <iostream>
#include <vector>
using namespace std;
int main(){
    int n,k;
    cin >> n >> k;
    vector<int> a;
    for(int i = 0 ; i < n ; i++){
        int temp; cin >> temp;
        a.push_back(temp);
    }
    int b = a[k-1], count = 0;
    for(int i = 0 ; i < n ; i++){
        if(a[i] >= b && a[i] > 0) count++;
        else break;
    }
    cout << count << endl;
    return 0;
}