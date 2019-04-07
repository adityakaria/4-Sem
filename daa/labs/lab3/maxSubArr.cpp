#include <bits/stdc++.h>
#include <climits>
using namespace std;
int maxSubArr(int *arr, int low, int high);
int maxCrossArr(int *arr, int low, int mid, int high);

int main(void) {
    int arr[] = {2, 9, -9, 10, -9};

    cout << maxSubArr(arr, 0, sizeof(arr)/sizeof(arr[0])-1) << endl;
    return 0;
}

int max(int a, int b) {
    if (a >= b) {
        return a;
    }
    else {
        return b;
    }
}

int maxSubArr(int *arr, int low, int high) {
    if (low < high) {
        int mid = (low + high) / 2;
        int x = maxSubArr(arr,low, mid); cout << endl;
        int y = maxSubArr(arr, mid + 1, high); cout << endl;
        int z = maxCrossArr(arr, low, mid, high); cout << endl;
        cout << "-->" << "\t" << x << "\t" << y << "\t" << z << endl;
        // return max(maxSubArr(arr,low, mid), maxSubArr(arr, mid + 1, high));
        cout << "==" << max(max(x, y), z) << endl;
        return max(max(x, y), z);
    }
    else if (low == high) {
        return arr[low];
    }
    else {
        return 0;
    }
}

int maxCrossArr(int *arr, int low, int mid, int high) {
    cout << "[";
    int i = 0;
    int sum = 0;
    int leftSum = INT_MIN;
    for (i = mid; i >= low; i--) {
        sum = sum + arr[i];
        if (sum > leftSum) {
            leftSum = sum;
        }
    }
    cout << leftSum << "...";

    sum = 0;
    i = 0;
    int rightSum = INT_MIN;
    for (i = mid+1; i <= high; i++) {
        // cout << "==" << arr[i] << endl;
        sum = sum + arr[i];
        if (sum > rightSum) {
            rightSum = sum;
        }
    }
    cout << rightSum << "]" << "\t";

    return leftSum + rightSum;
}