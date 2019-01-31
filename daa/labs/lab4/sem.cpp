#include <bits/stdc++.h>
using namespace std;

void addEdge(vector<int> adj[][2], int a, int b);
void topographicalSort(int V, vector<int> adj[][2], int count[]);

int main(void) {
    int V = 7;
    // cout << "Enter Number of vertices\t";
    // cin >> V;
    vector<int> adj[V][2];
    // vector<int> *adj= new vector<int>[V][2];
    int count[V];

    // int a, b;
    // cout << "Enter edges:" << endl;
    // for (int i = 0; i < V; i++) {
    //     cin >> a >> b;
    //     addEdge(adj, a, b);
    // }

    addEdge(adj, 0, 1);
    addEdge(adj, 0, 2);
    addEdge(adj, 0, 3);
    addEdge(adj, 1, 3);
    addEdge(adj, 1, 4);
    addEdge(adj, 2, 5);
    addEdge(adj, 3, 5);
    addEdge(adj, 4, 3);
    addEdge(adj, 6, 4);
    addEdge(adj, 6, 5);
    topographicalSort(V, adj, count);
}

void addEdge(vector<int> adj[][2], int a, int b) {
    adj[a][0].push_back(b);
    adj[b][1].push_back(a);
}

void topographicalSort(int V, vector<int> adj[][2], int count[]) {
    vector<int> S;
    cout << "S:\t";
    for (int i = 0; i < V; i++) {
        count[i] = adj[i][1].size();
        if (count[i] == 0) {
            S.push_back(i);
            cout << i << "\t";
        }
    }
    cout << endl << "Core Algo:\t" << endl;
    int semCount = 1;
    vector<int> nextsemCourses;
    while (!(S.empty())) {
        int u = S.back();
        cout << u << "\t" << endl;
        S.pop_back();
        for (int j = 0; j < adj[u][0].size(); j++) {
            cout << "\t" << adj[u][0][j] << ", " << count[adj[u][0][j]];
            count[adj[u][0][j]]--;
            if (count[adj[u][0][j]] == 0) {
                S.push_back(adj[u][0][j]);
                cout << " S++ ";
                nextsemCourses.push_back(adj[u][0][j]);
            }
            cout << endl;
        }
        cout << endl;
        if (!nextsemCourses.empty())
        {   
            semCount++;
            cout << "Sem " << semCount << ":\t";
            for (int k = 0; k < nextsemCourses.size(); k++) {
                cout << nextsemCourses[k] << "\t";
            }
            nextsemCourses.clear();
            cout << endl;
        }
    }
    cout << endl;
}