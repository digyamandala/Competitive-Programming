#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>
#include <fstream>
using namespace std;

int parent[210000];
vector<pair <double, pair<double, double> > > edge;
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
int main()
{
    vector<double> res;
    int majorcase;
    cin >> majorcase;
    vector<pair <double,double> > point;
    for(int i = 0 ; i < majorcase ; i++){
        if(i != 0){
            cout << '\n';
        }
        point.clear();
        edge.clear();
        int minorcase;
        double x, y, dist;
        cin >> minorcase;
        for(int j = 0 ; j < minorcase ; j++){
            cin >> x >> y;
            point.push_back(make_pair(x,y));
        }
        int n = point.size();
        for(int p = 0 ; p < n-1 ; p++){
            for(int q = p+1 ; q < n ; q++){
                dist = sqrt(((point[p].first-point[q].first)*(point[p].first-point[q].first))+((point[p].second-point[q].second)*(point[p].second-point[q].second)));
                edge.push_back(make_pair(dist,make_pair(p,q)));
                // cout << dist << endl
            }
        }
        makeSet(n);
        sort(edge.begin(), edge.end());
        int parentSrc, parentDest;
        double t = 0;
        int ledge = edge.size();
        for (int i = 0; i < ledge; i++)
        {
            parentSrc = findParent(edge[i].second.first);
            parentDest = findParent(edge[i].second.second);
            if (parentSrc != parentDest)
            {
                t = t + edge[i].first;
                parent[parentSrc] = parent[parentDest];
            }
        }
        printf("%.2lf\n", t);
        // res.push_back(t);
    }
    // ofstream file;
    // file.open("o.txt");
    // for(int i = 0 ; i < res.size() ; i++){
    //     // cout << res[i] << endl;
    //     printf("%.2lf\n", t);
    // }
    // file.close();
    return 0;
}