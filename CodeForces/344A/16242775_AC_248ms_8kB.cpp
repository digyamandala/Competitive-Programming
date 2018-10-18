#include <iostream>
#include <string>
using namespace std;
int main(){
    int n,c = 1;
    cin >> n;
    string temp;
    cin >> temp;
    for(int i = 0 ; i < n-1 ; i++){
        string p;
        cin >> p;
        if(p != temp) c++;
        temp = p;
    }
    cout << c << endl;
    return 0;
}