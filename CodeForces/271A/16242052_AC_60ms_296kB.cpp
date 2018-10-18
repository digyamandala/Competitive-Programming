#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

bool isDistinct(string x){
    sort(x.begin(), x.end());
    int c = 0;
    for (int i = 0; i < 3; i++){
        if (x[i] != x[i + 1]) c++;
        else break;
    }
    if (c == 3) return true;
    return false;
}
int main(){
    int x;
    cin >> x;
    for(int i = x+1; i <= 10000 ;i++){
        string y;
        y = to_string((int)i);
        if(isDistinct(y)){
            cout << y << endl;
            break;
        }
    }
    return 0;
}