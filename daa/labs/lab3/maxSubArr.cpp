#include <bits/stdc++.h>
#include <climits>
using namespace std;
int maxSubArr(int *arr, int low, int high);
int maxCrossArr(int *arr, int low, int mid, int high);

int main(void) {
    int arr[] = {-2, 10, -4, 12, -9};

    cout << maxSubArr(arr, 0, sizeof(arr)/sizeof(arr[0])) << endl;
    return 0;
}

int maxSubArr(int *arr, int low, int high) {
    if (low < high) {
        int mid = (low + high) / 2;
        cout << "1111\t" << maxSubArr(arr,low, mid) << " -- " << maxSubArr(arr, mid + 1, high) << " -- " << maxCrossArr(arr, low, mid, high) << endl;
        // return max(maxSubArr(arr,low, mid), maxSubArr(arr, mid + 1, high));
        return max(max(maxSubArr(arr,low, mid), maxSubArr(arr, mid + 1, high)), maxCrossArr(arr, low, mid, high));
    }
    else
        return 1;
}

int maxCrossArr(int *arr, int low, int mid, int high) {
    int sum = 0;
    int leftSum = INT_MIN;
    for (int i = mid; i >= low; i--) {
        sum = sum + arr[i];
        if (sum > leftSum) {
            leftSum = sum;
        }

        cout << "2222\t" << leftSum << endl;
    }

    sum = 0;
    int rightSum = INT_MIN;
    for (int i = mid+1; i < high; i++) {
        sum = sum + arr[i];
        if (sum > leftSum) {
            rightSum = sum;
        }
    }

    return leftSum + rightSum;
}