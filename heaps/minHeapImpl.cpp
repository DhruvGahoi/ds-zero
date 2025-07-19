#include<bits/stdc++.h>
using namespace std;

class minHeap {
    vector<int> nums;

    void heapifyDown(int i){
        int n = nums.size();
        while(1){
            int left = 2 * i + 1;
            int right = 2 * i + 2;
            int smallest = i;
            if(left < n && nums[left] < nums[smallest]){
                smallest = left;
            } else if(right < n && nums[right] < nums[smallest]){
                smallest = right;
            }

            if(smallest != i){
                swap(nums[i], nums[smallest]);
                i = smallest;
            } else {
                break;
            }
        }
    }
    
  public:
    void heapifyUp(int i){
        while(i > 0){
            int parent = (i - 1) / 2;
            if(nums[parent] > nums[i]){
                swap(nums[parent], nums[i]);
                i = parent;
            } else {
                break;
            }
        }
    }

    void insert(int val){
        nums.push_back(val);
        heapifyUp(nums.size() - 1);
    }

    int exctractMin(){
        int n = nums.size();
        if(n == 0) return -1;
        int root = nums[0];
        swap(nums[0], nums[n - 1]);
        nums.pop_back();
        heapifyDown(0);
        return root;
    }

    void print(){
        for(int num : nums){
            cout << num << " ";
        }
        cout << endl;
    }


};

int main() {
    minHeap h;
    h.insert(10);
    h.insert(4);
    h.insert(15);
    h.insert(20);
    h.insert(0);
    h.insert(8);

    cout << "Heap after insertions: ";
    h.print();

    cout << "Extracting elements in order:\n";
    while (true) {
        int minVal = h.exctractMin();
        if (minVal == -1) break;
        cout << minVal << " ";
    }
    cout << endl;

    return 0;
}

