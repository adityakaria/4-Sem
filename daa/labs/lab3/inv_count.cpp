#include <bits/stdc++.h>
using namespace std;

int count_inversions_naive(int size);
int mergeSort(vector<int> auxList, int low, int high);
int merge(vector<int> auxList, int low, int mid, int high);

vector<int> numList;

int main(int argc, char *argv[]) {
    cout << "Enter sequence of numbers" << endl;
    int input;
    while(cin >> input) {
        numList.push_back(input);
    }
    vector<int> auxList;
    cout << "naive: " << "\t" << count_inversions_naive(numList.size()) << endl;
    cout << "D&C: " << mergeSort(auxList, 0, numList.size()) << endl;

    return 0;
}

int count_inversions_naive(int size) {
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

int mergeSort(vector<int> auxList, int low, int high) {
    cout << "================" << endl;
    // To print the vector
    for (int p = low; p < high; p++) {
        cout  << "\t(" << p << ")";
    }
    cout << endl;
    for (int p = low; p < high; p++) {
        cout  << "\t" << numList[p];
    }
    cout << endl;

    // Check if low < high
    if (low >= high - 1) {
        cout << "----END---- " << low << ">=" << high << endl;
        return 0;
    }


    int mid = (low + high) / 2 ;
    cout << "\tLow: " << low << "\tMid: " << mid << "\tHigh: " << high << endl;
    int inversions = 0;

    cout << "\t--1--" << endl;
    inversions += mergeSort(auxList, low, mid);

    cout << "\t--2--" << endl;
    inversions += mergeSort(auxList, mid, high);

    cout << "\t--3--" << endl;
    inversions += merge(auxList, low, mid, high);

    cout << "Return inv: " << inversions << endl;
    return inversions;
}

int merge(vector<int> auxList, int low, int mid, int high) {
    auxList.clear();
    // cout << "\tAuxlist size "<<auxList.size() << endl;
    cout <<endl <<"While Merging: " << low << " | " << mid << " | " << high << endl;
    for (int p = low; p < high; p++) {
        if (p == mid) {
            cout << " |";
        }
        cout  << " " << numList[p];
    }
    cout << endl;
    
    int i = low, k = low, j = mid;
    int invCount = 0;
    while(i < mid && j < high) {
        cout << "\t\t" << numList[i] << " :-: " << numList[j] << endl;
        if (numList[i] <= numList[j]) {
            auxList.push_back(numList[i]);
            i++;
            cout << "\t\t      X" << endl;
        }
        else if (numList[i] > numList[j]) {
            auxList.push_back(numList[j]);
            j++;
            invCount += (mid - i ); 
            cout << "\t\tX" << endl;
            cout << "\t\t~> " << mid - i << endl;
            // invCount++;
            
        }
        k++;
    }
    while (i < mid) {
        auxList.push_back(numList[i]);
        cout << "00000 " << numList[i] << endl;
        i++;
    }
    while (j < high) {
        auxList.push_back(numList[j]);
        cout << "11111 " << numList[j] << endl;
        j++;
    }
    int m = low;
    cout << "[ ";
    for (int p = 0; p < auxList.size(); p++) {
        numList[m] = auxList[p];

        cout << numList[m] << "\t";
        m++;
    }
    cout << " ]";
    cout << endl;

    cout <<"\t\t" <<low<<", "<<mid<<", "<<high<<" --> "<<invCount << endl;
    return invCount;
}