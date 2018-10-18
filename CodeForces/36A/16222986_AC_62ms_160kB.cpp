#include <iostream>
#include <string>
#include <vector>
using namespace std;
int main(){
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    int n,res;
    vector<int> arr;
    bool m = true;
    string x;
    cin >> n;
    cin >> x;
    for(int i = 0 ; i < n ; i++){
        if(x[i] == '1'){
            arr.push_back(i);
        }
    }
    int l = arr.size();
    int temp = arr[1] - arr[0];
    for(int i = 1 ; i < l-1 ; i++){
        res = arr[i+1] - arr[i];
        if(temp != res){
            m = false; break;
        }
        temp = res;
    }
    if(m == true) cout << "YES" << endl;
    else cout << "NO" << endl;
    return 0;
}