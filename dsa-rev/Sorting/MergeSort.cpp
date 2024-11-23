#include <iostream>
using namespace std;

void merge(int arr[], int low, int high) {
    int mid = low + (high - low) / 2;
    int z = high - low + 1;
    int temp[z];
    int i = low;
    int j = mid + 1;
    int k = 0;

    while (i <= mid && j <= high) {
        if (arr[i] <= arr[j]) {
            temp[k++] = arr[i++];
        } else {
            temp[k++] = arr[j++];
        }
    }

    while (i <= mid) {
        temp[k++] = arr[i++];
    }

    while (j <= high) {
        temp[k++] = arr[j++];
    }

    for (int m = 0, n = low; m < z; m++, n++) {
        arr[n] = temp[m];
    }
}

void mergeSort(int arr[], int low, int high) {
    if (low >= high) return;
    int mid = low + (high - low) / 2;

    mergeSort(arr, low, mid);
    mergeSort(arr, mid + 1, high);

    merge(arr, low, high);
}

int main() {
    int nums[] = {63, 42, 3, 12, 1, 98, 33};
    int size = sizeof(nums) / sizeof(nums[0]);

    mergeSort(nums, 0, size - 1);

    for (int i = 0; i < size; i++) {
        cout << nums[i] << " ";
    }

    return 0;
}
