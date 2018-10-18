#include <iostream>
#include <string>

using namespace std;

int main()
{
    while(true){
        int total = 0; int c;
        cin >> c;
        if(c == 0) break;
        while (c != 0){
            total = total + (c%10);
            c = (int) (c / 10);
            if(c == 0 && total >= 10){
                c = total;
                total = 0;
            }
        }
        cout << total << endl;
    }
    return 0;
}