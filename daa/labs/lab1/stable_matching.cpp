#include <bits/stdc++.h>
#define MAX 256
using namespace std;

int main(void) {
    vector<string> men, women;
    char name[20];
    
    // Open file
    ifstream infile;
    infile.open("input.txt");
    
    // No of members from each gender
    int n;
    // cin >> n;
    infile >> n; // According to input.txt

    // Read men and women names
    for (int i = 0; i < n; i++) {
        infile >> name;
        men.push_back(name);
    }
    for (int i = 0; i < n; i++) {
        infile >> name;
        women.push_back(name);
    }

    // Read their preferences
    map<string, vector<string> > menPref, womenPref;

    for (int i = 0; i < n; i++) {
        vector<string> pref;
        infile >> name;
        for (int j = 0; j < n; j++) {
            infile >> name;
            pref.push_back(name);
        }
        menPref.insert(make_pair(men.at(i), pref));
    }
    for (int i = 0; i < n; i++) {
        vector<string> pref;
        infile >> name;
        for (int j = 0; j < n; j++) {
            infile >> name;
            pref.push_back(name);
        }
        womenPref.insert(make_pair(women.at(i), pref));
    }

    // Make Free man queue
    queue<string> freeMan;
    for (int i = 0; i < n; i++) {
        freeMan.push(men.at(i));
    }
    
    // Marriage mapping holds the engagement records with the woman name as the key
    map<string, string> marriage;
    while(!(freeMan.empty())) {
        string name = freeMan.front();
        // cout << name << endl;
        vector<string> mPref = menPref.at(name);
        string woman = mPref.at(0);
        // cout << "\t" << woman << endl;

        // If marriage record of woman exists (i.e., is engaged)
        if (marriage.count(woman) > 0) {
            menPref.at(name).erase(menPref.at(name).begin()); // Erase the first woman in the man's preference list after reading her name
            int oldIndex,newIndex;
            string prevMan = marriage.at(woman);
            vector <string> wPref = womenPref.at(woman);

            oldIndex = find(wPref.begin(), wPref.end(), prevMan) - wPref.begin();
            newIndex = find(wPref.begin(), wPref.end(), name) - wPref.begin();

            // If woman prefers new man over her current partner
            if (newIndex < oldIndex) {
                marriage[woman] = name;
                freeMan.pop();
                freeMan.push(prevMan);
            }
        }
        else { // When woman is not engaged, just pair her with the current man.
            marriage[woman] = name;
            freeMan.pop();
        }
    }
    // cout << endl << endl;
    // To print the final matching
    for (int i = 0; i < n; i++) {
        cout << marriage.at(women.at(i)) << "\t->  " << women.at(i) << endl;
    }
}