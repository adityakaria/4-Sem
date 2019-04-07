#include <bits/stdc++.h>

using namespace std;
void show(vector<vector<int> > a, int n);

bool sortcol( const vector<int>& v1, 
               const vector<int>& v2 ) { 
    return v1[1] < v2[1]; 
} 

int main(void) {
    cout << "Enter Number of Intervals:\t";
    int n;
    cin >> n;

    map<int, int> vals;
    // int intervals[n][2];
    vector< vector<int> > intervals;
    int a, b;
    cout << "Enter values: " << endl;
    for (int i = 0; i < n; i++) {
        cin >> a >> b;
        vector<int> values;

        values.push_back(a);
        values.push_back(b);    
        intervals.push_back(values);
        // cout << intervals[i][0] << " --> " << intervals[i][1] << endl;
        vals.insert(make_pair(a, b));
    }
    // show(intervals, n);
    // cout << endl;
    // map<int, int>::iterator itr; 
    
    // for (itr = vals.begin(); itr != vals.end(); itr++) {
    //     cout << itr->first << " | " << itr->second << endl;
    // }

    // sort(intervals, intervals + n);   
    sort(intervals.begin(), intervals.end(), sortcol); 
    // show(intervals, n);
    // show(intervals, n);
    // vector<vector<int> >::iterator itr;
    int current = 0;
    cout << intervals[current][0] << " --> " << intervals[current][1] << endl;             
    for (int i = 0; i < intervals.size(); i++) {
        if (current >= intervals.size())
            break;
        if (intervals[current][1] >= intervals[current+i][0]) {
            continue;
        }
        else {
            cout << intervals[current+i][0] << " --> " << intervals[current+i][1] << endl;
            current = current+i;             
        }
    }
}

void show(vector<vector<int> > a, int n) { 
    for(int i = 0; i < a.size(); i++) 
        cout << a[i][0] << " --> " << a[i][1] << endl; 
}