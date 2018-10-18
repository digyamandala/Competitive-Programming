#include <iostream>
#include <string>
#include <sstream>
#include <algorithm>
#include <cstdio>

using namespace std;

int main(){
    unsigned long n = 0;
    cin >> n;
    for(long i = 0 ; i < n ; i++){
        string x,y;
        cin >> x;
        unsigned long m = 0;
        while (true)
        {
            y = x;
            reverse(y.begin(), y.end());
            unsigned long p = 0, q = 0, total = 0;
            stringstream(x) >> p;
            stringstream(y) >> q;
            total = p + q;
            m = m+1;

            string totalstr = to_string(total);
            string temp = totalstr;
            reverse(temp.begin(), temp.end());
            if (temp == totalstr){
                cout << m << " " << totalstr << endl; break;
            }
            else{
                x = totalstr;
                totalstr = "";
            }
        }
    }
    return 0;
}