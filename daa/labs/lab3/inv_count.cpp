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
    cout << "D&C: " << mergeSort(numList, auxList, 0, numList.size() - 1) << endl;

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
    cout <<"\t" <<mid<<endl;
    int inversions = 0;

    inversions += mergeSort(numList, auxList, low, mid);
    cout << "\t--1--" << endl;
    inversions += mergeSort(numList, auxList, mid+1, high);
    cout << "\t--2--" << endl;
    inversions += merge(numList, auxList, low, mid, high);
    cout << "\t--3--" << endl;

    return inversions;
}

int merge(vector<int> numList, vector<int> auxList, int low, int mid, int high) {
    int i = low, k = low, j = mid + 1;
    int invCount = 0;
    while(i <= mid && j <= high) {
        if (numList[i] <= numList[j]) {
            auxList.push_back(numList[i++]);
        }
        else if (numList[i] > numList[j]) {
            auxList.push_back(numList[j++]);
            invCount += (mid - i + 1); 
        }
        k++;
    }
    while (i <= mid) {
        auxList.push_back(numList[i++]);
    }
    vector<int>::iterator ptr;
    for (ptr = auxList.begin(); ptr < auxList.end(); ptr++) {
        numList[k] = *ptr;
    }

    cout <<"\t\t" <<low<<", "<<mid<<", "<<high<<" --> "<<invCount << endl;
    return invCount;
}