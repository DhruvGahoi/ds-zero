#include<bits/stdc++.h>
using namespace std;

void insertionSort(int nums[], int size){
    for(int i = 0; i < size; i++){
        int j = i;
        while(j > 0 && nums[j-1] > nums[j]){
            swap(nums[j-1], nums[j]);
            j--;
        }
    }
}

int main(){
    int nums[] = {63, 42, 3, 12, 1, 98, 33};
    int size = sizeof(nums) / sizeof(nums[0]); 

    insertionSort(nums, size);

    for(int i = 0; i < size; i++) {
        cout << nums[i] << " ";
    }

    return 0;
}