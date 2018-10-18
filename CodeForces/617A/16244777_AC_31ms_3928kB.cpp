#include <iostream>
using namespace std;
int x[1000005];

void init(){
    x[0] = 0;
    int c = 1;
    for(int i = 1 ; i < 1000001 ; i++){
        x[i] = 1*c;
        if(i%5 == 0)
            c++;
    }
}
int main(){
    init();
    int p;
    cin >> p;
    cout << p[x] << endl;
    return 0; 
}