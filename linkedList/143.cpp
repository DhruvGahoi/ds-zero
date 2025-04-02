/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* findMiddle(ListNode* head){
        ListNode* slow = head, *fast = head;
        while(fast && fast -> next){
            slow = slow -> next;
            fast = fast -> next -> next;
        }
        return slow;
    }

    ListNode* reverse(ListNode* head){
        ListNode* prev = NULL, *curr = head, *next = NULL;
        while(curr){
            next = curr -> next;
            curr -> next = prev;
            prev = curr;
            curr = next;
        }
        return prev;
    }

    void merge(ListNode* first, ListNode* second){
        while(second){
            ListNode* temp1 = first -> next;
            ListNode* temp2 = second -> next;
            
            first -> next = second;
            second -> next = temp1;

            first = temp1;
            second = temp2;
        }
    }

    void reorderList(ListNode* head) {
        if (!head || !head->next || !head->next->next) return;

        ListNode* mid = findMiddle(head);
        ListNode* secondHalf = mid->next;

        mid->next = NULL; // brwaks the list into 2 halves
        
        secondHalf = reverse(secondHalf);
        merge(head, secondHalf);
    }
};
