/*
Problem 2: Move all zeroes to the end of an array.
Statement: Given an array of random numbers, push all zeroes to the end 
           while maintaining the relative order of the non-zero elements.

Approach : Apply Merge Sort manually and then push all 0s to the end.The input should be positive numbers

Input(Input should be positive numbers only):4 0 1 3 0 5
Output:1 3 4 5 0 0




*/

#include <iostream>
#include <vector>
using namespace std;


void merge(vector<int>& arr, int left, int mid, int right) {
    vector<int> temp;
    int i = left, j = mid + 1;

    while (i <= mid && j <= right) {
        if (arr[i] <= arr[j]) {
            temp.push_back(arr[i++]);
        } else {
            temp.push_back(arr[j++]);
        }
    }

    while (i <= mid) temp.push_back(arr[i++]);
    while (j <= right) temp.push_back(arr[j++]);

    for (int k = 0; k < temp.size(); ++k)
        arr[left + k] = temp[k];
}


void mergeSort(vector<int>& arr, int left, int right) {
    if (left >= right) return;

    int mid = (left + right) / 2;
    mergeSort(arr, left, mid);
    mergeSort(arr, mid + 1, right);
    merge(arr, left, mid, right);
}


void mergeSortZeroPush(vector<int>& arr) {
    mergeSort(arr, 0, arr.size() - 1);


    vector<int> result;
    for (int x : arr)
        if (x != 0)
            result.push_back(x);
    for (int x : arr)
        if (x == 0)
            result.push_back(x);

    arr = result;
}

void printArray(const vector<int>& arr) {
    for (int x : arr)
        cout << x << " ";
    cout << endl;
}

int main() {
    int n;
    cout << "Enter size of array: ";
    cin >> n;
    vector<int> arr(n);
    cout << "Enter elements: ";
    for (int i = 0; i < n; ++i) cin >> arr[i];

    vector<int> arr1 = arr;

    mergeSortZeroPush(arr1);
    

    cout << "Zero Push to : "; printArray(arr1);
   

    return 0;
}