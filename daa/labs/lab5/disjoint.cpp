

// This C++ program implements the Disjoint Set data structure. It is a data structure that keeps track of a set of elements partitioned into a number of disjoint (nonoverlapping) subsets.
// Here is the source code of the C++ program to display the sum of data subsets the data strucure has been partitioned in. This C++ program is successfully compiled and run on DevCpp, a C++ compiler. The program output is given below.

/*
* C++ Program to Implement Disjoint Set Data Structure
 */
#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>
#include <bits/stdc++.h>
using namespace std;
#define INF 1000000000
 
typedef pair<int ,int> ii;
typedef vector <int> vi;
 
vector <pair<int ,ii> > edges;
vi pset;
 
void init(int N)
{
    pset.assign(N, 0);
    for(int i = 0; i < N; i++)
    {
        pset[i] = i;
    }
}
 
int find_set(int i)
{
    if(pset[i] == i)
    {
        return pset[i];
    }
    return pset[i] = find_set(pset[i]);
}
bool issameset (int i, int j)
{
    return find_set(i) == find_set(j);
}
void joinset(int i, int j)
{
    pset[find_set(i)] = find_set(j);
}
int main()
{
    int n, m, a, b, dist, t;
    cin>>t;
    while(t--)
    {
        cin>>n>>m;
        init(n);
        edges.clear();
        for (int i = 0; i < m; i++)
        {
            cin>>a>>b>>dist;
            a--,b--;
            ii tmp = make_pair(a, b);
            edges.push_back(make_pair(dist, tmp));
        }
        sort(edges.rbegin(),edges.rend());
        int sum = 0;
        for(int i = 0; i < edges.size(); i++)
        {
            if (!issameset (edges[i].second.first, edges[i].second.second))
            {
               joinset(edges[i].second.first, edges[i].second.second);
            }
            else sum += edges[i].first;
        }
        cout<<sum;
    }
    cin>>t;
    // getch();
}
// Output
// enter the number of sets to be  computed
// 1
// enter the number of disjoint sets and the number of rows
// 2
// 3
// enter the start and end vertices alongwith weight of edge
// 1
// 1
// 2
// enter the start and end vertices alongwith weight of edge
// 1
// 1
// 3
// enter the start and end vertices alongwith weight of edge
// 1
// 1
// 4
// Sum is:9