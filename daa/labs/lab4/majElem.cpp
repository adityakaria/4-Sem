/*
Author: Aditya J Karia
Date: 10/02/2019

1. This is a program to find a majority element/object in a given set of objects. 
2. The only operations between each pair of objects is that of equivalence. No other comparisons are possible
3. The time complexity of the required problem must be O(nlog(n))

Note: An element is said to be in majority in a set if it appears MORE than n/2 number of times.

Approach: Divide & Conquer
T(n) = 2.T(n/2) + O(n^1)
Using master's theorum, we get the required time complexity.


To try: Implementing in linear time
*/

#include <bits/stdc++.h>
using namespace std;

char getMajElem(char arr[], int low, int high, int arrSize);
int getElemFreq(char arr[], int low, int high, char element, int arrSize);


int main(void) {
    char arr[] = {'r', 'a', 'm', 'a', 'a', 'r', 'a', 'a', 'm'};
    int arrSize = sizeof(arr)/sizeof(arr[0]);
    // cout << "Size of array: " << arrSize << endl;
    
    char majElem = getMajElem(arr, 0, arrSize - 1, arrSize);

    if (majElem == '\0') {
        cout << "-------------------------------" << endl;
        cout << "Majority Element does not exist" << endl;
        cout << "-------------------------------" << endl;
    }
    else {
        cout << "-------------------" << endl;
        cout << "Majority Element: " << majElem << endl;
        cout << "-------------------" << endl;
    }

    return 0;
}

char getMajElem(char arr[], int low, int high, int arrSize) {
    // cout << "\tgetMajElem: " << low << ", " << high << endl;
    // cout << "\t-----";
    if (high < low) {
        // cout << "\t-- high < low --" << endl;
        return '\0';
    }
    if (high == low) {
        // cout << "\t-- 1 elem --" << endl;
        return arr[low];
    }
    
    int k = (high - low + 1);
    int mid = (high + low) / 2;
    char leftMajElem = getMajElem(arr, low, mid, arrSize);
    char rightMajElem = getMajElem(arr, mid + 1, high, arrSize);

    if (leftMajElem == rightMajElem) {
        // cout << "\t-- rM = lM --" << leftMajElem << endl;
        return leftMajElem;
    }
    int leftFreq = getElemFreq(arr, low, high, leftMajElem, arrSize);
    int rightFreq = getElemFreq(arr, low, high, rightMajElem, arrSize);
    if (leftFreq >= (k / 2) + 1) {
        // cout << "\t-- lM --" << leftMajElem << endl;
        return leftMajElem;
    }
    else if (rightFreq >= (k / 2) + 1) {
        // cout << "\t-- rM --" << rightMajElem << endl;
        return rightMajElem;
    }
    else {
        // cout << "\t-- NULL --" << endl;
        return '\0';
    }
}

int getElemFreq(char arr[], int low, int high, char element, int arrSize) {
    int count = 0;
    for (int i = low; i <= high; i++) {
        if (arr[i] == element) {
            count++;
        }
    }
    // cout << "\t\tFreq count: " << low << ", " << high << ", element: " << element << " x " << count << endl;
    return count;
}