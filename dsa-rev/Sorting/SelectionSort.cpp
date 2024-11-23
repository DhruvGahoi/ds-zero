#include<iostream>
using namespace std;

void selectionSort(int arr[], int size) {
    for (int i = 0; i < size - 1; i++) {
        int smallest = i;
        for (int j = i + 1; j < size; j++) {
            if (arr[smallest] > arr[j]) {
                smallest = j;
            }
        }
        int temp = arr[i];
        arr[i] = arr[smallest];
        arr[smallest] = temp;
    }
}

int main() {
    int nums[] = {64, 25, 12, 22, 11};
    int size = sizeof(nums) / sizeof(nums[0]);

    selectionSort(nums, size);

    for (int i = 0; i < size; i++) {
        cout << nums[i] << " ";
    }
    return 0;
}
