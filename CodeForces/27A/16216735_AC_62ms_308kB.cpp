#include <iostream>
using namespace std;

bool arr[3050];
void init(){
    for(int i = 0 ; i < 3001 ; i++)
        arr[i] = false;
}
int main(){
    int n;
    cin >> n;
    for(int i = 0 ; i < n ; i++){
        int temp;
        cin >> temp;
        arr[temp-1] = true;
    }
    for(int i = 0 ; i < 3001 ; i++){
        if(arr[i] == false){
            cout << i+1 << endl;
            break;
        }
    }
    return 0;
}