#include<bits/stdc++.h>
using namespace std;

struct Node {
    // By default mem and data func are public 
    int data;
    Node* next;

    // Node(int val){
    //    data = val;
    //   next = nullptr;
    //}

    Node(int val, Node* nextNode = nullptr){
        data = val;
        next = nextNode;
    }
};

Node* convertArrToLL(vector<int>& arr){
    Node* head = new Node(arr[0]);
    Node* mover = head;
    for(int i = 1; i < arr.size(); i++){
        Node* temp = new Node(arr[i]);
        mover -> next = temp;
        mover = temp;
    }
    return head;
}

int lengthOfLL(Node* head){
    int count = 0;
    while(head){
        count++;
        head = head -> next;
    }
    return count;
}

bool checkIfPresent(Node* head, int key){
    Node* temp = head;
    while(temp){
        if(temp->data == key){
            return true;
        }
        temp = temp -> next;
    }
    return false;
}

void print(Node* head){
    Node* temp = head;
    while(temp){
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << "\n";
}

Node* deleteHead(Node* head){
    if(head == NULL) return head;
    Node* temp = head;
    head = head -> next;
    delete temp;
    return head;
}

Node* deleteTail(Node* head){
    if(head == NULL || head -> next == NULL) return NULL;
    Node* temp = head;
    while(temp->next->next != NULL){
        temp = temp -> next;
    }
    delete temp -> next;
    temp -> next = NULL;

    return head;
}

Node* deleteK(Node* head, int k){
    if(head == NULL) return NULL;
    if(k == 1){
        Node* temp = head;
        head = head -> next;
        delete temp;
        return head;
    }

    int count = 0;
    Node* temp = head;
    Node* prev = NULL;
    while(temp != NULL){
        count++;
        if(count == k){
            prev -> next = prev -> next -> next;
            delete temp; // free(temp);
            break;
        }
        prev = temp;
        temp = temp -> next;
    }

    return head;
}

Node* removeEl(Node* head, int el){
    if(head == NULL) return NULL;
    if(head -> data == el){
        Node* temp = head;
        head = head -> next;
        delete temp;
        return head;
    }
    Node* temp = head;
    Node* prev = NULL;
    while(temp != NULL){
        if(temp -> data == el){
            prev -> next = prev -> next -> next;
            delete temp;
            break;
        }
        prev = temp;
        temp = temp -> next;
    }
    return head;
}

Node* insertHead(Node* head, int val){
    return new Node(val, head);
}

Node* insertTail(Node* head, int val){
    if(head == NULL) return new Node(val);
    Node* temp = head;
    while(temp->next != NULL){
        temp = temp -> next;
    }
    Node* newNode = new Node(val);
    temp -> next = newNode;
    return head;
}

Node* insertAtK(Node* head, int el, int k){
    if(head == NULL) {
        if(k == 1){
            return new Node(el);
        } else {
            return head;
        }
    }
    if(k == 1){
        return new Node(el, head);
    }
    int cnt = 0;
    Node* temp = head;
    while(temp != NULL){
        cnt++;
        if(cnt == k - 1){
            Node* x = new Node(el, temp->next);
            temp->next = x;
            break;
        }
        temp = temp -> next;
    }
    return head;
}

int main(){
    vector<int> arr = {2, 3, 5, 8, 9};
    Node* y = new Node(arr[0]);
    cout << y->data << "\n";
    
    // Conversion from array to LL
    Node* head = convertArrToLL(arr);

    // Traversing in LL
    cout << "Linked List: ";
    print(head);

    cout << "Length of LL: " << lengthOfLL(head) << "\n";
    
    int key = 6;
    if(checkIfPresent(head, key))
        cout << key << " is present." << "\n";
    else cout << key << "is not present." << "\n"; 

    head = deleteHead(head);
    cout << "After deleting head: ";
    print(head);
    
    head = deleteTail(head);
    cout << "After deleting tail: ";
    print(head);

    int k = 7; // this is a 1 based indexing.
    head = deleteK(head, k);
    cout << "After deleting " << k << "th element: ";
    print(head);

    head = removeEl(head, 5);
    cout << "After deleting the element: ";
    print(head);

    head = insertHead(head, 1);
    cout << "After inserting at head: ";
    print(head);

    head = insertTail(head, 9);
    cout << "After inserting at tail: ";
    print(head);
    
    int pos = 3;
    head = insertAtK(head, 6, pos);
    cout << "After inserting at " << pos << "rd position: ";
    print(head);
}
