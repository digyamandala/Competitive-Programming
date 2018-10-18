#include <bits/stdc++.h>

using namespace std;

vector<string> split_string(string);

/*
 * Complete the getTotalX function below.
 */
int getTotalX(vector<int> a, vector<int> b) {

int aMax = *std::max_element(a.begin(), a.end());
    int aSize = a.size();
    vector<int> ares[aSize];

    for (int i = 0; i < aSize; i++)
    {
        for (int j = aMax; j < 101; j++)
        {
            if (j % a[i] == 0)
            {
                ares[i].push_back(j);
            }
        }
    }


    vector<int> aInter[aSize];
    int p = -1;

    if ((sizeof(ares) / sizeof(*ares)) > 1)
    {
        p = p + 1;

        set_intersection(ares[0].begin(), ares[0].end(), ares[1].begin(), ares[1].end(), back_inserter(aInter[p]));

        if ((sizeof(ares) / sizeof(*ares)) > 2)
        {
            for (int i = 2; i < (sizeof(ares) / sizeof(*ares)); i++)
            {
                set_intersection(aInter[p].begin(), aInter[p].end(), ares[i].begin(), ares[i].end(), back_inserter(aInter[p + 1]));
                p = p + 1;
            }
        }
    }
    else
    {
        aInter[p + 1] = ares[0];
        p = p + 1;
    }

    //==========================================================

    
    int bSize = b.size();
    vector<int> bres[bSize];

    for (int i = 0; i < bSize; i++)
    {
        for (int j = aMax; j < 101; j++)
        {
            if (b[i] % j == 0)
            {
                bres[i].push_back(j);
            }
        }
    }


    vector<int> bInter[bSize];
    int q = -1;

    if ((sizeof(bres) / sizeof(*bres)) > 1)
    {
        q = q + 1;

        set_intersection(bres[0].begin(), bres[0].end(), bres[1].begin(), bres[1].end(), back_inserter(bInter[q]));
        

        if ((sizeof(bres) / sizeof(*bres)) > 2)
        {
            for (int i = 2; i < (sizeof(bres) / sizeof(*bres)); i++)
            {

                set_intersection(bInter[q].begin(), bInter[q].end(), bres[i].begin(), bres[i].end(), back_inserter(bInter[q+1]));
                q = q + 1;
            }
        }
    }
    else
    {
        bInter[q+1] = bres[0];
        q = q+1;
    }   

    //==========================================================
    vector<int> cInter;

    set_intersection(aInter[p].begin(), aInter[p].end(), bInter[q].begin(), bInter[q].end(), back_inserter(cInter));
    
    int total = cInter.size();
    return total;
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    string nm_temp;
    getline(cin, nm_temp);

    vector<string> nm = split_string(nm_temp);

    int n = stoi(nm[0]);

    int m = stoi(nm[1]);

    string a_temp_temp;
    getline(cin, a_temp_temp);

    vector<string> a_temp = split_string(a_temp_temp);

    vector<int> a(n);

    for (int a_itr = 0; a_itr < n; a_itr++) {
        int a_item = stoi(a_temp[a_itr]);

        a[a_itr] = a_item;
    }

    string b_temp_temp;
    getline(cin, b_temp_temp);

    vector<string> b_temp = split_string(b_temp_temp);

    vector<int> b(m);

    for (int b_itr = 0; b_itr < m; b_itr++) {
        int b_item = stoi(b_temp[b_itr]);

        b[b_itr] = b_item;
    }

    int total = getTotalX(a, b);

    fout << total << "\n";

    fout.close();

    return 0;
}

vector<string> split_string(string input_string) {
    string::iterator new_end = unique(input_string.begin(), input_string.end(), [] (const char &x, const char &y) {
        return x == y and x == ' ';
    });

    input_string.erase(new_end, input_string.end());

    while (input_string[input_string.length() - 1] == ' ') {
        input_string.pop_back();
    }

    vector<string> splits;
    char delimiter = ' ';

    size_t i = 0;
    size_t pos = input_string.find(delimiter);

    while (pos != string::npos) {
        splits.push_back(input_string.substr(i, pos - i));

        i = pos + 1;
        pos = input_string.find(delimiter, i);
    }

    splits.push_back(input_string.substr(i, min(pos, input_string.length()) - i + 1));

    return splits;
}
