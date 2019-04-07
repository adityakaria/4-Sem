#include <bits/stdc++.h>
using namespace std;
#define MAX 256

struct Node {
    char name;
    struct Node *parent;
};

struct DisjointSet {
    vector<struct Node> sets;
};

int main(void) {
    int choice = 1;
    while(choice) {
        cout << "Enter your choice:\n1. makeSet\n2. findSet\n3. Union\n0. Exit" << endl;
        cin >> choice;
        switch (choice) {
            case 1: makeSet();
            case 2: findSet();
            case 3: setUnion();
        }
    }
        // string nodeName;
        // cin >> nodeName;

        // makeSet(nodeName);

    return 0;
}

void makeSet() {
    struct Node a;
    a.name;
    a.parent = &a;

    struct DisjointSet set;
    set. = &a;

    return &set;
}

void findSet() {
    struct Node a;
    a.name;
    a.parent = &a;

    struct DisjointSet set;
    set. = &a;

    return &set;
}

void Set() {
    struct Node a;
    // a.name;
    a.parent = &a;

    struct DisjointSet set;
    set.sets.push_back(a);

    return &set;
}


// class DisjointSet {
//     public:
//         class Node {
//             public:
//                 int data;
//                 int 
//     }
// }