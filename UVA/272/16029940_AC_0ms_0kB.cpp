#include <iostream>
#include <string>
#include <fstream>

using namespace std;

int main()
{
    string s;
    // ifstream file;
    // file.open("b.txt");
    int flag = 0;
    int l = 0;
    while (getline(cin,s))
    {   
        l = s.length();
        for (int i = 0; i < l; i++){
            // cout << flag << endl;
            if (s[i] == '\"'){
                if (flag == 0){
                    cout << "``";
                    flag = 1;
                    // cout << "changed" << endl;
                }
                else if (flag == 1){
                    cout << "''";
                    flag = 0;
                    // cout << "changed" << endl;
                }
            }
            else{
                cout << s[i];
            }
        }
        cout << endl;
        // cout << endl << endl <<  s << endl;
        // cout << l;
    }
    // cout << s << endl;
    // cout << endl;
    // file.close();

    // string s;
    // getline(cin,s);

    return 0;
}