#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <map>
#include <fstream>
using namespace std;

int parent[150000], g[150000];
// vector<pair<int, pair<int, int> > > edge;

void makeSet(int n){
    for (int i = 0; i <= n; i++){
        parent[i] = i;
        g[i] = 1;
    }
}
int findParent(int x){
    if (parent[x] != x){
        parent[x] = findParent(parent[x]);
    }
    return parent[x];
}
int main()
{
    int ncase;
    cin >> ncase;
    map<string, unsigned long> mp;
    // ofstream file;
    // file.open("g.txt");
    while(ncase--){
        int f;
        cin >> f;
        mp.clear();
        unsigned long long idx = 0;
        makeSet(150000);
        for(int i = 0 ;i < f ; i++){
            string a,b;
            unsigned long px,py;
            cin >> a >> b;
            if(mp.find(a) == mp.end()){
                //if ga ada di map
                idx = idx + 1;
                mp[a] = idx;
                parent[idx] = idx;
            }
            if(mp.find(b) == mp.end()){
                idx = idx + 1;
                mp[b] = idx;
                parent[idx] = idx;
            }
            px = findParent(mp[a]);
            py = findParent(mp[b]);
            if(px != py){
                parent[px] = py;
                g[py] = g[py] + g[px];
                cout << g[py] << endl;
                // file << g[py] << endl;
            }
            else{
                cout << g[px] << endl;
                // file << g[px] << endl;
            }
        }
    }
    // file.close();
    return 0;
}