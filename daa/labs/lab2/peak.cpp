#include <bits/stdc++.h>
using namespace std;

void findPeak(vector<int> array, int begin, int end);

int main(void) {
    int i, j;
    // vector<int> array;
    int arr[] = {2, 3, 5, 7, 36, 43, 9, 1, 0, -4, -11}; 
    int n = sizeof(arr) / sizeof(arr[0]); 
    vector<int> array(arr, arr + n); 
    // for (int x = 0; x < n; x++) {
    //     array.push_back(arr[x]);
    //     cout << arr[x] << " ";
    // }
    for (int x = 0; x < array.size(); x++) 
        cout << array[x] << " "; 
    cout << endl;
    // vector<int> *array = array{ 2, 3, 5, 7, 36, 43, 9, 1, 0, -4, -11 };
    findPeak(array, 0, array.size());

}

void findPeak(vector<int> array, int begin, int end) {
    cout << "\t1" << endl;
    int middle = (begin + end) / 2;
    if (array[middle - 1] < array[middle]) {
        findPeak(array, middle, end);
    }
    else if (array[middle -1] > array[middle]) {
        findPeak(array, begin, middle -1);
    }
}