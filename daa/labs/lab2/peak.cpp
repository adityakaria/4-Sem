#include <bits/stdc++.h>
using namespace std;

void findPeak(vector<int> array, int begin, int end);

int main(void) {
    int i, j;
    // vector<int> array;
    // int arr[] = {2, 3, 5, 99, 36, 9, 1, 0, -4, -11}; 
    int arr[] = {10, 12, 8, 4 , -3, -15};
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
    findPeak(array, 0, array.size() - 1);

}

void findPeak(vector<int> array, int begin, int end) {
    if (begin + 1 < end) {
        cout << "\t1\t" << begin << " - " << end << endl;
        int middle = ((begin + end) / 2);

        cout << "\t2\t" << middle << endl;
        // if (end != 10)
        // exit(1);
        if (array[middle - 1] < array[middle]) {
            cout << "\t3A" << endl;
            findPeak(array, middle, end);
        }
        else if (array[middle -1] > array[middle]) {
            cout << "\t3B" << endl;
            findPeak(array, begin, middle);
        }
    }
    else {
        cout << "END: " << begin << " -- " << end << endl;
        array[begin] > array[end] ? cout << array[begin] : cout << array[end];
        cout << endl;
    }
}