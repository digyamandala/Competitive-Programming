#include <iostream>
#include <string>
using namespace std;
int main(){
    string s;
    cin >> s;
    int l = s.length();
    for(int i = 0 ; i < l ; i++){
        if (!((char)tolower(s[i]) == (char)tolower('A') || (char)tolower(s[i]) == (char)tolower('I') 
        || (char)tolower(s[i]) == (char)tolower('U') || (char)tolower(s[i]) == (char)tolower('E') 
        || (char)tolower(s[i]) == (char)tolower('O') || (char)tolower(s[i]) == (char)tolower('Y')))
        {
            cout << '.' << (char)tolower(s[i]);
        }
        else{
            continue;
        }
    }
    cout << endl;
    return 0;
}