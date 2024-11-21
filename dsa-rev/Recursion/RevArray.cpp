#include<iostream>
using namespace std;

void reverseArray(int arr[], int i, int j){
    if(i >= j) return;

    int temp = arr[i];
    arr[i] = arr[j];
    arr[j] = temp;

    reverseArray(arr, i+1, j-1);
}

void printArray(int arr[], int size) {
    for (int i = 0; i < size; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
}

int main(){
    int n;
    cout << "Enter the size of array : ";
    cin >> n;
    int arr[n];
    for(int i = 0; i < n; i++){
        int x;
        cin >> x;
        arr[i] = x;
    }
    cout << "Original array is : ";
    printArray(arr, n);
    reverseArray(arr, 0, n-1);
    cout << "Reversed array is : ";
    printArray(arr, n);
    return 0;
}