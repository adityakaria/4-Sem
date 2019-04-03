
#include<bits/stdc++.h> 
using namespace std; 
  
int pageFaults(int pages[], int n, int capacity) 
{ 
    unordered_set<int> s; 
  
    queue<int> indexes; 
    int page_faults = 0; 
    for (int i=0; i<n; i++) 
    { 
        if (s.size() < capacity) 
        { 
            if (s.find(pages[i])==s.end()) 
            { 
                s.insert(pages[i]); 
                page_faults++; 
                indexes.push(pages[i]); 
            } 
        } 
  
        else
        {
            if (s.find(pages[i]) == s.end()) 
            {
                int val = indexes.front(); 
                indexes.pop(); 
                s.erase(val);  
                s.insert(pages[i]); 
                indexes.push(pages[i]); 
                page_faults++; 
            } 
        } 
    } 
  
    return page_faults; 
} 
  
// Driver code 
int main() 
{ 
    int pages[] = {9, 2, 1, 2, 0, 5, 0, 4, 2, 3, 0, 3, 1, 2, 9, 0, 5, 3, 4, 0}; 
    int n = sizeof(pages)/sizeof(pages[0]); 
    int capacity = 3;
    int pf = pageFaults(pages, n, capacity); 
    int hr = pf / n;
    int mr = (n-pf) / n;
    cout << "hit ratio: "; 
    return 0; 
} 


