#include <iostream>
#include <string>
// #include <sstream>
// #include <algorithm>
// #include <cstdio>
// #include <vector>
using namespace std;

int search(char s[], int n, char c){
    for(int i = 0 ; i < n ; i++){
        if(s[i] == c)
            return i;
    }
    return -1;
}

int main()
{
    char s1[] = {'Q','W','E','R','T','Y','U','I','O','P','[',']','\\'};
    char s2[] = {'A','S','D','F','G','H','J','K','L',';','\''};
    char s3[] = {'Z','X','C','V','B','N','M',',','.','/'};
    char s4[] = {'`','1','2','3','4','5','6','7','8','9','0','-','='};
    int ls1 = 13, ls2 = 11, ls3 = 10, ls4 = 13;
    string s;
    while(getline(cin,s)){
        int l = s.length();
        for(int i = 0 ; i < l ; i++){
            if(s[i] != ' '){
                if(search(s1, ls1, s[i]) != -1){
                    cout << s1[search(s1, ls1, s[i])-1];
                }
                else if(search(s2, ls2, s[i]) != -1){
                    cout << s2[search(s2, ls2, s[i]) - 1];
                }
                else if(search(s3, ls3, s[i]) != -1){
                    cout << s3[search(s3, ls3, s[i]) - 1];
                }
                else if(search(s4, ls4, s[i]) != -1){
                    cout << s4[search(s4, ls4, s[i]) - 1];
                }
            }
            else{
                cout << s[i];
            }
        }
        cout << endl;
    }
    return 0;
}
