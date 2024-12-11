#include <bits/stdc++.h>


int largestElement(vector<int> &arr, int n) {
  sort(arr.begin(), arr.end());
  for(int i = n - 1; i >= 0; i--){
    return arr[i];
  }
}

int secondlargest(vector<int>a, int n){
    int largest = a[0];
    int slargest = -1;
    for (int i = 0; i<n; i++){
        if(a[i]>largest){
            slargest = largest;
            largest = a[i];
        }

        else if(a[i]<largest && slargest<a[i]){
            slargest = a[i];
        }
    }
    return slargest;
}

int secondsmallest(vector<int>a, int n){
    int smallest = a[0];
    int ssmallest = INT_MAX;
    for (int i = 0; i<n; i++){
        if(a[i]<smallest){
            ssmallest = smallest;
            smallest  = a[i];
        }
        else if(a[i]>smallest && ssmallest>a[i]){
            ssmallest = a[i];
        }
    };
    return ssmallest;
}

vector<int> getSecondOrderElements(int n, vector<int> a) {
    int slargest = secondlargest(a, n);
    int ssmallest = secondsmallest(a, n);
    return {slargest, ssmallest};
}



