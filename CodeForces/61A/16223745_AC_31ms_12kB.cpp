#include <iostream>
#include <string>
using namespace std;
int main(){
    string x,y;
    cin >> x;
    cin >> y;
    int l = x.length();
    for(int i = 0 ; i < l ; i++){
        if(x[i] != y[i]) cout << '1';
        else cout << '0';
    }
    cout << endl;
    return 0;
}