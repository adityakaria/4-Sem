#include <bits/stdc++.h>
using namespace std;

int count_inversions_naive(vector<int> numList, int size);
int mergeSort(vector<int> numList, vector<int> auxList, int low, int high);
int merge(vector<int> numList, vector<int> auxList, int low, int mid, int high);

int main(int argc, char *argv[]) {
    vector<int> numList;
    cout << "Enter sequence of numbers" << endl;
    int input;
    while(cin >> input) {
        numList.push_back(input);
    }
    vector<int> auxList = numList;
    cout << "naive: " << count_inversions_naive(numList, numList.size()) << endl;
    cout << "D&C: " << mergeSort(numList, auxList, 0, numList.size()) << endl;

    return 0;
}

int count_inversions_naive(vector<int> numList, int size) {
    int i, j, invCount = 0;

    for (i = 0; i < size - 1; i++) {
        for (j = i + 1; j < size; j++) {
            if (numList[i] > numList[j]) {
                invCount++;
                // cout << numList[i] << ", " << numList[j] << endl;
            }
        }
    }

    return invCount;
}

int mergeSort(vector<int> numList, vector<int> auxList, int low, int high) {
    if (low >= high)
        return 0;
    int mid = floor( (low + high) / 2 );
    int inversions = 0;

    inversions += mergeSort(numList, auxList, low, mid);
    inversions += mergeSort(numList, auxList, mid+1, high);
    inversions += merge(numList, auxList, low, mid, high);

    return inversions;
}

int merge(vector<int> numList, vector<int> auxList, int low, int mid, int high) {
    
}