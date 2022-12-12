/*
 Time Complexity = O(N)
 Space Complexity = O(1)
 */
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
    void reorderList(ListNode* head) {
        if (head == NULL || head->next == NULL) {
            return;
        }
        ListNode* slow = head;
        ListNode* fast = head;
        
        //SubProblem 1 Find the mid
        
        while (fast->next != NULL && fast->next->next != NULL) { // for odd and even Linked list resp
            slow = slow->next;
            fast = fast->next->next;
        }
        
        //SubProblem 2 Reverse the second half of LL
        
        //Reverse LL function call
        fast = reverse(slow->next); 
        
        slow->next = NULL; //Remove the connection and make two Lists
        slow = head;
        
        //SubProblem 3 Merge the 2 Lists in desired order
        
        ListNode* temp = NULL;
        
        while (fast != NULL) {
            temp = slow->next;
            slow->next = fast;
            fast = fast->next;
            slow->next->next = temp;
            slow = temp;
        }
    }
    
    ListNode* reverse (ListNode* head) {
        ListNode* prev = NULL;
        ListNode* curr = head;
        ListNode* fast = head->next;
        while (fast != NULL) {
            curr->next = prev;
            prev = curr;
            curr = fast;
            fast = fast->next;
        }
        curr->next = prev; //For the last element
        return curr;
    }
};