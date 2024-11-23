#include<iostream>
using namespace std;

void bubbleSort(int arr[], int size){
    for(int i = 0; i <= size - 1; i++){
        for(int j = 0; j < size - i - 1; j++){
            if(arr[j] > arr[j + 1]){
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
}

int main(){
    int nums[] = {3, 2, 4, 1, 5};
    int size = sizeof(nums) / sizeof(nums[0]);
    bubbleSort(nums, size);
    
    for (int i = 0; i < size; i++) {
        cout << nums[i] << " ";
    }

    return 0;
}