#include <iostream>
#include <string>
using namespace std;
int main(){
    string x;
    cin >> x;
    int l = x.length();
    bool danger = false;
    int count = 0;
    for(int i = 0 ; i < l-1 ; i++){
        if(x[i] == x[i+1]){
            count++;
            if(count >= 6){
                danger = true;
                break;
            }
        }
        else count = 0;
    }
    if(danger) cout << "YES" << endl;
    else cout << "NO" << endl;
    return 0;
}