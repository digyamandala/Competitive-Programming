#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
using namespace std;

int parent[210000];
vector< pair < int, pair <int, int > > > edge;

void makeSet(int n)
{
    for (int i = 0; i <= n; i++)
    {
        parent[i] = i;
    }
}
int findParent(int x)
{
    if (parent[x] != x)
    {
        parent[x] = findParent(parent[x]);
    }
    return parent[x];
}
int main(){
    int m, n;
    while(cin >> m >> n){
        if(m == 0 && n == 0) break;
        edge.clear();
        unsigned long totalcost = 0;
        int src,dest,cost;
        for(int i = 0 ; i < n ; i++){
            cin >> src >> dest >> cost;
            edge.push_back(make_pair(cost, make_pair(src,dest)));
            totalcost = totalcost + edge[i].first;
        }
        makeSet(m);
        sort(edge.begin(), edge.end());
        int parentSrc, parentDest;
        unsigned long t = 0;
        for(int i = 0 ; i < n ; i++){
            parentSrc = findParent(edge[i].second.first);
            parentDest = findParent(edge[i].second.second);
            if(parentSrc != parentDest){
                t = t + edge[i].first;
                parent[parentSrc] = parent[parentDest];
            }
        }
        cout << totalcost - t << endl;
    }
    return 0;
}